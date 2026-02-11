use::std::io::{Read, Write, self};
use std::cmp::max;

/*
 T <= 10^5
 S <= 10^5
example
eeeee
brainpowerletthebasskick
gggggg

   if chars[i] != chars[i+1]{
       dp[i+1][0] =dp[i][0]+1;
   }
   //update_one_words
   dp[i+1][0]= dp[i][1]+1;

   //update_two_words

   //from one words
   dp[i+1][1] = dp[i-1][0]+1;

   //from two words
   if not is_anagram( chars[i-2:i] , s[i:i+2]){
       dp[i+1][1]=max(dp[i][0], dp[i+1][1]);
   }


dp[i+1] = max(dp[i][

*/

fn is_anagram(s: &[char], b: &[char]) -> bool {
    let mut s_chars: Vec<char> = s.to_vec();
    let mut b_chars: Vec<char> = b.to_vec();

    if s_chars.len() != b_chars.len() {
        return false;
    }

    s_chars.sort_unstable();
    b_chars.sort_unstable();

    s_chars == b_chars
}


fn main()->Result<(),Box<dyn std::error::Error>> {
    let stdout = io::stdout();
    let mut out = io::BufWriter::new(stdout.lock());
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.lines();
    let mut dp: [[i64;2];100001]= [[0; 2]; 100001];

    //initialize
    dp[1][0]=1;
    dp[1][1]=0;
    let n : i64 =  iter.next().unwrap().parse()?;
    for _  in 0..n {
        let s = iter.next().unwrap();
        let chars: Vec<char> = s.chars().collect();
        for i in 1..s.len() {
            dp[i+1][0]=0;
            dp[i+1][1]=0;

            if chars[i - 1] != chars[i] {
                // println!("{} {}",chars[i-1], chars[i]);
                dp[i + 1][0] = dp[i][0] + 1;
            }
            //update_one_words
            dp[i + 1][0] = max(dp[i][1] + 1, dp[i+1][0]);
            //update_two_words
            //from one words
            dp[i + 1][1] = dp[i - 1][0] + 1;
            //from two words
            if i > 2 {
                if !is_anagram(&chars[i - 3..i - 1], &chars[i - 1..i + 1]) {
                    dp[i + 1][1] = max(dp[i][0], dp[i + 1][1]);
                }
            } else {
                dp[i + 1][1] = max(dp[i][0], dp[i + 1][1]);
            }
            //&str slice는 뭐 수 있지?
        }
        let mut sol: i64 = 0;
        for i in 1..s.len() + 1 {
            for j in 0..2 {
                sol = max(dp[i][j], sol);
            }
        }

        // for j in 0..2 {
        //     for i in 1..s.len() + 1 {
        //         print!("{}", dp[i][j]);
        //     }
        //     println!();
        // }

        writeln!(out, "{}", sol).unwrap();
    }
    Ok(())
}


