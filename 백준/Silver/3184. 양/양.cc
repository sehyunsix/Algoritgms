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
  char m[251][251];
  bool visited[251][251];
  int N, M;
  int wolf_count, sheep_count;
  int dxdy[4][2] = {
    {1,0},
    {-1,0},
    {0, 1},
    {0, -1},
  };
  int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> m[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {

      if (m[i][j] == '#' && !visited[i][j]) {
        queue<pair<int, int>> q;
        q.push({ i,j });
        visited[i][j] = 1;
        int tmp_wolf_count = 0;
        int tmp_sheep_count = 0;
        if (m[i][j] == 'o') tmp_sheep_count++;
        if (m[i][j] == 'v') tmp_wolf_count++;
        while (!q.empty()) {
          pair<int, int> curr = q.front();
          q.pop();
          for (int i = 0; i < 4;i++) {
            pair<int, int> next = { curr.first + dxdy[i][0], curr.second + dxdy[i][1] };
            if (next.first < 0 || next.first >= N || next.second < 0 || next.second >= M || m[next.first][next.second] == '#' || visited[next.first][next.second]) { continue; }
            q.push(next);
            visited[next.first][next.second] = 1;
            if (m[next.first][next.second] == 'o') tmp_sheep_count++;
            if (m[next.first][next.second] == 'v') tmp_wolf_count++;
          }
        }
        if (tmp_sheep_count > tmp_wolf_count) {
          sheep_count += tmp_sheep_count;
        }
        else {
          wolf_count += tmp_wolf_count;
        }
      }
    }
  }

  cout << sheep_count << " " << wolf_count << endl;

  return 0;
  }