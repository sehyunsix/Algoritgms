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
int N;

typedef struct cmpCost {
  bool operator()( pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
  }
}cmpCost;

vector<vector<pair<int, int>>> adj;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int makeNodeKey(int i, int j,  int n) {
  return i * n + j;
}

int dijkstra(int st, int en) {

  vector<int> cost(N*N + 1, INT32_MAX);
  vector<bool> visited(N*N + 1, 0);
  priority_queue<pair<int, int> ,vector<pair<int, int>>, cmpCost> q;
  q.push({ st,0 });

  while (!q.empty()) {
    pair<int, int> curr = q.top();
    q.pop();
    if (visited[curr.first]) continue;
    cost[curr.first] = curr.second;
    visited[curr.first] = true;

    for (auto next : adj[curr.first]) {
      if (visited[next.first]) continue;
      if (cost[next.first] < curr.second + next.second) continue;
        q.push({ next.first, curr.second + next.second });
    }
  }

  return cost[en];
}

int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
int t = 1;
while (1) {
  cin >> N;
  if (N == 0) break;
  adj = vector<vector<pair<int, int>>>(N*N+ 1, vector<pair<int, int>>());
  vector<vector<int>> m = vector<vector<int>>(N, vector<int>(N, 0));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N;j++) {
      cin >> m[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N;j++) {
      int curr = makeNodeKey(i, j, N);
      for (int k = 0; k < 4;k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        int next = makeNodeKey(nx, ny, N);
        adj[curr].push_back({ next, m[nx][ny] });
      }
    }
  }
  cout << "Problem " << t<<": " << dijkstra(0, makeNodeKey(N - 1, N - 1, N)) + m[0][0] <<endl;
  t++;
}
return 0;
}