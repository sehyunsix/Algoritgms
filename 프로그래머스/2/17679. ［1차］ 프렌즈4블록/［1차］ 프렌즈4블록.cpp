#include <string>
#include <vector>
#include<iostream>
using namespace std;


int remove(vector<string>& board ,vector<vector<bool>>& removed_list){
    int removed =0;
    int N = board.size();
    int M = board[0].size();
    for(int i=0; i<N-1; i++){
        for(int j=0; j<M-1; j++){
            
            char prev = board[i][j];
            bool chk =true;
            for(int k=0; k<2; k++){
                for(int l=0; l<2; l++){
                    if(prev != board[i+k][j+l] || board[i+k][j+l] =='*' ){
                        chk=false;
                        break;
                    }
                }
            }
            if(chk){
                
                for(int k=0; k<2; k++){
                for(int l=0; l<2; l++){
                    if(!removed_list[i+k][j+l]){
                        removed++;
                    }
                    removed_list[i+k][j+l] =1;
               
                    }
                 }
            }
            
            
        }
    }
    return removed;
    
}

void drop(vector<string>& board ,vector<vector<bool>>&  removed_list){
    int N = board.size();
    int M = board[0].size();
    for(int c=0; c<M; c++ ){
        int move_count= 0;
        int r= N-1;
        while(r>=0){
            if(removed_list[r][c]){
                board[r][c] ='*';
                move_count++;
            }
            else if(!removed_list[r][c] && move_count+r <=N-1){
                if(move_count > 0){
                board[r+move_count][c] =board[r][c];
                board[r][c] ='*';
                }
          
            } 
            r--;
        }
         
    }
    return;
    
}

int solution(int m, int n, vector<string> board) {
    vector<vector<bool>> removed_list(m, vector<bool>(n, 0));
    int answer = 0;
    int removed=0;
    do{
       for(int i=0; i<m;i++){
           for(int j=0; j<n;j++){
               removed_list[i][j] =0;
           }
       }
        
    // for(auto v : board){
    //     for(auto p : v){
    //         cout << p;
    //     }
    //     cout << endl;
    // }
    removed = remove(board ,removed_list);
    answer+= removed;
    drop(board,removed_list);
    }while(removed>0);
    return answer;
}