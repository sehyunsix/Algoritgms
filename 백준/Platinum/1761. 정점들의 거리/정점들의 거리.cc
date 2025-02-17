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
int N, LOGN;

int LOG(int x) {
  int res = 0;
  while (x > 1) {
    x = x >> 1;
    res++;
  }
  return res;
}

vector<vector<pair<int, int>>> childs;
vector<vector<pair<int,int>>> parents;
vector<int> levels;



void dfs(int node, int level) {
  for (pair<int,int> c : childs[node]) {
    if (levels[c.first] == 0) {
      levels[c.first] = level + 1;
      parents[c.first][0] = { node ,c.second };
      dfs(c.first, level + 1);
    }
  }
}


int lca(int a, int b) {
  int res = 0;

  if (levels[a] < levels[b]) {
    swap(a, b);
  }

  while (levels[a] != levels[b]) {

    int diff = levels[a] - levels[b];
    res += parents[a][LOG(diff)].second;
    a = parents[a][LOG(diff)].first;
  }


  if (a == b) return res;

  for (int i = LOGN; i > -1; i--) {
    if (parents[a][i].first != parents[b][i].first) {
      res += parents[a][i].second + parents[b][i].second;
      a = parents[a][i].first;
      b = parents[b][i].first;
    }
  }
  res += parents[a][0].second + parents[b][0].second;

  return res;

}
int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);

cin >> N;
LOGN = LOG(N);

childs.resize(N + 1);
parents =vector<vector<pair<int,int>>>(N + 1 ,vector<pair<int,int>>(LOGN+1));
levels = vector<int>(N + 1, 0);

for (int i = 0; i < N-1; i++) {
  int x, y, w;
  cin >> x >> y >> w;
  childs[x].push_back({ y,w });
  childs[y].push_back({ x,w });
}

levels[1] = 1;
dfs(1, 1);

for (int j = 1; j <= LOGN; j++) {
  for (int i = 1; i < N + 1; i++) {
    parents[i][j].first = parents[parents[i][j - 1].first][j - 1].first;
    parents[i][j].second = parents[i][j - 1].second + parents[parents[i][j - 1].first][j-1].second;
  }
}

int M;
cin >> M;
for (int i = 0; i < M; i++) {
  int a, b;
  cin >> a >> b;
  cout << lca(a, b) << endl;
}


return 0;
}