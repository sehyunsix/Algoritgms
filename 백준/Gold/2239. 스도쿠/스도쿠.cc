#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<queue>
#include <string>
#include<math.h>
#define ll long long
#define P 1000000007
#define INF 987654321
#define endl "\n"
using namespace std;
int m[9][9];
bool check_board[9][9][10];

int count_zero(bool a[10]){
  int res = 0;
  for( int j =1 ; j<10 ;j++){
    if (a[j] == 1) {
      res += 1;
    }
  }
  return res;
}



void reverse(int r, int c, int a) {

  // cout << "update " << r << " " << c << endl;
  int s_r, s_c;
  s_r = r / 3;
  s_c = c / 3;

  m[r][c] = 0;
  for (int i = 0; i < 9;i++) {

    if (i != c) {
      check_board[r][i][a] = 0;
    }
    if(i !=r){
    check_board[i][c][a] = 0;
    }

  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (s_r + i != r && s_c + j != c) {
        check_board[s_r + i][s_c + j][a] = 0;
      }
        }
    }

}
vector<pair<int,int>> update(int r, int c, int a) {

  // cout << "update " << r << " " << c << endl;
  vector<pair<int, int>> res;
  int s_r, s_c;
  s_r = (r / 3)*3;
  s_c = (c / 3)*3;

  m[r][c] = a;
  for (int i = 0; i < 9;i++) {

    if (i != c) {
      if (check_board[r][i][a] == 0) {
        res.push_back({ r,i });
      }
      check_board[r][i][a] = 1;

    }
    if (i != r) {
      if (check_board[i][c][a] == 0) {
        res.push_back({ i,c });
      }
      check_board[i][c][a] = 1;
    }

  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (((s_r + i) != r) && ((s_c + j) != c)) {
        if (check_board[s_r + i][s_c + j][a] == 0) {
          res.push_back({ s_r + i,s_c + j });
        }
        check_board[s_r + i][s_c + j][a] = 1;
      }
    }
  }

  return res;

}


int dfs(int depth) {

  if (depth == 81) {
    return 1;
  }
  // cout << "==========check========= " << endl;
  // for (int i = 0; i < 9; i++) {
  //   for (int j = 0; j < 9;j++) {
  //     cout << m[i][j];
  //   }
  //   cout << endl;
  // }
  // cout << "==========chk_board========= " << endl;
  // for (int i = 0; i < 9; i++) {
  //   for (int j = 0; j < 9;j++) {
  //     cout << check_board[i][j][8];
  //   }
  //   cout << endl;
  // }
  // cout << depth << endl;

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9;j++) {
      if (m[i][j] == 0) {
        for (int k = 0; k < 9;k++) {
          if (!check_board[i][j][k + 1]) {
            vector<pair<int, int>> res = update(i, j, k + 1);
            if (dfs(depth + 1)) {
              return 1;
            }
            check_board[i][j][k + 1] = 0;
            for (auto p : res) {
              // cout << p.first << " " << p.second <<" " << k+1<< endl;
              check_board[p.first][p.second][k + 1] = 0;
            }
            // reverse(i, j, k + 1);
            m[i][j] = 0;
          }
        }
        return 0;

      }
      }
  }


  return 0;
}

int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);

int depth = 0;
for (int i = 0; i < 9; i++) {
  for( int j =0 ; j < 9 ;j++){
    char tmp;
    cin >> tmp;
    int num = tmp - 48;
    if (num > 0) {
      update(i, j, num);
      depth += 1;
    }
  }
}

// cout << "test === " << endl;
// for (int i = 0; i < 9; i++) {
//   for (int j = 0; j < 9;j++) {
//     cout << m[i][j]<<endl;

//   }
//   cout << endl;
// }

// cout << "dfs start" << endl;
dfs(depth);

for( int i =0 ; i<9; i++){
  for( int j =0 ; j<9 ;j++){
    cout << m[i][j];
  }
  cout << endl;
}


return 0;
}