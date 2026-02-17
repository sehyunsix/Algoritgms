use std::io::{self, Read};

#[derive(Clone, Copy)]
struct Edge {
    to: usize,
    w: i32,
}

fn main() {
    // ----- Fast input -----
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let n: usize = match it.next() {
        Some(v) => v.parse().unwrap(),
        None => return,
    };

    let mut g: Vec<Vec<Edge>> = vec![Vec::new(); n + 1];
    for _ in 0..(n - 1) {
        let a: usize = it.next().unwrap().parse().unwrap();
        let b: usize = it.next().unwrap().parse().unwrap();
        let w: i32 = it.next().unwrap().parse().unwrap();
        g[a].push(Edge { to: b, w });
        g[b].push(Edge { to: a, w });
    }

    let q: usize = it.next().unwrap().parse().unwrap();

    // ----- Prepare LCA (binary lifting) -----
    let mut log = 1usize;
    while (1usize << log) <= n {
        log += 1;
    }

    let mut parent = vec![vec![0usize; n + 1]; log];
    let mut min_w = vec![vec![i32::MAX; n + 1]; log];
    let mut max_w = vec![vec![i32::MIN; n + 1]; log];
    let mut depth = vec![0usize; n + 1];

    // BFS/stack from root=1 to set depth and 2^0 parent, min/max
    let root = 1usize;
    let mut stack: Vec<(usize, usize, i32)> = Vec::with_capacity(n);
    // (node, par, edge_weight_from_par)
    stack.push((root, 0, 0));

    let mut visited = vec![false; n + 1];
    visited[root] = true;
    depth[root] = 0;
    parent[0][root] = 0;
    min_w[0][root] = i32::MAX; // root has no incoming edge
    max_w[0][root] = i32::MIN;

    while let Some((u, p, w)) = stack.pop() {
        parent[0][u] = p;
        if p != 0 {
            min_w[0][u] = w;
            max_w[0][u] = w;
            depth[u] = depth[p] + 1;
        }

        for &e in &g[u] {
            if !visited[e.to] {
                visited[e.to] = true;
                stack.push((e.to, u, e.w));
            }
        }
    }

    // Build sparse tables
    for k in 1..log {
        for v in 1..=n {
            let mid = parent[k - 1][v];
            parent[k][v] = parent[k - 1][mid];
            min_w[k][v] = min_w[k - 1][v].min(min_w[k - 1][mid]);
            max_w[k][v] = max_w[k - 1][v].max(max_w[k - 1][mid]);
        }
    }

    // ----- Query function -----
    let mut out = String::new();

    for _ in 0..q {
        let mut u: usize = it.next().unwrap().parse().unwrap();
        let mut v: usize = it.next().unwrap().parse().unwrap();

        let mut mn = i32::MAX;
        let mut mx = i32::MIN;

        // 1) make depths equal
        if depth[u] < depth[v] {
            std::mem::swap(&mut u, &mut v);
        }
        let mut diff = depth[u] - depth[v];
        for k in 0..log {
            if (diff & (1usize << k)) != 0 {
                mn = mn.min(min_w[k][u]);
                mx = mx.max(max_w[k][u]);
                u = parent[k][u];
            }
        }

        // if already same
        if u == v {
            out.push_str(&format!("{} {}\n", mn, mx));
            continue;
        }

        // 2) lift both up
        for k in (0..log).rev() {
            if parent[k][u] != parent[k][v] {
                mn = mn.min(min_w[k][u]).min(min_w[k][v]);
                mx = mx.max(max_w[k][u]).max(max_w[k][v]);
                u = parent[k][u];
                v = parent[k][v];
            }
        }

        // 3) one step to LCA
        mn = mn.min(min_w[0][u]).min(min_w[0][v]);
        mx = mx.max(max_w[0][u]).max(max_w[0][v]);

        out.push_str(&format!("{} {}\n", mn, mx));
    }

    print!("{}", out);
}