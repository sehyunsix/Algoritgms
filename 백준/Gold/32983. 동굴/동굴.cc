#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<queue>
#include <string>
#include<math.h>
#define ll long long
using namespace std;

int m[1001][1001];
bool visited[1001][1001];
int dp[1000001];

int dxdy[4][2] = {
  {0,1},
  {0,-1},
  {1,0},
  {-1,0}
};

typedef struct Info {

  int r;
  int c;
  int level;

}Info;

int main() {

  int N, M, C;
  cin >> N >> M >> C;
  int s1, s2;
  cin >> s1 >> s2;
  for (int i = 0; i < N; i++) {
    for( int j =0 ; j<M ;j++){
      cin >> m[i+1][j+1];
    }
  }
  m[0][0] = -1;
  queue<Info> q;
  q.push({ s1,s2,0 });
  dp[0] = m[s1][s2];
  visited[s1][s2] = true;



  while (!q.empty()) {
    Info node = q.front();
    q.pop();

    // cout << node.r << node.c << endl;
    for (int i = 0; i < 4; i++) {
      Info new_node;
      new_node.r = node.r + dxdy[i][0];
      new_node.c = node.c + dxdy[i][1];
      new_node.level = node.level + 1;

      if (!visited[new_node.r][new_node.c] && m[new_node.r][new_node.c] != -1 && new_node.r > 0 && new_node.r <= N && new_node.c> 0 && new_node.c <= M) {
            dp[new_node.level] += m[new_node.r][new_node.c];
            visited[new_node.r][new_node.c] = true;
            q.push(new_node);
      }
    }

  }

  // cout << "visited" << endl;
  // for (int i = 0; i < N; i++) {
  //   for (int j = 0; j < M; j++) {

  //     cout << visited[i + 1][j + 1] << " ";

  //   }
  //   cout << endl;

  // }
  // for (int i = 1; i < N * M + 1; i++) {
  //   cout << dp[i] << " ";
  // }

  for( int i =1 ; i<N*M+1; i++){
    dp[i] += dp[i - 1];
  }


  for (int i = 0; i < N * M + 1; i++) {
    dp[i] -= C * i;
  }

  int ans = 0;
  for (int i = 0; i < N * M + 1; i++) {
    ans = max(dp[i], ans);
  }
  cout << ans << endl;


  return 0;
}