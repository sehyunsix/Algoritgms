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
int dp[maxP];
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

for (int j = 0; j < maxP;j++) {
  dp[j] = INT32_MAX;
}


dp[0] = 0;
for (int j = 0; j < maxP; j++) {
  for (int i = 1; i <= N;i++) {
    if (j - people[i] < 0) continue;
    if (dp[j - people[i]] == INT32_MAX) continue;
    dp[j] = min(dp[j - people[i]] + cost[i], dp[j]);
    }
}



int ans = INT32_MAX;
for (int j = C; j < maxP; j++) {
    ans = min(ans, dp[j]);
}
cout << ans << endl;

return 0;
}