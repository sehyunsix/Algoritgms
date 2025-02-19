#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int N ,M;
int dx[4]={-1,1,0,0};
int dy[4] ={0,0,-1,1};
bool removed[52][52];
bool crainRemoved[52][52];
bool tmpRemoved[52][52];

void bfs(int r, int c  ){
    queue<pair<int,int>> q;
    q.push({r,c});
    vector<vector<bool>> visited(N+2,vector<bool>(M+2,0));
    while(!q.empty()){
        pair<int,int> curr = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            pair<int,int> nx = { curr.first + dx[i] , curr.second+dy[i]};
            if(nx.first <0|| nx.first >= N+2 || nx.second<0 || nx.second >=M+2)
                continue;
            if(visited[nx.first][nx.second]) continue;
            if(!removed[nx.first][nx.second] && !crainRemoved[nx.first][nx.second]) continue;
            visited[nx.first][nx.second] =true;
            tmpRemoved[nx.first][nx.second] =true;
            q.push({nx.first,nx.second});
        } 
    }

}

int solution(vector<string> storage, vector<string> requests) {
    N = storage.size();
    M = storage[0].size();
    
    for(int i=0; i<M+2;i++){
        removed[0][i] =1;
        removed[N+1][i] =1;
    }
    
    for(int i=0; i<N+2;i++){
        removed[i][M+1] =1;
        removed[i][0] =1;
    }
    
    int cntRemoved =0;
    for(string request : requests){
        for(int i=1; i<N+1;i++){
            for(int j=1; j<M+1;j++){
                tmpRemoved[i][j] =removed[i][j];
            }
        }
        for(int i=1; i<N+1;i++){
            for(int j=1; j<M+1;j++){
                  if(removed[i][j]) continue;
                  if(crainRemoved[i][j]) continue;
                  if(storage[i-1][j-1] != request[0]) continue;
                  if(request.size() != 1){
                      crainRemoved[i][j]= true;
                      cntRemoved++;
                  }
                  else{
                      bool chk =false;
                      for(int d=0; d<4; d++){
                        if(removed[i+dx[d]][j+dy[d]]) chk =true;
                      }
                      if(!chk) continue;
                      tmpRemoved[i][j]= true;
                      cntRemoved++;
                  }
                }
            }
        
        for(int i=1; i<N+1;i++){
            for(int j=1; j<M+1;j++){
                removed[i][j] =tmpRemoved[i][j];
            }
        }
        
        bfs(0,0);
        
          for(int i=1; i<N+1;i++){
            for(int j=1; j<M+1;j++){
                removed[i][j] =tmpRemoved[i][j];
            }
        }
        
            
        }

    return N*M-cntRemoved;
}