use std::io::{ Read};
use std::collections::{BinaryHeap};
use std::{fmt::Debug, iter::Cycle, ops::Index, sync::RwLock, usize, vec};

#[derive(Debug,Clone)]
struct Traffic{
   first :  usize,
   cycle : [usize; 2]
}

// 1 2 3 4 5 6 7 8 9 10
// X X X O O X X X O O  (2 3 ,1) 
// O O X X X O O X X X  (2 3, 0)

impl Traffic  {

    fn is_we_green(&self,  time :usize) -> bool{
        if self.first ==0  { 
            return ((time) % (self.cycle[0]+self.cycle[1]) )< self.cycle[0]
        }
        else
        {
            return ((time) % (self.cycle[0]+self.cycle[1])) >= self.cycle[1]
        }
    }

    //현재 시간 부터 가장 가까운 동서 신호등 초록색인 시점
    fn we_green_time(&self, time :usize ) ->  usize {
        // println!("wait at time :{time}");
        let mut res =time;
        while !self.is_we_green(res) {
            res += 1;
        }
        // println!("we green time : {res}");
        return  res;
    }
    
    //현재 시간 부터 가장 가까운 남북 신호등 초록색인 시점
    fn ns_green_time(&self, time :usize ) -> usize{
        let mut res =time;
        // println!("wait at time :{time}");
        while self.is_we_green(res) {
            res += 1;
        }
        // println!("ns green time : {res}");
        return  res;
    }
}

//시작점과 종착점이 주어졌을때 가장 빠른 시간을 출력함.
fn djkstra( 
    start : (usize ,usize) , 
    end : (usize, usize) , 
    board : &Vec<Vec<char>> ,
    traffic :&Vec<Traffic> )->i32{
    
    let (n, m) = (board.len() as i32 ,board[0].len() as i32);
    let mut dist  = vec![vec![1000000007;20];20];
    let mut pq = BinaryHeap::<(i32 ,i32,i32)>::new();
    let dxdy : [(i32,i32) ; 4] = [
        (1, 0),
        (0, 1),
        (-1,0),
        (0, -1)
    ];
    //base
    dist[start.0][start.1]=0;
    pq.push((0, start.0 as i32 ,start.1 as i32));


    //동시에 신호등이 들어갈 경우.?
    while !pq.is_empty() {
        let mut curr : (i32 ,i32, i32) = pq.pop().unwrap();
        // println!("curr : {:?}",curr);
        for d in dxdy {
            let  next =  (0, curr.1+d.0, curr.2+d.1);
            if next.1 >=n || next.1< 0 || next.2 >= m || next.2 <0 {
                continue;
            }
            let mut curr_t = curr.0.abs();
            let n_sym = &board[next.1 as usize][next.2 as usize];
            match n_sym  {
                '.'=> {continue;}
                '0'..'9'=>{
                    let idx : usize = n_sym.to_digit(10).unwrap()as usize;
                    // println!("traffic idx: {idx}");
                    if next.2 -curr.2 ==1 {
                        curr_t = curr_t.abs().max(traffic[idx].we_green_time(curr_t.abs() as usize) as i32);
                    }
                    else{
                        curr_t = curr_t.abs().max(traffic[idx].ns_green_time(curr_t.abs() as usize) as i32);
                    }
                }
                _=>{}
            }
            if dist[next.1 as usize ][next.2 as usize]> curr_t.abs()+1 {
                dist[next.1 as usize ][next.2 as usize]=curr_t.abs()+1;
                pq.push((-(curr_t.abs()+1),next.1 ,next.2));
            }

        }
    }

    return  dist[end.0][end.1];
}

fn main(){

    let mut input = String::new();
    std::io::stdin().read_to_string(&mut input);
    let mut it = input.lines();
    while let Some(line) = it.next() {
        let mut ws = line.split_whitespace();
        let n :usize = ws.next().unwrap().parse().unwrap();
        let m :usize = ws.next().unwrap().parse().unwrap();
        let mut start = (0usize, 0usize);
        let mut end  = (0usize, 0usize);
        let mut t = 0usize;
        if n==0 {
            break;
        } 
        let mut board = vec![vec!['.';m];n];
        for i in 0..n {
            let mut row :Vec<char> = it.next().unwrap().chars().collect();
            for j in 0..m{
                if '0'<=row[j] && row[j] <= '9' {
                    t += 1;

                }
                if row[j] == 'A' {
                    start =(i,j);
                } 
                if row[j] == 'B' {
                    end =(i,j);
                } 
                board[i][j] = row[j];
            }
        }
        
        let mut traffic : Vec<Traffic>=  vec![ Traffic { first:0 ,cycle : [0, 0] }; t];
        for i in 0.. t{
            ws =it.next().unwrap().split_whitespace();
            ws.next();
            let first = ws.next().unwrap().parse::<char>().unwrap().ne(&'-');
            let c1: usize = ws.next().unwrap().parse().unwrap();
            let c2: usize = ws.next().unwrap().parse().unwrap();
            traffic[i].first = first as usize;
            traffic[i].cycle = [c1 ,c2];
        }

        let mut sol = djkstra(start, end, &board, &traffic);
       
        //벽이 있고. 
        //정지
        //신호등
        //교차로 없으면 다익스트라가 짱임.
        //교차로 말고는? 




        // println!("================");
        // println!("{:?}", board);
        // println!("{:?}", traffic);
        if sol ==1000000007 {
            println!("impossible");
        }
        else{
            println!("{}", sol);
        }
        it.next();


    }


}