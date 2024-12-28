#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<queue>
#include<string>
#include<math.h>
#define ll long long
using namespace std;

ll dp[51][101];
ll A[101];
ll B[101];
ll C[101];


int main(){

  int N, M, K;
  cin >> N >> M >> K;

  for( int i =1 ; i<K+1; i++){
    cin >> A[i] >> B[i] >> C[i];
  }

  fill(&dp[0][0], &dp[0][0] + 51 * 101, -1);

  for (int i = 0; i < K + 1; i++) {
    dp[0][i] = 0;
  }

  for (int m = 1; m < M + 1; m++) {
    for (int k = 1; k < K + 1; k++) {


      if (m - A[k] >= 0) {

        for (int l = 1; l < K + 1; l++) {


            if (dp[m - A[k]][l] >= 0) {
              // cout << dp[m - A[k]][l] + C[k] << endl;
              dp[m][k] = max(dp[m][k], (dp[m - A[k]][l] + C[k]));
              // cout << dp[m][k] << endl;
            }


          }
        }
      if (m - B[k] > 0 && dp[m-B[k]][k] >0) {
        // cout << dp[m - B[k]][k] + C[k] << endl;
        dp[m][k] = max(dp[m][k], (dp[m - B[k]][k] + C[k]));
        // cout << dp[m][k] << endl;
      }

      dp[m][k] = max(dp[m][k], 0LL);
      dp[m][k] = max(dp[m][k], dp[m-1][k]);

    }
  }
  // for (int i = 0; i < M+1; i++) {
  //   for (int j = 0;j < K+1;j++) {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;

  // }

  ll ans = 0;
  for (int i = 1; i < K+1; i++) {

    ans = max(ans, dp[M][i]);

  }
  cout << ans*N << endl;


  return 0;

  }





