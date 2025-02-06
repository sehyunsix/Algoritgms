#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for(vector<string> place : places){
        int N = place.size();
        int M = place[0].size();
        bool a  = true;
        for(int i=0;i <N-1 && a;i++){
            for(int j=0; j<M-1 && a; j++){
                int p_c=0;
                int x_c=0;
               for(int k=0; k<2 ; k++){
                   for(int l=0; l<2 ; l++){
                       if(place[i+k][j+l] =='P' ){
                           p_c++;
                       } 
                   }
               }
               if(p_c>=2){
                   bool c =place[i][j] =='X' && place[i+1][j+1] =='X';
                   bool d = place[i][j+1] =='X' && place[i+1][j] =='X';
                   if( !c && !d) { a=false;}
               }
               if(i<N-2 && place[i][j] =='P' &&place[i+2][j] =='P' && place[i+1][j] !='X') {
                   a =false;
               }
               if(j<M-2 && place[i][j] =='P' &&place[i][j+2] =='P' && place[i][j+1] !='X') {
                   a= false;
               }
               if(j<M-2 && i<N-2&& place[i+2][j+2] =='P' &&place[i+2][j] =='P' && place[i+2][j+1] !='X') {
                   a= false;
               }
               if(j<M-2 && i<N-2&& place[i+2][j+2] =='P' &&place[i][j+2] =='P' && place[i+1][j+2] !='X') {
                   a= false;
               } 
            
            }
        }
        answer.push_back(a);
    }
 
    return answer;
}