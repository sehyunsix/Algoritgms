#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool com(vector<int> a , vector<int> b){
    
    if(a[0] != b[0]){
        return a[0] < b[0];
    }
    else{
        return a[1]< b[1];
    }
}

int solution(vector<vector<int>> targets) {
    
    int N =targets.size();
    
    sort(targets.begin(), targets.end(),com);
    
    int answer = 0;
    int tmp = -1e9;
    for(int i =0; i<N;i++){
        
       if(tmp<=targets[i][0]){
           answer+=1;
           tmp = targets[i][1];
       }
        else{
            if(tmp > targets[i][1]){
                tmp=targets[i][1];
            }
        }
      
    }
    return answer;
}
