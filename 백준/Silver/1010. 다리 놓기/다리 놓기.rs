use std::io::{self, Read};


fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut n_ck = [[0i64; 33] ;33];
    n_ck[0][0] = 1;

    for i in 0..33 {
        n_ck[i][0] = 1;
    }

    for i in 0..33 {
        n_ck[i][i] = 1;
    }

    for i in 1..33{
        for j in 1..i {
            n_ck[i][i-j] = n_ck[i-1][i-j-1] + n_ck[i-1][i-j];
        }
    }

    // for i in 0..33 {
    //     for j in 0..33 {
    //         print!("{} ", n_ck[i][j]);
    //     }
    //     print!("\n");
    // }

    let t = input.trim().parse().unwrap();
    for _ in 0..t {
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        let mut iter = input.trim().split_whitespace();
        let n : usize = iter.next().unwrap().parse().unwrap();
        let m : usize = iter.next().unwrap().parse().unwrap();
        // println!(" n : {n} m : {m}");
        println!("{}", n_ck[m][n]);
    }
}