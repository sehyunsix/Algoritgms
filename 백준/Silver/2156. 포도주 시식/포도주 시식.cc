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
int N;
int dp[10001][3];

int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
cin >> N;



vector<int> v;
for (int i = 0; i < N; i++) {
  int tmp;
  cin >> tmp;
  v.push_back(tmp);
}

// 0: no eat ,1: eat , 2 : eat

for (int i = 1; i < N+1;i++) {
  dp[i][0] = max(max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
  dp[i][1] = dp[i - 1][0] + v[i-1];
  dp[i][2] = dp[i - 1][1] + v[i-1];
}


cout << max(max(dp[N][0], dp[N][1]), dp[N][2]) << endl;


return 0;
}