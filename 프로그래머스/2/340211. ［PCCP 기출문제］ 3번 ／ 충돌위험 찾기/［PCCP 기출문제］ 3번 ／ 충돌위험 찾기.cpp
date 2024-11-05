#include <string>
#include <vector>
#include <iostream>
using namespace std;

int map[102][102][20002];
int t =0;



    void make_path(vector<int>& start ,vector<int>& end){
    

        if( start[0] > end[0]){
            for(int i= start[0]-1 ; i >=end[0]; i--){
                t++;
                map[i][start[1]][t] += 1 ;
            }

        }
        else if( start[0] < end[0]) {

              for(int i= start[0]+1 ; i <=end[0]; i++){
                t++;
                map[i][start[1]][t] += 1 ;
            }

        }

     
        if( start[1] > end[1]) {

            for(int i= start[1]-1  ; i >=end[1]; i--){
                t++;
                map[end[0]][i][t] += 1;
            }
        }

        else if( start[1] < end[1]){

              for(int i= start[1]+ 1  ; i <=end[1]; i++){
                t++;
                map[end[0]][i][t] +=1 ;
            }
        }

        }

    


int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    
    for(vector<int> route : routes){
        t=0;
        int start_y = points[route[0]-1][0];
        int start_x =  points[route[0]-1][1];
        map[start_y][start_x][0] +=1;
        
        for(int i =1 ; i < route.size();i++){
   
            make_path(points[route[i-1]-1], points[route[i]-1]);
        }
        
    }
    
    for(int t= 0; t< 20001; t++){
        for(int i=1; i < 101; i++){
            for(int j=1; j<101; j++){
                if(map[i][j][t]>=2){
                    answer += 1 ;
                }
            }
        }
    }
    return answer;
}