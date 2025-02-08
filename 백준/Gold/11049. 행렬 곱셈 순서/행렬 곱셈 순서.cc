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



int dp[501][501];
vector<pair<int, int>> v;

int multiMatrix(int st, int en) {
  int value = 0;
  for (int i = st+1; i <= en; i++) {
    value += v[st].first * v[i].first * v[i].second;
  }
  return value ;
}


int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
int N;
cin >> N;

for(int i= 0; i< N; i++ ){
  int p1, p2;
  cin >> p1 >> p2;
  v.push_back({ p1,p2 });
}

for (int i = 0; i < N;i++) {
  for(int j = i+1; j<N; j++)
  dp[i][j] = INT32_MAX;
}

for (int i = 1; i < N;i++) {
  for (int j = 0; j < N - i; j++) {
    for (int k = j; k <= j + i;k++) {
      dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i] + v[j].first * v[k].second * v[j + i].second);
    }
  }
}


cout << dp[0][N-1] << endl;


return 0;
}