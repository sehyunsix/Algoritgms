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
int N, M, K;
bool colBroked[201][201];
bool rowBroked[201][201];
ll dp[201][201];
int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
cin >> N >> M >> K;
for( int j =0 ; j<K ;j++){
  int r1, c1, r2, c2;
  cin >> r1 >> c1 >> r2 >> c2;
  if(r1 == r2){
    if (c1 > c2) swap(c1, c2);
    rowBroked[r1][c1]=1;
  }
  if (c1 == c2) {
    if (r1 > r2) swap(r1, r2);
    colBroked[r1][c1]=1;
  }
}

dp[0][0] = 1;
for (int i = 0; i <=N; i++) {
  for( int j =0 ; j<=M ;j++){
    if(i-1>=0 && !colBroked[i-1][j] ) dp[i][j] += dp[i-1][j];
    if(j-1>=0 && !rowBroked[i][j-1] ) dp[i][j] += dp[i][j-1];
  }
}
cout << dp[N][M] << endl;

// for( int i =0 ; i<=N ;i++){
//   for( int j =0 ; j<=M ;j++){
//     cout << dp[i][j] << " ";
//   }
//   cout << endl;
// }

// for (int i = 0; i <= N;i++) {
//   for (int j = 0; j <= M;j++) {
//     cout << rowBroked[i][j] << " ";
//   }
//   cout << endl;
// }

// for (int i = 0; i <= N;i++) {
//   for (int j = 0; j <= M;j++) {
//     cout << colBroked[i][j] << " ";
//   }
//   cout << endl;
// }
return 0;
}