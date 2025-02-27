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
int board[51][51];
bool visited[51][51];
int dxdy[4][2] = {
  {1,0},
  {-1,0},
  { 0,1 },
  {0,-1}
};
int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);

int T, N, M, K;
cin >> T;
for (int t = 0; t < T;t++) {
  cin >> M >> N >> K;
  memset(board ,0, sizeof(board));
  memset(visited, 0, sizeof(visited));
  for (int k = 0; k < K;k++) {
    int c, r;
    cin >> c >> r;
    board[r][c] = 1;
  }

  // for( int i =0 ; i<N; i++){
  //   for( int j =0 ; j<M; j++){
  //     cout << board[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  int ans = 0;
  for (int i = 0; i < N;i++) {
    for( int j =0 ; j<M ;j++){
      if (visited[i][j] || board[i][j]==0)  continue;
      queue<pair<int, int>> q;
      ans++;
      q.push({ i,j });
      visited[i][j] = 1;
      while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        for( int j =0 ; j<4 ;j++){
          pair<int, int> next = { curr.first + dxdy[j][0], curr.second + dxdy[j][1] };
          if (next.first >= N || next.first < 0 || next.second >= M || next.second < 0) continue;
          if (visited[next.first][next.second] || board[next.first][next.second]==0) continue;
          visited[next.first][next.second] = 1;
          q.push({ next.first,next.second });
        }
      }

    }
  }
  cout << ans << endl;
}


return 0;
}