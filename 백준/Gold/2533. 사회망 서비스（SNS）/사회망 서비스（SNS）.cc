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

vector<vector<int>> childNodes;
vector<vector<int>> dp;
vector<bool> visited;

void dfs(int node) {
  visited[node] = true;
  dp[node][1] = 1;
  dp[node][0] = 0;

  for (auto c : childNodes[node]) {
    if (!visited[c]) {
      dfs(c);
      dp[node][0] += dp[c][1];
      dp[node][1] += min(dp[c][1], dp[c][0]);
    }
  }
}

int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  childNodes = vector<vector<int>>(N + 1, vector<int>());
  visited = vector<bool>(N + 1, 0);
  dp = vector<vector<int>>(N + 1, vector<int>(2, -1));

  for (int i = 0; i < N-1;i++) {
    int x, y;
    cin >> x >> y;
    childNodes[x].push_back(y);
    childNodes[y].push_back(x);
  }

  dfs(1);
  cout << min(dp[1][0], dp[1][1]) << endl;

return 0;
}