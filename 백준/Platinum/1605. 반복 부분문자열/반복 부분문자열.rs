use std::io::{self, Read};

fn build_suffix_array(s: &[u8]) -> Vec<usize> {
    let n = s.len();
    let mut sa: Vec<usize> = (0..n).collect();
    let mut rank: Vec<i32> = s.iter().map(|&c| c as i32).collect();
    let mut tmp = vec![0i32; n];

    let mut k = 1;
    loop {
        sa.sort_by_key(|&i| {
            let second = if i + k < n { rank[i + k] } else { -1 };
            (rank[i], second)
        });

        tmp[sa[0]] = 0;
        for i in 1..n {
            let a = sa[i - 1];
            let b = sa[i];

            let ra1 = rank[a];
            let rb1 = rank[b];
            let ra2 = if a + k < n { rank[a + k] } else { -1 };
            let rb2 = if b + k < n { rank[b + k] } else { -1 };

            tmp[b] = tmp[a] + if (ra1, ra2) != (rb1, rb2) { 1 } else { 0 };
        }

        rank.copy_from_slice(&tmp);

        if rank[sa[n - 1]] == (n as i32 - 1) {
            break;
        }
        k <<= 1;
    }

    sa
}

fn build_lcp(s: &[u8], sa: &[usize]) -> Vec<usize> {
    let n = s.len();
    let mut rank = vec![0usize; n];
    for i in 0..n {
        rank[sa[i]] = i;
    }

    let mut lcp = vec![0usize; n - 1];
    let mut h = 0usize;

    for i in 0..n {
        let r = rank[i];
        if r == 0 {
            continue;
        }
        let j = sa[r - 1];

        while i + h < n && j + h < n && s[i + h] == s[j + h] {
            h += 1;
        }

        lcp[r - 1] = h;

        if h > 0 {
            h -= 1;
        }
    }

    lcp
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let l: usize = it.next().unwrap().parse().unwrap();
    let s_str = it.next().unwrap();
    let s = s_str.as_bytes();

    if l <= 1 {
        println!("0");
        return;
    }

    let sa = build_suffix_array(s);
    let lcp = build_lcp(s, &sa);

    let ans = lcp.into_iter().max().unwrap_or(0);
    println!("{ans}");
}