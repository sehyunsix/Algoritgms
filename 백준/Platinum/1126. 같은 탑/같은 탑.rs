use std::io::Read;


fn main() {
    let mut input  = String::new();
    std::io::stdin().read_to_string(&mut input);
    let mut it = input.split_whitespace();
    let n : usize = it.next().unwrap().parse().unwrap();
    let mut array: Vec<usize> = it.take(n).map(|x| x.parse().unwrap()).collect();
    let mut dp = vec![vec![-1i32 ;500001];51];
    array.sort();
    let s : usize = array.iter().sum();
    
    dp[0][0]=0;
    for i in 1..n+1 {
        for k  in 0usize..s as usize+1 {
            if (k+array[i-1]) <= s  && (k+array[i-1]) <= 250000  {
                dp[i][k] = dp[i][k].max(dp[i-1][k+array[i-1]]);
            }
            let diff :i32 = (array[i-1] as i32 -k as i32).abs();
            if(dp[i-1][diff as usize]>= 0){
                if (array[i-1] as i32 -k as i32)<0 {
                    dp[i][k]= dp[i][k].max(dp[i-1][diff as usize]+k as i32- diff );
                }else{
                    dp[i][k]= dp[i][k].max(dp[i-1][diff as usize]+k as i32);
                }            
            }
            dp[i][k]= dp[i][k].max(dp[i-1][k]);
        }
    }

    let mut sol : i32= 0;
    for i in 1..n+1 {
        sol = sol.max(dp[i][0]);
    }
    if sol ==0  {
        println!("{}",-1);
    }else{
        println!("{sol}");
    }
}