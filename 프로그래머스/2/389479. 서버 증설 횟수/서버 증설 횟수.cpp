#include <string>
#include <vector>
#include <queue>
using namespace std;
int solution(vector<int> players, int m, int k) {
    int answer = 0;
    priority_queue<int, vector<int> ,greater<int>> q;
    for(int i=0; i<24;i++){
        while(!q.empty() && q.top()<=i){
            q.pop();
        }
        int cntNeedServer = players[i]/ m;
        int cntAddServer =max(cntNeedServer -(int)q.size() ,0);
        answer += cntAddServer;
        for(int j=0; j<cntAddServer; j++){
          q.push({i+k});   
        }
    }
    return answer;
}