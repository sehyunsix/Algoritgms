#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> board(n , vector<int>(n,0));
    int total_count = n*(n+1)/2;
    int dxdy[4][2]= {
        {1,0},
        {0,1},
        {-1,-1},
    };
    int dir =0;
    int count =1;
    pair<int,int> curr= {0,0};
    pair<int,int> next ={0,0};
    while(count<=total_count){
        board[curr.first][curr.second] =count;
        count++;
        
        next.first = curr.first +dxdy[dir][0];
        next.second = curr.second+dxdy[dir][1];
        
        if(0<=next.first && next.first< n && 0<=next.second && next.second< n &&
          board[next.first][next.second]==0
          ){
            curr=next;
        }
        else{
            dir = (dir+1)%3;
            next.first = curr.first +dxdy[dir][0];
            next.second = curr.second+dxdy[dir][1];
            curr=next;
        }
        
     
    }
       for( auto v : board){
            for(auto i : v){
                if(i>0)
                answer.push_back(i);
            }
        }

    
    return answer;
    
}