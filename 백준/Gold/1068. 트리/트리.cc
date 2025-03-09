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
bool removed[51];
int ans;
void dfs(int u) {
  // cout << u << endl;
  if (adj[u].size() == 0) {
    ans++;
  }
  for (int v : adj[u]) {
    if (!removed[v]) {
      dfs(v);
    }
    else {
      if (adj[u].size() == 1)  ans++;
    }
  }
}

int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);

int N,root;
cin >> N;
for (int i = 0;i < N; i++) {
  int tmp;
  cin >> tmp;
  if (tmp >= 0) {
    adj[tmp].push_back(i);
  }
  else {
    root = i;
  }
}


int remove;
cin >> remove;
removed[remove] = 1;
if(!removed[root]) dfs(root);
cout << ans << endl;
return 0;
}