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
bool m[750][750];
int dp[752][752][4];

int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);

int N,M;
cin >> N >> M;

for (int i = 0; i < N;i++) {
  for (int j = 0; j < M;j++) {
    char tmp;
    cin >> tmp;
    m[i][j] = tmp - '0';
  }
}

for (int i = 0; i < N;i++) {
  for (int j = 0; j < M; j++) {
    if (m[i][j] == 1) {
      // cout << i << " " <<j << endl;
      dp[i + 1][j + 1][0] = dp[i][j][0] + 1;
      // cout << i + 1 << " " << j + 1 << "       " << i << " " << j + 2 << dp[i][j + 2][1] << endl;
      dp[i + 1][j + 1][1] = dp[i][j + 2][1] + 1;
    }
  }
}

for (int i = N; i >=1 ;i--) {
  for (int j = 1; j <= M; j++) {
    if (m[i-1][j-1] == 1) {
      dp[i][j][2] = dp[i+1][j - 1][2] + 1;
      dp[i][j][3] = dp[i+1][j + 1][3] + 1;
    }
  }
}
// cout << "===============" << endl;
// for (int j = 1; j < N + 1;j++) {
//   for (int i = 1; i < M + 1;i++) {
//     cout << dp[j][i][0] << " ";
//   }
//   cout << endl;
// }
// cout << "===============" << endl;

// for (int j = 1; j < N + 1;j++) {
//   for (int i = 1; i < M + 1;i++) {
//     cout << dp[j][i][1] << " ";
//   }
//   cout << endl;
// }

// cout << "===============" << endl;
// for (int j = 1; j < N + 1;j++) {
//   for (int i = 1; i < M + 1;i++) {
//     cout << dp[j][i][2] << " ";
//   }
//   cout << endl;
// }

// cout << "===============" << endl;

// for (int j = 1; j < N + 1;j++) {
//   for (int i = 1; i < M + 1;i++) {
//     cout << dp[j][i][3] << " ";
//   }
//   cout << endl;
// }


int ans = 0;
for (int i = 1; i < N+1;i++) {
  for (int j = 1; j < M + 1; j++) {
    int tmp = min(dp[i][j][1], dp[i][j][3]);
    int distance = 2 * tmp - 2;
    for (int distance = 2 * tmp - 2; distance > -1; distance = distance - 2) {
      if (j + distance <= M) {
        if (distance / 2 + 1 <= min(dp[i][j + distance][0], dp[i][j + distance][2]))
          ans = max(ans, distance / 2 + 1);
      }
    }
  }
  }


cout << ans << endl;

return 0;
}