#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int N, M, ans, sum;
int bite[101], cost[101];


int main()
{
  cin >> N >> M;
  vector<ll>dp(10001, 0);
  for (int i = 1; i <= N; i++) cin >> bite[i];
  for (int i = 1; i <= N; i++)
  {
    cin >> cost[i];
    sum += cost[i];
  }

  // dp[i][j] == i번째 앱까지 탐색했을 때
  // j비용을 소모해서 얻을 수 있는 최대 메모리
    dp[0] = 0;

  for (int i = 1; i <= N;i++) {
    for (int j =sum; j >= 0;j--) {
      if (j - cost[i] >= 0) {
          dp[j] = max(dp[j - cost[i]] + bite[i], dp[j]);
        }
      }
    }

  for (int i = 0; i <= sum; i++)
  {
    if (dp[i] >= M)
    {
      cout << i << endl;
      break;
    }
  }


}