
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
char board[50][50];
int visited[50][50];
int dp[50][50];
int dxdy[4][2] = {
  {-1, 0},
  {1, 0},
  {0, 1},
  {0,-1},
};


int dfs(pair<int, int> node ) {
  int tmp = 0;
  for (int i = 0; i < 4;i++) {
    int dis = board[node.first][node.second] - '0';
    pair<int, int> next = { node.first + dis * dxdy[i][0], node.second + dis * dxdy[i][1] };
    if (next.first < 0 || next.first >= N || next.second < 0 || next.second >= M || board[next.first][next.second] == 'H') {
      tmp= max(tmp, 1);
    }
    else {
      if (visited[next.first][next.second]) {
        dp[node.first][node.second] = INT32_MAX;
        return INT32_MAX;
      };
      visited[next.first][next.second] = true;
      int res = (dp[next.first][next.second] != 0 ? dp[next.first][next.second] : dfs(next));
      visited[next.first][next.second] = false;
      tmp = (res == INT32_MAX ? res: max(tmp, res + 1));
    }
  }

  dp[node.first][node.second] = tmp;
  return dp[node.first][node.second];
}


int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
cin >> N >> M;
for (int i = 0; i < N;i++) {
  for (int j = 0; j < M;j++) {
    cin >> board[i][j];
  }
}

visited[0][0] = true;
dfs({ 0,0 });
cout << (dp[0][0]==INT32_MAX?-1:dp[0][0]) << endl;

return 0;
}