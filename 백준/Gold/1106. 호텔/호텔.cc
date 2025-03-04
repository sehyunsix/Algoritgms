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
#define maxP 1500
using namespace std;
int  C, N;
int dp[21][maxP];
int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);

cin >> C >> N;

vector<int>cost(N + 1, 0);
vector<int>people(N + 1, 0);
for (int i = 1;i <= N;i++) {
  cin >> cost[i] >> people[i];
}

for (int i = 0; i <= N; i++) {
  for (int j = 0; j < maxP;j++) {
    dp[i][j] = INT32_MAX;
  }
}

dp[0][0] = 0;
for (int i = 1; i <= N; i++) {
  for (int j = 0; j < maxP; j++) {
    dp[i][j] = dp[i - 1][j];
    int maxNum = j / people[i];
    for (int k = 0; k <= maxNum;k++) {
      if (dp[i - 1][j - k * people[i]] != INT32_MAX) {
        dp[i][j] = min(dp[i][j], dp[i-1][j - k * people[i]] + k * cost[i]);
        }
      }
  }
}

// for (int i =0 ; i <= N;i++) {
//   for (int j = 0; j < 10001; j++) {
//     cout << dp[i][j] << " ";
//   }
//   cout << endl;
// }

int ans = INT32_MAX;
for (int j = C; j < maxP; j++) {
    ans = min(ans, dp[N][j]);
}

cout << ans << endl;

return 0;
}