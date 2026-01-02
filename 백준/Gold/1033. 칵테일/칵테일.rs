use std::io;


#[derive(Clone, Copy)]
struct Fraction {
    num: i64,
    den: i64,
}


fn gcd(a: i64, b: i64) -> i64 {
    if b == 0 {
        a
    } else {
        gcd(b, a % b)
    }
}

fn dfs(
    node: usize,
    graph: &Vec<Vec<i32>>,
    weights: &Vec<Vec<Fraction>>,
    parents: &mut Vec<i32>,
    values: &mut Vec<i64>,
    visited: &mut Vec<bool>,
) {
    visited[node] = true;
    for &neighbor in &graph[node] {
        let neighbor = neighbor as usize;
        if parents[neighbor] == -1 && neighbor != 0 && visited[neighbor] == false {
            parents[neighbor] = node as i32;
            let weight = weights[node][neighbor];
            let factor = weight.den / gcd( weight.den, values[node]);
            values[0] *= factor;
            // println!(" root value {} ", values[0]);
            update_values(0, graph, weights, parents, values);
            dfs(neighbor, graph, weights, parents, values , visited);
        }
    }
}

fn update_values(
    node: usize,
    graph: &Vec<Vec<i32>>,
    weights: &Vec<Vec<Fraction>>,
    parents: &Vec<i32>,
    values: &mut Vec<i64>,
) {
    for &neighbor in &graph[node] {
        let neighbor = neighbor as usize;
        if parents[neighbor] == node as i32 {
            let weight = weights[node][neighbor];
            values[neighbor] = values[node] * weight.num / weight.den;
            update_values(neighbor, graph, weights, parents, values);
        }
    }
}

fn main(){

    let mut n = String::new();
    let mut graph: Vec<Vec<i32>> = Vec::new();
    let mut values: Vec<i64> = Vec::new();
    let mut parents: Vec<i32> = Vec::new();
    let mut seeds: Vec<Vec<usize>> = Vec::new();
    let mut weights: Vec<Vec<Fraction>> = Vec::new();
    let mut frations: Vec<Vec<Fraction>> = Vec::new();
    let mut visited: Vec<bool> = Vec::new();

    io::stdin()
        .read_line(&mut n)
        .expect("Failed to read line");
    let n: i32 = n.trim().parse().expect("Please type a number!");
    values.resize(n as usize, 0);
    parents.resize(n as usize, -1);
    visited.resize(n as usize, false);
    graph.resize(n as usize, Vec::new());
    weights.resize(n as usize, vec![Fraction { num: 0, den: 0 }; n as usize]);
    for i in 0..n-1 {
      
        let mut line = String::new();
        io::stdin()
            .read_line(&mut line)
            .expect("Failed to read line");

        let nums: Vec<i32> = line
            .trim()
            .split_whitespace()
            .map(|x| x.parse().expect("Please type a number!"))
            .collect();

        let len =nums.len();
        // println!(" nums {len}");
        
        //분수 기약분수로 만들기
        let gcd_value = gcd(nums[2] as i64, nums[3] as i64);
        
        // println!(" gcd_value {gcd_value}");
        let num: i64 = nums[2] as i64/gcd_value;
        let dem: i64 = nums[3] as i64 /gcd_value;

        graph[nums[0] as usize].push(nums[1]);
        weights[nums[0] as usize][nums[1] as usize] = Fraction { num: dem, den: num };

        graph[nums[1] as usize].push(nums[0]);
        weights[nums[1] as usize][nums[0] as usize] = Fraction { num: num, den: dem };
    }
   
    values[0] = 1;
    dfs(0, &graph, &weights, &mut parents, &mut values, &mut visited  );
    let root_node = 0;


    for val in values {
        print!("{} ", val);
    }


}