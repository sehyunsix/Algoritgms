use std::io::{self, Read};

const MOD: i32 = 9901;

fn dfs(
    row: usize,
    n: usize,
    cur_mask: usize,
    next_mask: usize,
    val: i32,
    next_dp: &mut [i32],
) {
    if row == n {
        next_dp[next_mask] = (next_dp[next_mask] + val) % MOD;
        return;
    }

    // already occupied
    if (cur_mask & (1 << row)) != 0 {
        dfs(row + 1, n, cur_mask, next_mask, val, next_dp);
        return;
    }

    // 1) place horizontal domino -> occupies this cell in current col
    // and the corresponding cell in next col
    dfs(
        row + 1,
        n,
        cur_mask,
        next_mask | (1 << row),
        val,
        next_dp,
    );

    // 2) place vertical domino -> occupies row and row+1 in current col
    if row + 1 < n && (cur_mask & (1 << (row + 1))) == 0 {
        dfs(row + 2, n, cur_mask, next_mask, val, next_dp);
    }
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let n: usize = it.next().unwrap().parse().unwrap();
    let m: usize = it.next().unwrap().parse().unwrap();

    let size = 1usize << n;
    let mut dp = vec![0i32; size];
    dp[0] = 1;

    for _ in 0..m {
        let mut next_dp = vec![0i32; size];
        for mask in 0..size {
            if dp[mask] != 0 {
                dfs(0, n, mask, 0, dp[mask], &mut next_dp);
            }
        }
        dp = next_dp;
    }

    println!("{}", dp[0]);
}