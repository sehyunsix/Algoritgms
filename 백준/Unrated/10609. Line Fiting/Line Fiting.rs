use std::io::{self, Read};

#[derive(Clone)]
struct Dist {
    y: Vec<f64>, // sorted
    w: Vec<f64>, // probabilities in [0,1], sum=1
}

fn slope(p: (f64, f64), q: (f64, f64)) -> f64 {
    (q.1 - p.1) / (q.0 - p.0)
}

// Maintain lower hull for points (x, y) with increasing x.
// We want convex hull where slopes between consecutive points are strictly increasing.
fn push_lower(h: &mut Vec<(f64, f64)>, p: (f64, f64)) {
    while h.len() >= 2 {
        let a = h[h.len() - 2];
        let b = h[h.len() - 1];
        // If slope(a,b) >= slope(b,p), b is unnecessary for lower hull
        if slope(a, b) >= slope(b, p) {
            h.pop();
        } else {
            break;
        }
    }
    h.push(p);
}

// Maintain upper hull for points (x, y) with increasing x.
// Slopes between consecutive points are strictly decreasing.
fn push_upper(h: &mut Vec<(f64, f64)>, p: (f64, f64)) {
    while h.len() >= 2 {
        let a = h[h.len() - 2];
        let b = h[h.len() - 1];
        // If slope(a,b) <= slope(b,p), b is unnecessary for upper hull
        if slope(a, b) <= slope(b, p) {
            h.pop();
        } else {
            break;
        }
    }
    h.push(p);
}

// Query maximum slope from a lower hull point to query point q, with monotone pointer.
fn query_max_slope(h: &Vec<(f64, f64)>, ptr: &mut usize, q: (f64, f64)) -> f64 {
    while *ptr + 1 < h.len() {
        let s1 = slope(h[*ptr], q);
        let s2 = slope(h[*ptr + 1], q);
        if s2 >= s1 {
            *ptr += 1;
        } else {
            break;
        }
    }
    slope(h[*ptr], q)
}

// Query minimum slope from an upper hull point to query point q, with monotone pointer.
fn query_min_slope(h: &Vec<(f64, f64)>, ptr: &mut usize, q: (f64, f64)) -> f64 {
    while *ptr + 1 < h.len() {
        let s1 = slope(h[*ptr], q);
        let s2 = slope(h[*ptr + 1], q);
        if s2 <= s1 {
            *ptr += 1;
        } else {
            break;
        }
    }
    slope(h[*ptr], q)
}

// Compute interval [L, R] such that E[|Y - t|] <= err for discrete distribution.
// Returns None if impossible (err < minimum).
fn interval_for_err(dist: &Dist, err: f64) -> Option<(f64, f64)> {
    let m = dist.y.len();
    let y = &dist.y;
    let w = &dist.w;

    // prefix sums
    let mut pw = vec![0.0; m + 1];
    let mut pys = vec![0.0; m + 1];
    for i in 0..m {
        pw[i + 1] = pw[i] + w[i];
        pys[i + 1] = pys[i] + w[i] * y[i];
    }
    let total_sy = pys[m];

    // g at each breakpoint y[k]
    let mut g_at = vec![0.0; m];
    for k in 0..m {
        let wl = pw[k + 1];
        let sl = pys[k + 1];
        let wr = 1.0 - wl;
        let sr = total_sy - sl;
        g_at[k] = y[k] * wl - sl + sr - y[k] * wr;
    }

    // minimal g occurs at weighted median (first prefix >= 0.5)
    let mut med = 0usize;
    while med < m && pw[med + 1] < 0.5 {
        med += 1;
    }
    let min_g = g_at[med]; // enough for our purposes
    if err + 1e-12 < min_g {
        return None;
    }

    // Find left root: smallest t with g(t) <= err
    let mut left = y[0] - (err - g_at[0]); // segment (-inf, y0] slope -1
    if err + 1e-12 < g_at[0] {
        // scan right from y0
        let mut found = false;
        for k in 0..m - 1 {
            let t0 = y[k];
            let g0 = g_at[k];
            let s = 2.0 * pw[k + 1] - 1.0; // slope on (y[k], y[k+1])
            let t1 = y[k + 1];
            // g at t1 (continuous) is g_at[k+1]
            let g1 = g_at[k + 1];

            if g0 <= err + 1e-12 {
                left = t0;
                found = true;
                break;
            }
            if s < -1e-15 && g1 <= err + 1e-12 {
                // cross within (t0, t1)
                left = t0 + (err - g0) / s; // s negative
                found = true;
                break;
            }
            // else continue
        }
        if !found {
            // If not found in middle, must be on right tail (shouldn't happen if err >= min_g)
            // But handle safely:
            // Find first k with g_at[k] <= err and set left=y[k]
            for k in 0..m {
                if g_at[k] <= err + 1e-12 {
                    left = y[k];
                    found = true;
                    break;
                }
            }
            if !found {
                return None;
            }
        }
    }

    // Find right root: largest t with g(t) <= err
    let mut right = y[m - 1] + (err - g_at[m - 1]); // segment [y_last, +inf) slope +1
    if err + 1e-12 < g_at[m - 1] {
        // scan left from y_last
        let mut found = false;
        for k in (1..m).rev() {
            let t1 = y[k];
            let g1 = g_at[k];
            let s = 2.0 * pw[k] - 1.0; // slope on (y[k-1], y[k])
            let t0 = y[k - 1];
            let g0 = g_at[k - 1];

            if g1 <= err + 1e-12 {
                right = t1;
                found = true;
                break;
            }
            if s > 1e-15 && g0 <= err + 1e-12 {
                // cross within (t0, t1)
                right = t1 + (err - g1) / s; // (err-g1)<0, s>0 => move left
                found = true;
                break;
            }
        }
        if !found {
            for k in (0..m).rev() {
                if g_at[k] <= err + 1e-12 {
                    right = y[k];
                    found = true;
                    break;
                }
            }
            if !found {
                return None;
            }
        }
    }

    if left > right + 1e-9 {
        return None;
    }
    Some((left, right))
}

// Check feasibility: exists a,b s.t. for all i: a*x_i + b in [L_i, R_i]
fn feasible(xs: &Vec<f64>, dists: &Vec<Dist>, err: f64) -> bool {
    let n = xs.len();
    let mut l = vec![0.0; n];
    let mut r = vec![0.0; n];

    for i in 0..n {
        if let Some((li, ri)) = interval_for_err(&dists[i], err) {
            l[i] = li;
            r[i] = ri;
        } else {
            return false;
        }
    }

    // slope bounds: for all i<j
    // a >= (L_j - R_i)/(x_j - x_i)  => max_lower
    // a <= (R_j - L_i)/(x_j - x_i)  => min_upper
    let mut max_lower = f64::NEG_INFINITY;
    let mut min_upper = f64::INFINITY;

    // Build hulls incrementally
    let mut low_hull: Vec<(f64, f64)> = Vec::new();  // points (x, R)
    let mut up_hull: Vec<(f64, f64)> = Vec::new();   // points (x, L)
    push_lower(&mut low_hull, (xs[0], r[0]));
    push_upper(&mut up_hull, (xs[0], l[0]));

    let mut ptr_low = 0usize;
    let mut ptr_up = 0usize;

    for j in 1..n {
        let q_lower = (xs[j], l[j]);
        let q_upper = (xs[j], r[j]);

        // update bounds
        let lb = query_max_slope(&low_hull, &mut ptr_low, q_lower);
        if lb > max_lower {
            max_lower = lb;
        }
        let ub = query_min_slope(&up_hull, &mut ptr_up, q_upper);
        if ub < min_upper {
            min_upper = ub;
        }

        // add current points into hulls
        push_lower(&mut low_hull, (xs[j], r[j]));
        push_upper(&mut up_hull, (xs[j], l[j]));

        // pointers should never exceed len-1
        if ptr_low >= low_hull.len() {
            ptr_low = low_hull.len() - 1;
        }
        if ptr_up >= up_hull.len() {
            ptr_up = up_hull.len() - 1;
        }
    }

    max_lower <= min_upper + 1e-9
}

fn solve_case(xs: Vec<f64>, dists: Vec<Dist>) -> f64 {
    // Binary search minimal err
    let mut lo = 0.0f64;
    let mut hi = 1.0f64;

    while !feasible(&xs, &dists, hi) {
        hi *= 2.0;
        if hi > 1e12 {
            break;
        }
    }

    for _ in 0..70 {
        let mid = (lo + hi) * 0.5;
        if feasible(&xs, &dists, mid) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    hi
}

fn main() {
    // Read all input as tokens
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let mut outputs: Vec<String> = Vec::new();

    loop {
        let n_opt = it.next();
        if n_opt.is_none() {
            break;
        }
        let n: usize = n_opt.unwrap().parse().unwrap();
        if n == 0 {
            break;
        }

        let mut xs: Vec<f64> = Vec::with_capacity(n);
        let mut dists: Vec<Dist> = Vec::with_capacity(n);

        for _ in 0..n {
            let xi: u64 = it.next().unwrap().parse().unwrap();
            let mi: usize = it.next().unwrap().parse().unwrap();

            let mut yv: Vec<f64> = Vec::with_capacity(mi);
            for _ in 0..mi {
                let yy: u64 = it.next().unwrap().parse().unwrap();
                yv.push(yy as f64);
            }
            let mut pv: Vec<f64> = Vec::with_capacity(mi);
            for _ in 0..mi {
                let pp: u64 = it.next().unwrap().parse().unwrap();
                pv.push(pp as f64 / 100.0);
            }

            // sort by y
            let mut pairs: Vec<(f64, f64)> = yv.into_iter().zip(pv.into_iter()).collect();
            pairs.sort_by(|a, b| a.0.partial_cmp(&b.0).unwrap());

            let (mut y, mut w) = (Vec::with_capacity(mi), Vec::with_capacity(mi));
            for (yy, ww) in pairs {
                y.push(yy);
                w.push(ww);
            }

            xs.push(xi as f64);
            dists.push(Dist { y, w });
        }

        let ans = solve_case(xs, dists);

        // round to exactly 1 digit after decimal
        let rounded = (ans * 10.0).round() / 10.0;
        outputs.push(format!("{:.1}", rounded));
    }

    print!("{}", outputs.join("\n"));
}