  #include<iostream>
  #include<algorithm>
  #include<vector>
  #include<memory.h>
  #include<queue>
  #include <string>
  #include<math.h>
  #include<map>
  #include<stack>
  #define ll long long
  #define P 1000000007
  #define endl "\n"
  using namespace std;
  int cost[201];
  vector<int> adj[201];
  stack<int> s;
  vector<vector<int>> scc;
  int labels[201];
  bool finished[201];
  int label=1;

  int dfs(int u) {
    labels[u] = label++;
    s.push(u);
    int parent = labels[u];
    for (int v: adj[u]) {
      if (labels[v] != 0 && !finished[v]) {
        parent = min(parent, labels[v]);
      }
      else if(!finished[v]){
        parent = min(parent, dfs(v));
      }
    }

    if (parent == labels[u]) {
      vector<int> tmp;
      tmp.push_back(u);
      finished[u] = 1;
      while (!s.empty() && parent != labels[s.top()]) {
        tmp.push_back(s.top());
        finished[s.top()] = 1;
        s.pop();
      }
      s.pop();
      scc.push_back(tmp);
    }
    return parent;
  }

  int N;
  int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> N;
  for(int i= 0; i<N;i++){
    cin >> cost[i+1];
  }

  for(int i=0; i < N;i++){
    for(int j=0; j< N; j++){
      char tmp;
      cin >> tmp;
      if(tmp =='1') adj[i+1].push_back(j+1);
    }
  }

  for( int j =0 ; j<N ;j++){
    if (!finished[j + 1])
      {
        memset(labels, 0, sizeof(labels));
        label = 1;
        dfs(j + 1);
      }
    }

  ll ans = 0;
  for (auto v : scc) {

    int tmp = INT32_MAX;
    // cout << "cc : ";
    for (auto e : v) {
      // cout << e << " ";
      tmp = min(cost[e], tmp);
    }
    // cout << endl;
    ans += tmp;
  }
  cout << ans << endl;
  return 0;
  }
