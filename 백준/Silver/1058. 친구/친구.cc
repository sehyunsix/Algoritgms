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

vector<int> adj[51];
vector<bool> visited;

void dfs(int node, int level) {
  if (level == 2) {
    return;
  }
  for (int child : adj[node]) {
      visited[child] = true;
      dfs(child, level + 1);
  }
  return;
}

int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
int N;
cin >> N;

for (int i = 0; i < N;i++) {
  string row;
  cin >> row;
  for (int j = 0; j < N;j++) {
    if (row[j] == 'Y') {
      adj[i].push_back(j);
      adj[j].push_back(i);
    }
  }
}

int ans = 0;
for (int i = 0; i < N; i++) {
  int cntFriends = 0;
  visited = vector<bool>(N, 0);
  visited[i] = true;
  dfs(i, 0);
  for( int j =0 ; j<N ;j++){
    cntFriends += visited[j];
  }
  ans = max(ans, cntFriends-1);

}

cout << ans << endl;
return 0;
}