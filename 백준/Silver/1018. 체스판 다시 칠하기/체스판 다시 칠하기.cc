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
int N, M;
bool board[50][50];
bool w_board[8][8] = {
{1,0,1,0,1,0,1,0},
{0,1,0,1,0,1,0,1},
{1,0,1,0,1,0,1,0},
{0,1,0,1,0,1,0,1},
{1,0,1,0,1,0,1,0},
{0,1,0,1,0,1,0,1},
{1,0,1,0,1,0,1,0},
{0,1,0,1,0,1,0,1},
};

bool b_board[8][8] = {
{0,1,0,1,0,1,0,1},
{1,0,1,0,1,0,1,0},
{0,1,0,1,0,1,0,1},
{1,0,1,0,1,0,1,0},
{0,1,0,1,0,1,0,1},
{1,0,1,0,1,0,1,0},
{0,1,0,1,0,1,0,1},
{1,0,1,0,1,0,1,0},
};



int find_min(int r, int c) {

  int w_c = 0;
  int b_c = 0;
  for (int i = 0; i < 8;i++) {
    for (int j = 0; j < 8;j++) {
      if (board[r + i][c + j] != b_board[i][j]) {
        b_c++;
      }
      if (board[r + i][c + j] != w_board[i][j]) {
        w_c++;
      }
    }
  }

  return min(w_c, b_c);

}
int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
cin >> N >> M;

for (int i = 0; i < N;i++) {
  for (int j = 0; j < M; j++) {
    char tmp;
    cin >> tmp;
    board[i][j] = (tmp == 'W') ? 1 : 0;
  }
}

int min = INT32_MAX;
for (int i = 0; i < N - 7;i++) {
  for (int j = 0; j < M - 7;j++) {
    int res = find_min(i, j);
    if (min >= res) {
      min = res;
    }
  }
}

cout << min << endl;

return 0;
}