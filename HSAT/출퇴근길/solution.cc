#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 200001;
vector<int> graph[MAX];
vector<int> rev_graph[MAX];
bool visited_s[MAX];
bool visited_rs[MAX];
bool visited_t[MAX];
bool visited_rt[MAX];

void bfs_from_s(int s, int t) {
    queue<int> q;
    q.push(s);
    visited_s[s] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int next : graph[curr]) {
            if (!visited_s[next] && next != t) {
                visited_s[next] = true;
                q.push(next);
            }
        }
    }
}

void bfs_from_rs(int s, int t) {
    queue<int> q;
    q.push(s);
    visited_rs[s] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int next : rev_graph[curr]) {
            if (!visited_rs[next] ) {
                visited_rs[next] = true;
                q.push(next);
            }
        }
    }
}


void bfs_from_t(int s, int t) {
    queue<int> q;
    q.push(t);
    visited_t[t] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int next : graph[curr]) {
            if (!visited_t[next] && next != s ) {
                visited_t[next] = true;
                q.push(next);
            }
        }
    }
}

void bfs_from_rt(int s, int t) {
    queue<int> q;
    q.push(t);
    visited_rt[t] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int next : rev_graph[curr]) {
            if (!visited_rt[next] ) {
                visited_rt[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // 양방향 그래프 구성
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        rev_graph[y].push_back(x);
    }

    int s, t;
    cin >> s >> t;

    bfs_from_s(s, t);
    bfs_from_rs(s, t);
    bfs_from_t(s, t);
    bfs_from_rt(s, t);



    // 두 방문 배열을 비교하여 결과 계산
    int result = 0;
    for (int i = 1; i <= n; i++) {
        if (i != s && i != t && visited_s[i] && visited_t[i]  && visited_rs[i] && visited_rt[i]) {
            result++;
        }
    }

    cout << result << "\n";
    return 0;
}