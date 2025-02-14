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
vector<vector<pair<int, double>>> adj;
vector<pair<double, double>> vertex;
int n;

typedef struct cmpCost {

  bool operator()(pair<int, double> a, pair<int, double> b) {
    return a.second > b.second;
  }
}cmpCost;

double dijkstra(int st, int en) {
  vector<double> cost(n + 2, INT32_MAX);
  priority_queue<pair<int, double>, vector<pair<int, double>>, cmpCost> q;
  cost[0] = 0;
  q.push({ 0,0 });
  while (!q.empty()) {
    pair<int, double> curr = q.top();
    q.pop();
    if (cost[curr.first] < curr.second) continue;
    for (pair<int, double> next : adj[curr.first]) {
      if (cost[next.first] <= curr.second + next.second) continue;
        cost[next.first] = curr.second + next.second;
      q.push({ next.first ,curr.second + next.second });
    }
  }

  return cost[en];
}

double calCost(int i, int j) {

  double distance = sqrt(pow(vertex[i].first - vertex[j].first, 2) + pow(vertex[i].second - vertex[j].second, 2));
  if (distance >= 50)  return (distance - 50) / 5 + 2;
  else return min((50 - distance) / 5 + 2, distance / 5);
}

double calDefaultCost(int i, int j) {
  double distance = sqrt(pow(vertex[i].first - vertex[j].first, 2) + pow(vertex[i].second - vertex[j].second, 2));
  return distance / 5;
}

int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);


  for (int i = 0; i < 2;i++) {
    double x, y;
    cin >> x >> y;
    vertex.push_back({ x,y });
  }
  cin >> n;

    for (int i = 0; i < n;i++) {
    double x, y;
    cin >> x >> y;
    vertex.push_back({ x,y });
  }

    adj.resize(n + 2);

    for (int i = 0; i < n + 2; i++) {
      adj[1].push_back({ i,calDefaultCost(1, i) });
      if (i == 0)continue;
      adj[i].push_back({ 1,calCost(i,1) });
    }

    for (int i = 1; i < n + 2; i++) {
      adj[0].push_back({ i,calDefaultCost(0, i) });
      if (i == 1) continue;
      adj[i].push_back({ 0,calCost(i,0) });
    }

  for (int i = 2; i < n + 1;i++) {
    for (int j = i + 1; j < n+2; j++) {
      double cost = calCost(i,j);
      adj[i].push_back({ j, cost });
      adj[j].push_back({ i, cost });
    }
  }

  cout << dijkstra(0, 1) << endl;


return 0;
}