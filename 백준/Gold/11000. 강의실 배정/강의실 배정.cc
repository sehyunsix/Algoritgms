#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<queue>
#include <string>
#include<math.h>
#include<map>
#define ll long long
#define P 1000000007
#define endl "\n"
using namespace std;



int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);

priority_queue<int, vector<int>, greater<int>> endQueue;
priority_queue<pair<int,int>, vector<pair<int,int>> ,greater<pair<int,int>>> startQueue;


int N;
cin >> N;
for (int i = 0; i < N; i++) {
  int s, t;
  cin >> s >> t;
  startQueue.push({ s,t });
}

int ans = 0;
while (!startQueue.empty()) {
  pair<int, int> curr = startQueue.top();
  startQueue.pop();
  if (endQueue.empty()) {
    endQueue.push(curr.second);
  }
  else{
    int fastEndTime = endQueue.top();
    if (fastEndTime <= curr.first) {
      endQueue.pop();
      endQueue.push(curr.second);
    }
    else {
      endQueue.push(curr.second);
    }
  }
  ans = max((int)endQueue.size(), ans);
}


cout << ans << endl;

return 0;
}