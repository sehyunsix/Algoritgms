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
int N, M ,S ,D;
vector<vector<pair<int, int>>> rightAdj;
vector<vector<pair<int, int>>> reverseAdj;
bool removedAdj[501][501];

//가설 폐기 ...
typedef struct DjkstraResult{
  vector<int> distance;
  vector<int> parents;
}DjkstraResult;

DjkstraResult Djkstra(int st,  vector<vector<pair<int, int>>>& adj) {
  vector<int> distance(N, INT32_MAX);
  vector<int> parents(N, 0);
  parents[st] = st;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  q.push({ 0, st });
  distance[st] = 0;
  while (!q.empty()) {
    pair<int, int> curr = q.top();
    q.pop();
    if (curr.first > distance[curr.second]) continue;
    for (pair<int, int> edge : adj[curr.second]) {
      if (removedAdj[curr.second][edge.first]) continue;
      if (curr.first + edge.second < distance[edge.first]) {
        distance[edge.first] = curr.first + edge.second;
        parents[edge.first] = curr.second;
        q.push({ curr.first + edge.second, edge.first });
        }
      }
  }
  return { distance ,parents };
}



int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
while (1) {
  cin >> N >> M;
  if (N == 0 && M == 0) break;
  rightAdj=vector<vector<pair<int, int>>>(N, vector<pair<int, int>>());
  reverseAdj = vector<vector<pair<int, int>>>(N, vector<pair<int, int>>());
  memset(removedAdj, 0, sizeof(removedAdj));
  cin >> S >> D;
  for (int j = 0; j < M;j++) {
    int u, v, w;
    cin >> u >> v >> w;
    // if (u == D) continue;
    rightAdj[u].push_back({ v,w });
    reverseAdj[v].push_back({ u,w });
  }
  DjkstraResult res = Djkstra(S, rightAdj);
  DjkstraResult reverseRes = Djkstra(D, reverseAdj);
  // vector<int> reverseDis = Djkstra(D, reverseAdj);
  // cout << "dis : ";
  // for (auto d :  res.distance) {
  //   cout << d << " ";
  // }
  // cout << endl;

  // cout << "dis : ";
  // for (auto d : reverseRes.distance) {
  //   cout << d << " ";
  // }
  // cout << endl;

  for (int j = 0; j < N;j++) {
    // cout << "dis : " << res.distance[j] << "reverse : " << reverseRes.distance[j] << endl;
    if (res.distance[j] != INT32_MAX && reverseRes.distance[j] != INT32_MAX) {
      if (res.distance[j] + reverseRes.distance[j] == res.distance[D]) {
        int node = j;
        while (node != S) {
          removedAdj[res.parents[node]][node] = 1;
          node = res.parents[node];
        }
        node = j;
        while (node != D) {
          removedAdj[node][reverseRes.parents[node]] = 1;
          node = reverseRes.parents[node];
        }
      }
    }

  }
  res = Djkstra(S, rightAdj);
  cout << (res.distance[D] == INT32_MAX ? -1 : res.distance[D]) << endl;
}
return 0;
}