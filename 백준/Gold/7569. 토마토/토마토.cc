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

typedef struct Pos {
  int x;
  int y;
  int z;
}Pos;

typedef struct Info {
    Pos pos;
    int time;
}Info;

int N, M ,H;
  int m[101][101][101];
  bool visited[101][101][101];
  int dxdy[6][3]{
    {-1,0,0},
    {1,0,0},
    {0,-1,0},
    {0, 1,0},
    {0,0,-1},
    {0,0,1}
  };
  int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> M>> N >>H;

  for (int h = 0; h < H;h++) {
    for (int i = 0; i < N;i++) {
      for (int j = 0; j < M;j++) {
        cin >> m[i][j][h];
      }
    }
  }

  queue<Info> q;

  for (int h = 0; h < H;h++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (m[i][j][h] == 1)
        {
          // cout << "start" << i << " " << j << endl;
          visited[i][j][h] = 1;
          q.push({ { i,j,h}, 0 });
        }
      }
    }
  }

    Info curr;
    Info next;
    while (!q.empty()) {
      curr = q.front();
      // cout << curr.pos.first << " " << curr.pos.second << endl;
      q.pop();
      for (int i = 0;i < 6;i++) {
        next.pos = { curr.pos.x + dxdy[i][0], curr.pos.y + dxdy[i][1],curr.pos.z + dxdy[i][2] };
        next.time = curr.time + 1;
        if (next.pos.x < 0 || next.pos.x >= N || next.pos.y < 0 || next.pos.y >= M || next.pos.z < 0 || next.pos.z >= H) {
          continue;
        }
        if (m[next.pos.x][next.pos.y][next.pos.z] == -1) {
          continue;
        }
        if (visited[next.pos.x][next.pos.y][next.pos.z]) {
          continue;
        }
        q.push(next);
        visited[next.pos.x][next.pos.y][next.pos.z] = 1;
      }
    }

    for (int h = 0; h < H;h++) {
      for (int i = 0; i < N;i++) {
        for (int j = 0; j < M; j++) {

          if (visited[i][j][h] == 0 && m[i][j][h] == 0) {
            cout << -1 << endl;
            return 0;
          }
        }
      }
    }

    cout << curr.time << endl;

  return 0;
  }