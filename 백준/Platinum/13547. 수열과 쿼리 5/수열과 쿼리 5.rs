use std::io::{self, Read};

struct Fenwick {
    n: usize,
    tree: Vec<i32>,
}

impl Fenwick {
    fn new(n: usize) -> Self {
        Self {
            n,
            tree: vec![0; n + 1],
        }
    }

    fn add(&mut self, mut idx: usize, val: i32) {
        while idx <= self.n {
            self.tree[idx] += val;
            idx += idx & idx.wrapping_neg();
        }
    }

    fn sum(&self, mut idx: usize) -> i32 {
        let mut res = 0;
        while idx > 0 {
            res += self.tree[idx];
            idx -= idx & idx.wrapping_neg();
        }
        res
    }

    fn range_sum(&self, l: usize, r: usize) -> i32 {
        self.sum(r) - self.sum(l - 1)
    }
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let n: usize = it.next().unwrap().parse().unwrap();

    let mut a = vec![0usize; n + 1];
    for i in 1..=n {
        a[i] = it.next().unwrap().parse().unwrap();
    }

    let m: usize = it.next().unwrap().parse().unwrap();

    let mut queries_by_r = vec![Vec::<(usize, usize, usize)>::new(); n + 1];
    for idx in 0..m {
        let l: usize = it.next().unwrap().parse().unwrap();
        let r: usize = it.next().unwrap().parse().unwrap();
        queries_by_r[r].push((l, r, idx));
    }

    let mut bit = Fenwick::new(n);
    let mut last = vec![0usize; 1_000_001];
    let mut ans = vec![0i32; m];

    for i in 1..=n {
        let x = a[i];

        if last[x] != 0 {
            bit.add(last[x], -1);
        }
        bit.add(i, 1);
        last[x] = i;

        for &(l, r, idx) in &queries_by_r[i] {
            ans[idx] = bit.range_sum(l, r);
        }
    }

    let mut out = String::new();
    for v in ans {
        out.push_str(&format!("{v}\n"));
    }
    print!("{out}");
}