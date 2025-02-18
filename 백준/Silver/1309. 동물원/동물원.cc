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
#define MOD 9901
#define endl "\n"
using namespace std;
int dp[100000][3];

int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);

int N;
cin >> N;

for (int i = 0; i < 3; i++) {
  dp[0][i] = 1;
}

for (int i = 1; i < N;i++) {
  dp[i][0] = dp[i - 1][0] + dp[i - 1][2];
  dp[i][1] = dp[i - 1][1] + dp[i - 1][2];
  dp[i][2] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];

  for (int j = 0; j < 3;j++) {
    dp[i][j] %= MOD;
  }
}

cout << (dp[N-1][0] + dp[N-1][1] + dp[N-1][2]) % MOD << endl;
return 0;
}