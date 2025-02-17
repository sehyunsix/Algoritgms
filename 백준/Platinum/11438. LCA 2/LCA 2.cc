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
int N , LOGN;
vector<vector<int>> childNodes;
vector<int> levels;
vector<vector<int>> parents;

int LOG(int n) {
  int res = 0;
  while (n > 1) {
    n = n >> 1;
    res++;
  }
  return res;
}

void dfs(int node, int level) {

  for (int c : childNodes[node]) {
    if (levels[c] == 0) {
        levels[c] = level+1;
        parents[c][0] = node;
        dfs(c, level + 1);
      }
    }
  return;
};

int lca(int a, int b) {
  if (levels[a] < levels[b]) {
    swap(a, b);
  }

  while (levels[a] != levels[b]) {
    int diff = levels[a] - levels[b];
    a = parents[a][LOG(diff)];
  }

  if (a == b) return a;

  for (int i = LOGN; i > -1; i--) {
    if (parents[a][i] != parents[b][i]) {
      a = parents[a][i];
      b = parents[b][i];
    }
  }

  return parents[a][0];
}


  int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> N;
  LOGN = LOG(N);

  childNodes.resize(N + 1);
  levels = vector<int>(N+1 , 0);
  parents = vector<vector<int>>(N + 1, vector<int>(LOGN+1, 0));

  for (int i = 0; i < N-1; i++) {
    int x, y;
    cin >> x >> y;
    childNodes[x].push_back(y);
    childNodes[y].push_back(x);
  }

  parents[1][0] = 0;
  levels[1] = 1;
  dfs(1, 1);


  for (int j = 1; j <= LOGN; j++) {
    for (int i = 1; i < N + 1;i++) {
      parents[i][j] = parents[parents[i][j - 1]][j - 1];
    }
  }

  int M;
  cin >> M;
  for( int j =0 ; j<M ;j++){
    int a, b;
    cin >> a >> b;
    cout <<lca(a,b) << endl;
  }

  return 0;
  }