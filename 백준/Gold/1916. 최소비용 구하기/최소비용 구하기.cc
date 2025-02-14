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

int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
cin >> N >> M;

adj.resize(N + 1);
cost = vector<int>(N + 1, INT32_MAX);
visited = vector<bool>(N + 1, 0);

for (int i = 0; i < M;i++) {
  int x, y, c;
  cin >> x >> y >> c;
  adj[x].push_back({ y,c });
}

int s, t;
cin >> s >> t;
priority_queue<pair<int, int>, vector<pair<int, int>>, cmpCost> q;
q.push({ s, 0 });
while(!q.empty()){
  pair<int, int> curr = q.top();
  q.pop();
  if (visited[curr.first])  continue;
  cost[curr.first] = curr.second;
  visited[curr.first] = true;
  for (pair<int, int> next : adj[curr.first]) {
    if (visited[next.first])  continue;
    q.push({ next.first, cost[curr.first] + next.second});
  }
}

// for( int j =1 ; j<N+1 ;j++){
//   cout << cost[j] << " ";
// }
// cout << endl;
cout << cost[t] << endl;




return 0;
}