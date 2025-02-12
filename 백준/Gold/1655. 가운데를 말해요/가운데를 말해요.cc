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

priority_queue<int> leftQueue;
priority_queue<int, vector<int>, greater<int>> rightQueue;

int N;
cin >> N;

for (int i = 0; i < N; i++) {
  int tmp;
  cin >> tmp;
  if (leftQueue.size() <= rightQueue.size()) {
    leftQueue.push(tmp);
  }
  else {
    rightQueue.push(tmp);
  }

  if (!rightQueue.empty()) {
    if (rightQueue.top() < leftQueue.top()) {
      int rqt = rightQueue.top();
      int lqt = leftQueue.top();
      leftQueue.pop();
      rightQueue.pop();
      leftQueue.push(rqt);
      rightQueue.push(lqt);
    }
  }
  cout << leftQueue.top() << endl;
}



return 0;
}