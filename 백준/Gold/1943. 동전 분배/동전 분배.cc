    #include<iostream>
    #include<algorithm>
    #include<vector>
    #include<memory.h>
    #include<queue>
    #include <string>
    #include<math.h>
    #include<map>
    #define ll long long
    #define endl "\n"
    using namespace std;

    int dp[101][100001];
    int P[101];
    int C[101];
    int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);


    int N;
    for (int t = 0; t < 3;t++) {
      int totalPrice = 0;
      cin >> N;
      for (int i = 0; i < N;i++) {
        cin >> P[i] >> C[i];
        totalPrice += P[i] * C[i];
      }
      if (totalPrice % 2) {
        cout << 0 << endl;
        continue;
      }
      for (int j = 0; j <= totalPrice/2; j++) {
        dp[0][j] = 0;
      }
      dp[0][0] = 1;
        for (int i = 1; i <= N;i++) {
          for (int j = 0; j <= totalPrice/2; j++) {
            dp[i][j] = dp[i - 1][j];
            for (int c = 1; c <= C[i - 1]; c++) {
              int tmp = j - P[i - 1] * c;
              if (tmp >= 0) {
                dp[i][j] = max(dp[i - 1][tmp], dp[i][j]);
              }
              else {
                break;
              }
            }
          }
        }
        // cout << "totalPrice : " << totalPrice << endl;
        // for (int i = 0; i <= N; i++) {
        //   for (int j = 0; j < 5000;j++) {
        //     if (dp[i][j])
        //       cout << i<<j << " ";
        //   }
        //   cout << endl;
        // }
        cout <<  dp[N][totalPrice / 2] << endl;

    }


    return 0;
    }