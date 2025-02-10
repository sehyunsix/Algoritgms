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
bool m[1000][1000];
int visited[1000][1000][2];
int dxdy[4][2] = {
  {1,0},
  {-1,0},
  { 0,1 },
  {0,-1}
};

typedef struct Info{
  int heart;
  pair<int, int> pos;
}Info;

int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> N >> M;

  for (int i = 0; i < N;i++) {
    for (int j = 0; j < M;j++) {
      char tmp;
      cin >> tmp;
      m[i][j] =tmp - '0';
    }
  }

 for(int i=0; i<N;i++){
  for(int j=0; j<M; j++){
    for(int h=0;h<2;h++){
      visited[i][j][h] = INT32_MAX;
    }
  }
 }
  queue<Info> q;
  q.push({1,{0,0}});
  visited[0][0][1] = 0;
  while (!q.empty()) {
    Info curr = q.front();
    // cout << curr.pos.first << " " << curr.pos.second << endl;
    q.pop();
    for (int i = 0; i < 4;i++) {
      Info next;
      next.pos.first = curr.pos.first + dxdy[i][0];
      next.pos.second = curr.pos.second + dxdy[i][1];
      if (next.pos.first < 0 || next.pos.first >= N || next.pos.second < 0 || next.pos.second >= M || visited[next.pos.first][next.pos.second][curr.heart] != INT32_MAX) {
        continue;
      }
      if (m[next.pos.first][next.pos.second] == 1 && curr.heart ==0 ) {
          continue;
      }
      if (m[next.pos.first][next.pos.second] == 1 && curr.heart ==1 ) {
        next.heart = 0;
      }
      else {
        next.heart = curr.heart;
      }
      q.push(next);
      visited[next.pos.first][next.pos.second][next.heart] = visited[curr.pos.first][curr.pos.second][curr.heart] + 1;
    }

  }
  if (visited[N - 1][M - 1][0] == INT32_MAX && visited[N - 1][M - 1][1] == INT32_MAX) {
    cout << -1 << endl;
  }
  else {
    cout << min(visited[N - 1][M - 1][0], visited[N - 1][M - 1][1]) + 1 << endl;
  }


return 0;
}