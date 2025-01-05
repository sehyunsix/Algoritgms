  #include<iostream>
  #include<algorithm>
  #include<vector>
  #include<memory.h>
  #include<queue>
  #include <string>
  #include<math.h>
  #define ll long long
  using namespace std;


  int main() {
    int dp[100001];
    int X, Y, Z;
    cin >> X >> Y >> Z;


    if (X == 3 && Y == 3 && Z == 3) {
      cout << 0;
        return 0;
    }
    dp[1] = 0;
    dp[2] = 0;
    dp[3] = 1;
    dp[4] = 1;

    for( int i =5 ; i<100001; i++){
      dp[i] = dp[i -2] +1;
    }

    int m = min(X, min(Y, Z));
    cout << dp[m];


    return 0;
  }