use std::io::{self ,Read, Write };
use std::cmp::Ordering;


/*
convex hull

x,y 좌표

관찰

가장 왼쪽 점은 반드시 포함된다.
좌표계를 모두 바꾸면? rtheta로 바꿀 수 있지 않을까?
theta로 정렬하면? 
                                                                                                                                                                                                                                                                                                            
좌표계는 

*/



#[derive(Clone, Copy, Debug, Eq, PartialEq)]
struct Point {
    x: i64,
    y: i64,
}

// (b-a) x (c-a)
fn cross(a: Point, b: Point, c: Point) -> i64 {
    (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x)
}

fn convex_hull_size(mut pts: Vec<Point>) -> usize {
    if pts.len() <= 1 {
        return pts.len();
    }

    // 1) 정렬 (x, y)
    pts.sort_by(|p, q| {
        if p.x == q.x {
            p.y.cmp(&q.y)
        } else {
            p.x.cmp(&q.x)
        }
    });

    // 2) 중복 제거
    pts.dedup();
    if pts.len() <= 1 {
        return pts.len();
    }
    if pts.len() == 2 {
        // 두 점이 서로 다르면 껍질은 2
        return 2;
    }

    // 3) Monotone chain
    // "strict hull" (변 위 점 제거) -> cross <= 0 이면 pop
    let mut lower: Vec<Point> = Vec::with_capacity(pts.len());
    for &p in &pts {
        while lower.len() >= 2 {
            let l = lower.len();
            if cross(lower[l - 2], lower[l - 1], p) <= 0 {
                lower.pop();
            } else {
                break;
            }
        }
        lower.push(p);
    }

    let mut upper: Vec<Point> = Vec::with_capacity(pts.len());
    for &p in pts.iter().rev() {
        while upper.len() >= 2 {
            let l = upper.len();
            if cross(upper[l - 2], upper[l - 1], p) <= 0 {
                upper.pop();
            } else {
                break;
            }
        }
        upper.push(p);
    }

    // 마지막 점은 시작점과 중복되므로 각각 하나씩 제거 후 합침
    lower.pop();
    upper.pop();

    let hull_size = lower.len() + upper.len();
    // 모든 점이 일직선이면 위 로직에서 양끝만 남아서 hull_size=2가 됨(요구와 일치)
    hull_size
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let n: usize = match it.next() {
        Some(v) => v.parse().unwrap(),
        None => return,
    };

    let mut pts = Vec::with_capacity(n);
    for _ in 0..n {
        let x: i64 = it.next().unwrap().parse().unwrap();
        let y: i64 = it.next().unwrap().parse().unwrap();
        pts.push(Point { x, y });
    }

    let ans = convex_hull_size(pts);
    println!("{}", ans);
}

