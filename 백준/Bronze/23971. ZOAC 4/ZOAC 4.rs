use std::io::{Read , Write};

fn main(){
let mut input = String::new();
std::io::stdin().read_to_string(&mut input);
let mut it = input.split_whitespace();
let h : i32 = it.next().unwrap().parse().unwrap();
let w : i32 = it.next().unwrap().parse().unwrap();
let n : i32 = it.next().unwrap().parse().unwrap();
let m : i32 = it.next().unwrap().parse().unwrap();

let max_n : i32 = (h-1)/(n+1)+1;
let max_m : i32 = (w-1)/(m+1)+1;

println!("{}" , max_m *max_n);



}