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
#define maxN 16
using namespace std;
int N;
//i N :  방문한 사람들 목록
//j N :  방문한 마지막 노드
//k 2 :  방문한 마지막 노드서의 값
int dp[1 << maxN][maxN][2];
int adj[maxN][maxN];

int dfs(int node ,int depth ,int prev ,int path) {
  int maxDepth = depth;
  for (int i = 1; i < N; i++) {
    if ((path>>i)%2) continue;
    if (adj[node][i] < prev)  continue;
    int nextPath = (path | 1 << i);
    if (dp[nextPath][i][0] == -1 || dp[nextPath][i][1] > adj[node][i]) {
      maxDepth = max(maxDepth, dfs(i, depth + 1, adj[node][i], nextPath));
    }
    else {
      maxDepth = max(maxDepth, dp[nextPath][i][0]);
    }
  }

  dp[path][node][0] = maxDepth;
  dp[path][node][1] = prev;
  return maxDepth;
}

int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
cin >> N;
for (int i = 0; i < N; i++) {
  for (int j = 0; j < N;j++) {
    char tmp;
    cin >> tmp;
    tmp = tmp - '0';
    adj[i][j] = tmp;
  }
}

for (int j = 0; j < (1 << maxN);j++) {
  for (int i = 0; i < maxN;i++) {
    dp[j][i][0] = -1;
  }
}

dfs(0, 1, 0, 1);

// for (int j = 0; j < (1 << maxN);j++) {
//   for (int i = 0; i < maxN;i++) {
//     cout << dp[j][i] << " ";
//   }
//   cout << endl;
// }
cout << dp[1][0][0] << endl;


return 0;
}