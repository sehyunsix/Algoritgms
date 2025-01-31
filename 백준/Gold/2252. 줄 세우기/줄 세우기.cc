#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<queue>
#include <string>
#include<math.h>
#define ll long long
#define P 1000000007
#define endl "\n"
using namespace std;
int N,M;
vector<int> edge_list[32001];
vector<int> parent_list[32001];
bool visited_list[32001];

void dfs(int node ){

  visited_list[node] = true;
  for (int e : parent_list[node]) {
    if(!visited_list[e]){
      dfs(e);
    }
  }
  cout << node <<" ";
}


int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);


cin >> N >> M;

for (int i = 0; i < M; i++) {
  int p, c;
  cin >> p >> c;
  edge_list[p].push_back(c);
  parent_list[c].push_back(p);
}

for (int i = 1; i < N+1; i++) {
  if (!visited_list[i]) {
      dfs(i);
  }
}



return 0;
}