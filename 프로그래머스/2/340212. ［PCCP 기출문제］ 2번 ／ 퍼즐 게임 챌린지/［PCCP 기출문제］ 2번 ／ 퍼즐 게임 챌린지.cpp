#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    
    int N = diffs.size();
    
    int max_level = *max_element(diffs.begin(),diffs.end());
    cout << max_level << endl;
    int start =1;
    int end = max_level;
    int mid = 0;
    while(start<end){
      
        mid = (start+end)/2;
        long long total_time = times[0];
        for( int i = 1 ; i<N; i++){
            
            if(diffs[i]>mid){
            total_time += (times[i-1]+times[i])*(diffs[i]-mid);
            total_time += times[i];
                
            }
            else{
                total_time += times[i];
            }
        }
        // cout << "Total time :" << total_time << " level :"<<mid<< endl; 
        if(limit < total_time){
            start= mid+1;
        }
        else{
            end = mid;
        }
          
      
    }
    return start;
}