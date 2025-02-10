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
typedef struct Info {
  pair<int, int> pos;
  int time;
}Info ;
int N, M;
int m[1000][1000];
bool visited[1000][1000];
int dxdy[4][2]{

  {-1,0},
  {1,0},
  {0,-1},
  {0, 1}
};
int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
cin >> M>> N;

for (int i = 0; i < N;i++) {
  for( int j =0 ; j< M ;j++){
    cin >> m[i][j];
  }
}

queue<Info> q;


for (int i = 0; i < N; i++) {
  for (int j = 0; j < M; j++) {
    if (m[i][j] == 1)
    {
      // cout << "start" << i << " " << j << endl;
      visited[i][j] = 1;
      q.push({ { i,j }, 0 });
    }
  }
  }

  Info curr;
  Info next;
  while (!q.empty()) {
    curr = q.front();
    // cout << curr.pos.first << " " << curr.pos.second << endl;
    q.pop();
    for (int i = 0;i < 4;i++) {
      next.pos = { curr.pos.first + dxdy[i][0], curr.pos.second + dxdy[i][1] };
      next.time = curr.time + 1;
      if (next.pos.first < 0 || next.pos.first >= N || next.pos.second < 0 || next.pos.second >= M) {
        continue;
      }
      if (m[next.pos.first][next.pos.second] == -1) {
        continue;
      }
      if (visited[next.pos.first][next.pos.second]) {
        continue;
      }
      q.push(next);
      visited[next.pos.first][next.pos.second] = 1;
    }
  }

  for (int i = 0; i < N;i++) {
    for (int j = 0; j < M; j++) {
      if (visited[i][j] == 0 && m[i][j] == 0) {
        cout << -1 << endl;
        return 0;
      }
    }
  }

  cout << curr.time << endl;

return 0;
}