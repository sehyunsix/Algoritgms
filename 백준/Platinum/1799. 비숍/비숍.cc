#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<queue>
#include<string>
#include<math.h>
#define ll long long
#define P 1000000007
#define endl "\n"
using namespace std;

int N, b_sol,w_sol;
int s[10][10];
int b[10][10];
bool m[10][10];

void update(int r, int c) {
  for (int i = 0; i <N;i++) {
    for( int j =0 ; j<N ;j++){
      if (abs(r - i) == abs(c-j)) {
        m[i][j] = 0;
      }
    }
  }
}


bool dfs(int idx, int depth, int& sol) {
  // cout << depth << endl;
  if (sol < depth) {
    sol = max(sol, depth);
    for( int i =0 ; i<N; i++){
      for( int j =0 ; j<N ;j++){
        s[i][j] = b[i][j];
      }
    }
  }




  // cout << "depth " << depth << " new " << s_r << " " << s_c << " map" << endl;
  // for (int i = 0; i < N; i++) {
  //   for (int j = 0; j < N;j++) {
  //     cout << m[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  if (depth ==N-1 && depth != 0) {
    return 1;
  }

  bool tmp[10][10];
  for( int i =0 ; i<N ;i++){
    for( int j =0 ; j<N ;j++){
      tmp[i][j] = m[i][j];
    }
  }

  int i, j;

  if (N % 2 == 1) {
    for (int n = idx; n < N * N; n += 2) {
      i = n / N;
      j = n % N;
      // cout << n << endl;
      if (m[i][j]) {
        b[i][j] = depth + 1;
        update(i, j);
        if (dfs(n + 2, depth + 1, sol)) {
          return 1;
        }
        b[i][j] = 0;
        for (int k = 0; k < N;k++) {
          for (int l = 0; l < N;l++) {
            m[k][l] = tmp[k][l];
          }
        }
      }
    }
  }
  else {
    int g =0;
    for (int n = idx; n < N * N; n += 2+g) {

      g = 0;
      if ( n % N == N - 2) {
        g = 1;
      }
      if (n % N == N - 1) {
        g = -1;
      }



      i = n / N;
      j = n % N;


      // cout << n << endl;
      if (m[i][j]) {
        b[i][j] = depth + 1;
        update(i, j);

        if (dfs(n + g+ 2, depth + 1, sol)) {
          return 1;
        }
        b[i][j] = 0;
        for (int k = 0; k < N;k++) {
          for (int l = 0; l < N;l++) {
            m[k][l] = tmp[k][l];
          }
        }
      }
    }

    if (j == N - 1) {

    }

  }
  // cout << "error " << endl;
  return 0;
}


int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);


cin >> N;

for (int i = 0; i <N; i++) {
  for( int j =0 ; j<N ;j++){
    cin >> m[i][j];
  }
}

bool tmp[10][10];
for (int i = 0; i < N;i++) {
  for (int j = 0; j < N;j++) {
    tmp[i][j] = m[i][j];
  }
}

dfs(0, 0, w_sol);

for (int i = 0; i < N;i++) {
  for (int j = 0; j < N;j++) {
    m[i][j] = tmp[i][j];
  }
}
// cout << "===========dfs end===========" << endl;

dfs(1, 0, b_sol);


// cout << w_sol << endl;
// cout << b_sol << endl;
//  for (int i = 0; i < N; i++) {
//     for (int j = 0; j < N;j++) {
//       cout << s[i][j] << " ";
//     }
//     cout << endl;
//   }

cout << w_sol + b_sol << endl;

return 0;
}