use std::collections::VecDeque;
use std::io::{self, Read};

fn main() {
    // Input
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let n: usize = it.next().unwrap().parse().unwrap();
    let m: usize = it.next().unwrap().parse().unwrap();

    let mut graph = vec![Vec::<(usize, i64)>::new(); n + 1];
    let mut rev_graph = vec![Vec::<(usize, i64)>::new(); n + 1];
    let mut indegree = vec![0usize; n + 1];

    for _ in 0..m {
        let u: usize = it.next().unwrap().parse().unwrap();
        let v: usize = it.next().unwrap().parse().unwrap();
        let w: i64 = it.next().unwrap().parse().unwrap();

        graph[u].push((v, w));
        rev_graph[v].push((u, w));
        indegree[v] += 1;
    }

    let start: usize = it.next().unwrap().parse().unwrap();
    let end: usize = it.next().unwrap().parse().unwrap();

    // 1) Topological DP for longest path
    let mut dist = vec![0i64; n + 1];
    let mut q = VecDeque::new();

    // Since the problem guarantees:
    // - every city is reachable from start
    // - every city can reach end
    // and the whole graph is a DAG,
    // starting topo from `start` works with indegree reduction.
    q.push_back(start);

    while let Some(cur) = q.pop_front() {
        for &(next, w) in &graph[cur] {
            if dist[next] < dist[cur] + w {
                dist[next] = dist[cur] + w;
            }

            indegree[next] -= 1;
            if indegree[next] == 0 {
                q.push_back(next);
            }
        }
    }

    // 2) Reverse traversal to count all edges on any longest path
    let mut visited = vec![false; n + 1];
    let mut rq = VecDeque::new();
    rq.push_back(end);
    visited[end] = true;

    let mut critical_edges = 0usize;

    while let Some(cur) = rq.pop_front() {
        for &(prev, w) in &rev_graph[cur] {
            if dist[prev] + w == dist[cur] {
                critical_edges += 1;

                if !visited[prev] {
                    visited[prev] = true;
                    rq.push_back(prev);
                }
            }
        }
    }

    println!("{}", dist[end]);
    println!("{}", critical_edges);
}