#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_N = 1000001;
vector<int> tree[MAX_N];
int dp[MAX_N][2];  // dp[u][0]: 얼리 아답터 X, dp[u][1]: 얼리 아답터 O
bool visited[MAX_N];

// DFS + DP
void dfs(int node) {
    visited[node] = true;
    dp[node][0] = 0;  // 얼리 아답터 X
    dp[node][1] = 1;  // 얼리 아답터 O

    for (int child : tree[node]) {
        if (!visited[child]) {
            dfs(child);
            dp[node][0] += dp[child][1];  // 자식이 얼리 아답터여야 함
            dp[node][1] += min(dp[child][0], dp[child][1]);  // 자식이 얼리 아답터일 수도 있고 아닐 수도 있음
        }
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    memset(dp, -1, sizeof(dp));
    memset(visited, false, sizeof(visited));

    dfs(1);  // 1번 노드를 루트로 가정

    cout << min(dp[1][0], dp[1][1]) << endl;
    return 0;
}
