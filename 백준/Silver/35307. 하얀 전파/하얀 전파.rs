use std::error::Error;
use std::io::{Read, Write, BufWriter};
use std::convert::TryInto;


fn main()->Result<(), Box<dyn Error>> {

    let mut input = String::new();
    std::io::stdin().read_to_string(&mut input).unwrap();
    let mut iter = input.lines();
    let t : i64 = iter.next().unwrap().parse()?;
    let stdout = std::io::stdout();
    let mut out = BufWriter::new(stdout.lock());
    for _ in 0..t {
        let [n, m, l, r, u, d]: [i64; 6]
            = iter
                .next().unwrap()
                .split_whitespace()
                .map( |x| x.parse::<i64>())
                .collect::<Result<Vec<i64>,_>>().unwrap()
                .try_into().unwrap();
        // println!("{n} {m} {l} {r} {u} {d}");
        let mut w: i64 = 0;
        let mut t: i64 = 0;
        if l+r !=0 && u+d !=0 {
            w = n*m;
            t=(m-2)/(l+r)+1+(n-2)/(u+d)+1;
            if m==1 {
                t =(n-2)/(u+d)+1;
            }
            if n==1 {
                t= (m-2)/(l+r)+1;
            }
            if m*n ==1 {
                t= 0;
            }

        }
        else if l+r==0 && u+d !=0 {
            w = n;
            t = (n-2)/(u+d)+1;
        }
        else if l+r !=0 && u+d ==0 {
            w = m;
            t = (m-2)/(l+r)+1;
        }
        else{
            w=1;
            t=0;
        }
        writeln!(out, "{} {}", w, t)?;
    } 
    Ok(())

}