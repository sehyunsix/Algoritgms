#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;


int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    int q1_pointer = 0;
    int q2_pointer = queue1.size();
    long long q1_sum =0;
    long long q2_sum =0;
    int count = 0;
    vector<int> total_queue;
    for(int q: queue1){
        total_queue.push_back(q);
        q1_sum += q;
    }
    for(int q: queue2){
        total_queue.push_back(q);
        q2_sum += q;
    }
    
    while(count < total_queue.size()*2){
        // cout << q1_sum << " " <<q2_sum << endl;
        if(q1_sum > q2_sum){
            q1_sum = q1_sum - total_queue[q1_pointer];
            q2_sum = q2_sum + total_queue[q1_pointer];
            q1_pointer = (q1_pointer+1)%total_queue.size();
            count++;


        }
        else if(q1_sum < q2_sum){
            q2_sum = q2_sum - total_queue[q2_pointer];
            q1_sum = q1_sum + total_queue[q2_pointer];
            q2_pointer = (q2_pointer+1)%total_queue.size();
            count++;

        }
        else{
            break;
        }
    };
    if(count ==total_queue.size()*2){
        return -1;
    }else{
        return count;
    }
    
}