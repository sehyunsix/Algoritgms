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
vector<vector<int>> edge_list;
vector<int> parent;
void dfs(int node) {
  for (int c : edge_list[node]) {
    if (parent[c] == -1) {
      parent[c] = node;
      dfs(c);
    }
  }
  return;

}


int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
int N;
cin >> N;
edge_list = vector<vector<int>> (N + 1, vector<int>());
parent = vector<int>(N + 1, -1);
for (int i = 0; i < N-1;i++) {
  int t1, t2;
  cin >> t1 >> t2;
  edge_list[t1].push_back(t2);
  edge_list[t2].push_back(t1);
}

parent[1] = 0;
dfs(1);
for (int i = 2; i <= N; i++) {
  cout << parent[i] << endl;
}


return 0;
}