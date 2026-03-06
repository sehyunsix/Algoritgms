#include <bits/stdc++.h>
using namespace std;

struct Shark {
    int s, v, iq;
};

int N;
vector<Shark> sharks;
vector<vector<int>> adj;
vector<int> matchTo;
vector<bool> visited;

bool canEat(int i, int j) {
    if (i == j) return false;

    const auto &a = sharks[i];
    const auto &b = sharks[j];

    if (a.s >= b.s && a.v >= b.v && a.iq >= b.iq) {
        // If completely equal, only smaller index can eat larger index
        if (a.s == b.s && a.v == b.v && a.iq == b.iq && i > j) return false;
        return true;
    }
    return false;
}

bool dfs(int u) {
    for (int v : adj[u]) {
        if (visited[v]) continue;
        visited[v] = true;

        if (matchTo[v] == -1 || dfs(matchTo[v])) {
            matchTo[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    sharks.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> sharks[i].s >> sharks[i].v >> sharks[i].iq;
    }

    adj.assign(N, {});
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (canEat(i, j)) {
                adj[i].push_back(j);
            }
        }
    }

    matchTo.assign(N, -1);
    int eaten = 0;

    // Each shark can eat up to 2 sharks
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < 2; k++) {
            visited.assign(N, false);
            if (dfs(i)) eaten++;
        }
    }

    cout << N - eaten << '\n';
    return 0;
}