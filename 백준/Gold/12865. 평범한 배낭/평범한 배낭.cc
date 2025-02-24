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
#define maxN 101
#define maxK 100001
using namespace std;

int dp[maxN][maxK];

int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);

int N, K;
cin >> N >> K;

vector<int> values(N, 0);
vector<int> weights(N, 0);
for (int i = 0; i < N;i++) {
  cin >> weights[i] >> values[i];
}

for (int i = 1; i < N + 1;i++) {
  for (int j = 0; j < K+1;j++) {
      if (j - weights[i-1] >= 0) {
        dp[i][j] = dp[i - 1][j - weights[i - 1]] + values[i - 1];
      }
      dp[i][j] = max(dp[i][j], dp[i - 1][j]);
  }
}


cout << dp[N][K] << endl;


return 0;
}