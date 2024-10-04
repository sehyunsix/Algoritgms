#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>

int N, M, T;
int prev_list[51][51];
int next_list[51][51];
bool next_removed[51][51] = { false, };
bool visited[51][51] = { false, };
bool removed[51][51] = { false, };
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

using namespace std;

void turn(int x, int k, int d) {
  int tmp = 0;
  // cout << "debug k " << k << endl;
  for (int i = 1; i < N + 1; i++) {

    for (int j = 1; j < M + 1;j++) {
      if (i % x == 0) {
        int next_index = (j + k * d) % M;
        if (next_index <= 0) {
          next_index += M;
        }
        next_list[i][next_index] = prev_list[i][j];
        next_removed[i][next_index] = removed[i][j];

      }
      else {
        next_list[i][j] = prev_list[i][j];
        next_removed[i][j] = removed[i][j];
      }
    }
  }

  // cout << "===turn before ====" << endl;
  // for (int i = 1; i < N + 1; i++) {
  //   for (int j = 1; j < M + 1;j++) {
  //     cout << prev_list[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  // cout << "===end====" << endl;
  // cout << "===turn init ====" << endl;
  // for (int i = 1; i < N + 1; i++) {
  //   for (int j = 1; j < M + 1;j++) {
  //     cout << next_list[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  // cout << "===end====" << endl;


}



int dfs(int x, int y, int depth) {
  visited[x][y] = true;
  next_removed[x][y] = true;
  bool removable = false;
  // cout << "============== dfs" << endl;
  // cout << x << " " << y << endl;
  for (int i = 0; i < 4; i++) {
    int next_x = (x + dir[i][0]);
    int next_y = (y + dir[i][1]) % M;
    if (next_y <= 0) {
      next_y += M;
    }

    if (!visited[next_x][next_y] && !next_removed[next_x][next_y] && next_list[x][y] == next_list[next_x][next_y] && next_x > 0) {
      removable = true;
      // cout << "next " << next_x << " " << next_y << endl;
      dfs(next_x, next_y, depth + 1);

    }
  }

  if (depth == 0 && removable == false) {
    next_removed[x][y] = false;
    return 0;
  }
  return 1;

}

void update() {
  int find = 0;
  int sum = 0;
  int count = 0;
  for (int i = 1; i < N + 1; i++) {
    for (int j = 1; j < M + 1;j++) {
      if (!next_removed[i][j]) {
        find += dfs(i, j, 0);
        sum += next_list[i][j];
        count += 1;
      }
    }
  }

  // cout << "===removed check ====" << endl;
  // for (int i = 1; i < N + 1; i++) {
  //   for (int j = 1; j < M + 1;j++) {
  //     cout << next_removed[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  // cout << "===end====" << endl;

  // cout << "===update before ==== " << endl;
  // for (int i = 1; i < N + 1; i++) {
  //   for (int j = 1; j < M + 1;j++) {
  //     cout << next_list[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  // cout << "===end====" << endl;
  double avg = sum * 1.0 / count;
  if (find == 0) {
    for (int i = 1; i < N + 1; i++) {
      for (int j = 1; j < M + 1;j++) {
        if (!next_removed[i][j]) {
          if (next_list[i][j] < avg) {
            next_list[i][j] += 1;
          }
          else if (next_list[i][j] > avg) {
            next_list[i][j] -= 1;
          }

        }
      }
    }

    // cout << "===update check ==== " << "avg " << avg << "sum" << sum << "count " << count << endl;
    // for (int i = 1; i < N + 1; i++) {
    //   for (int j = 1; j < M + 1;j++) {
    //     cout << next_list[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    // cout << "===end====" << endl;

  }
}

void init() {

  for (int i = 1; i < N + 1; i++) {
    for (int j = 1; j < M + 1;j++) {
      visited[i][j] = false;
      prev_list[i][j] = next_list[i][j];
      removed[i][j] = next_removed[i][j];
    }
  }
}

int main() {

  cin >> N >> M >> T;

  for (int i = 1; i < N + 1;i++) {
    for (int j = 1; j < M + 1;j++) {
      cin >> prev_list[i][j];
    }
  }

  for (int i = 0; i < T;i++) {
    int x, d, k;
    cin >> x >> d >> k;
    if (d == 0) {
      turn(x, k, 1);

    }
    else {
      turn(x, k, -1);
    }
    update();
    init();
  }

  int res = 0;

  for (int i = 1; i < N + 1; i++) {
    for (int j = 1; j < M + 1;j++) {
      if (!next_removed[i][j]) {
        res += next_list[i][j];
      }
    }
  }

  cout << res;

}