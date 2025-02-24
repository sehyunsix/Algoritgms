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

ll dp[31];


// i j k 는 2씩 차이냐야 됨
int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
int N;
cin >> N;

if (N % 2) {
  cout << 0 << endl;
  return 0;
}


dp[0] = 1;
for (int i = 2; i <= N; i += 2) {
  dp[i] += dp[i - 2] * 3;
  for (int j = 4; j <= i; j += 2) {
    dp[i] += dp[i - j] * 2;
  }
}
cout << dp[N] << endl;
return 0;
}