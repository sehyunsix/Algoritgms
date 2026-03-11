use std::io::{self, Read};

const MOD: i64 = 1_000_000_007;
const K: usize = 11;

struct Fenwick {
    n: usize,
    tree: Vec<i64>,
}

impl Fenwick {
    fn new(n: usize) -> Self {
        Self {
            n,
            tree: vec![0; n + 1],
        }
    }

    fn add(&mut self, mut idx: usize, val: i64) {
        let v = val % MOD;
        while idx <= self.n {
            self.tree[idx] += v;
            if self.tree[idx] >= MOD {
                self.tree[idx] -= MOD;
            }
            idx += idx & (!idx + 1);
        }
    }

    fn sum(&self, mut idx: usize) -> i64 {
        let mut res = 0;
        while idx > 0 {
            res += self.tree[idx];
            if res >= MOD {
                res -= MOD;
            }
            idx &= idx - 1;
        }
        res
    }

    fn range_sum(&self, left: usize, right: usize) -> i64 {
        if left > right {
            return 0;
        }
        let mut res = self.sum(right) - self.sum(left - 1);
        if res < 0 {
            res += MOD;
        }
        res
    }
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let n: usize = it.next().unwrap().parse().unwrap();
    let a: Vec<usize> = (0..n).map(|_| it.next().unwrap().parse().unwrap()).collect();

    // bits[len] stores counts for increasing subsequences of length len
    let mut bits: Vec<Fenwick> = (0..=K).map(|_| Fenwick::new(n)).collect();

    for &x in &a {
        let mut cur = [0i64; K + 1];
        cur[1] = 1;

        for len in 2..=K {
            cur[len] = bits[len - 1].sum(x - 1);
        }

        for len in 1..=K {
            bits[len].add(x, cur[len]);
        }
    }

    println!("{}", bits[K].sum(n));
}