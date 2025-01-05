#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<queue>
#define ll long long
using namespace std;
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);


struct pair_hash {
  template <class T1, class T2>
  std::size_t operator()(const std::pair<T1, T2>& p) const {
    return std::hash<T1>()(p.first) ^ std::hash<T2>()(p.second);
  }
};

vector<int> edge_list[200001];
bool ans[200001];
bool visited[200001];
int N;

void dfs(int s ,int level) {
  visited[s] = true;
  for (int e : edge_list[s]) {
    if (!visited[e]) {
      ans[e] =(N-1 -level )% 2;  // 필요한 간선만 추가
      dfs(e ,level+1);
    }
  }
  return;
}

int main() {
  fastio();
  cin >> N;

  for (int i = 0; i < N - 1; i++) {
    int p, n;
    cin >> p >> n;
    edge_list[p].push_back(n);
    edge_list[n].push_back(p);
  }

  dfs(0,-1);

  for (int i = N - 1; i >= 1; i--) {
    cout << ans[i];
  }
  return 0;
}
