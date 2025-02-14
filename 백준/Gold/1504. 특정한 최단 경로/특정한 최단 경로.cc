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
vector<int> cost;
vector<vector<pair<int, int>>> adj;
vector<bool> visited;


typedef struct cmpCost {

  bool operator()(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
  }

}cmpCost;


int dijkstra(int st ,int en){
  cost = vector<int>(N + 1, INT32_MAX);
  visited = vector<bool>(N + 1, 0);
  priority_queue<pair<int, int>, vector<pair<int, int>>, cmpCost> q;
  q.push({ st, 0 });
  while (!q.empty())  {
    pair<int, int> curr = q.top();
    q.pop();
    if (visited[curr.first])  continue;
    cost[curr.first] = curr.second;
    visited[curr.first] = true;
    for (pair<int, int> next : adj[curr.first]) {
      if (visited[next.first])  continue;
      if (curr.second + next.second > cost[next.first]) continue;
      q.push({ next.first, curr.second + next.second });
    }
  }
  return cost[en];
}


int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> N >> M;
  adj.resize(N + 1);
  for (int i = 0; i < M; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    adj[x].push_back({ y,c });
    adj[y].push_back({ x,c });
  }
  int u, v;
  cin >> u >> v;
  vector<pair<int, int>> path1 = { {1,u},{u,v},{v, N} };
  vector<pair<int, int>> path2 = { {1,v},{v,u},{u, N} };

  ll ans1 = 0;
  int chk1 = false;
  for (pair<int, int> p : path1) {
    int res = dijkstra(p.first,p.second);
    if (res == INT32_MAX) {
      chk1 =true;
      break;
    };
    ans1 += res;
  }

  ll ans2 = 0;
  bool chk2 = false;
  for (pair<int, int> p : path2) {
    int res = dijkstra(p.first, p.second);
    if (res == INT32_MAX) {
      chk2 = true;
      break;
    };
    ans2 += res;
  }

  ans1 = (chk1 ? INT32_MAX : ans1);
  ans2 = (chk2 ? INT32_MAX : ans2);


  if (chk1 && chk2) {
    cout << -1 << endl;
    return 0;
  }

  cout << min(ans1, ans2) << endl;


  return 0;
}