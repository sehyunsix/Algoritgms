use std::io;
fn main(){
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let n : i64 = input.trim().parse().unwrap();
    input.clear();
    std::io::stdin().read_line(&mut input).unwrap();
    let mut arr :Vec<i64> =
        input.split_whitespace()
            .take(n as usize)
            .map(|x| x.parse().unwrap())
            .collect();
    // n <= 8
    // 2 <= x <= 8

    //E[X+Y+Z+D]= E[X] + E[Y] + E[Z] ...
    let mut sol =0.0 ;
    for i in 0..n  {
        let m = arr[i as usize];
        for j in 0..m as usize {
            sol += (j as f32 +1.0)/ (m as f32);
        }
    }
    println!("{}",sol);
}