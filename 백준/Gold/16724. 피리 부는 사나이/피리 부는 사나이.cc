#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<queue>
#include <string>
#include<math.h>
#define ll long long
#define P 1000000007
using namespace std;

char m[1000][1000];
int visited[1000][1000];

pair<int, int> get_next(int i, int j, char c) {
  pair<int, int> next;
  if (c == 'D') {
    next = { i + 1, j };
  }
  else if (c == 'U') {
    next = { i - 1, j };
  }
  else if (c == 'R') {
    next = { i, j + 1 };
  }
  else if (c == 'L') {
    next = { i, j - 1 };

  }
  return next;
}
  int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);

int N, M;
cin >> N >> M;
for( int i =0 ; i<N; i++){
  for( int j =0 ; j<M ;j++){
    cin >> m[i][j];
  }
}


int ans = 0;
int rp_chk = 1;

for( int i =0 ; i<N; i++){
  for( int j=0 ; j<M; j++){
    if (visited[i][j]==0) {
      visited[i][j] = rp_chk;
      pair<int, int> next = get_next(i, j, m[i][j]);
      // cout << next.first << " " << next.second << " " <<ans << endl;
      while (!visited[next.first][next.second]) {
        visited[next.first][next.second] = rp_chk;
        next = get_next(next.first, next.second, m[next.first][next.second]);
      }
      if (visited[next.first][next.second] == rp_chk) {
        ans += 1;
      }
      rp_chk += 1;
      // for (int i = 0; i < N; i++) {
      //   for (int j = 0; j < M;j++) {
      //     cout << visited[i][j];
      //   }
      //   cout << endl;
      // }
    }


  }
}

cout << ans;


return 0;
}