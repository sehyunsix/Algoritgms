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
vector<int> levels;
vector<int> parents;

void dfs(int node, int level) {
  levels[node] = level;
  for (int c : childNodes[node]) {
    if (parents[c] == -1) {
      parents[c] = node;
      dfs(c, level + 1);
    }
    }
  return;
};

int N;
int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
cin >> N;
childNodes.resize(N + 1);
levels = vector<int>(N+1 , 0);
parents = vector<int>(N + 1, -1);

for (int i = 0; i < N-1; i++) {
  int x, y;
  cin >> x >> y;
  childNodes[x].push_back(y);
  childNodes[y].push_back(x);
}

parents[1] = 0;
dfs(1, 0);

int M;
cin >> M;
for( int j =0 ; j<M ;j++){
  int a, b;
  cin >> a >> b;
  while (a != b) {
    if (levels[a] <= levels[b]) b = parents[b];
    if (levels[a] > levels[b]) a = parents[a];
  }
  cout <<a << endl;
}


return 0;
}