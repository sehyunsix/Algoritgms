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
#define INF 987654321
using namespace std;
int N, M;
vector<int> cost;
vector<vector<pair<int, int>>> adj;
vector<bool> visited;


int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> N >> M;

  adj.resize(N + 1);
  cost = vector<int>(N + 1, INT32_MAX);

  for (int i = 0; i < M;i++) {
    int x, y, c;
    cin >> x >> y >> c;
    adj[x].push_back({ y,c });
  }

  int s, t;
  cin >> s >> t;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  cost[s] = 0;
  q.push({ 0, s });
  while (!q.empty()) {
    pair<int, int> curr = q.top();
    q.pop();
    if (cost[curr.second] < curr.first) continue;
    for (pair<int, int> next : adj[curr.second]) {
      if (curr.first + next.second >= cost[next.first]) continue;
      cost[next.first] = curr.first + next.second;
      q.push({ curr.first + next.second , next.first });
    }
  }

  cout << cost[t] << endl;




  return 0;
}