#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<queue>
#include <string>
#include<math.h>
#define MAX 17
#define INF 987654321
#define ll long long
#define P 1000000007
#define endl "\n"
using namespace std;

int N, Answer_bit;
int m[MAX][MAX];
int c[MAX][1 << MAX];

int DFS(int c_n, int c_b) {
  // cout << c_n << endl;
  if (c_b == Answer_bit) {
    if (m[c_n][0] == 0) { return INF; }
    else { return m[c_n][0]; }
  }
  if (c[c_n][c_b] != -1) {
    return c[c_n][c_b];
  }
  c[c_n][c_b] = INF;
  for( int i =0 ; i<N; i++){
    if (m[c_n][i] == 0) {
      continue;
    }
    if ((c_b & (1 << i)) == (1 << i)) {
      continue;
    }
    c[c_n][c_b] = min(c[c_n][c_b], m[c_n][i] + DFS(i, c_b | 1<< i));
  }
  return c[c_n][c_b];
}

int main() {

  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  for( int i =0 ; i<N; i++){
    for( int j =0 ; j< N;j++){
      cin >> m[i][j];
    }
  }
  Answer_bit = (1 << N) - 1;
  for( int i =0 ; i<MAX; i++){
    for( int j =0 ; j<(1<<MAX) ;j++){
      c[i][j] = -1;
    }
  }
  cout << DFS(0, 1) << endl;

  return 0;
}