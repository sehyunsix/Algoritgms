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
int N, M;
int dx(int i, int x) {
  if (i == 0) return x - 1;
  else if (i == 1) return x + 1;
  else return 2 * x;
};


int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
cin >> N >> M;

vector<int> visited(100001, -1);

queue<int> q;
q.push(N);
visited[N] = 0;
while (!q.empty()) {
  int curr = q.front();
  // cout << curr << endl;
  q.pop();
  for (int i = 0; i < 3;i++) {
    int next = dx(i, curr);
    // cout << next << " " <<visited[next]  <<endl;
    if (next < 0 || next>100001 || visited[next] != -1) {
      continue;
    }
    q.push(next);
    visited[next] = visited[curr] + 1;
  }

}

cout << visited[M] << endl;


return 0;
}