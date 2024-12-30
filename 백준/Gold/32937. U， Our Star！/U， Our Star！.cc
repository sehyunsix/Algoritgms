#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<queue>
#include <string>
#include<math.h>
#define ll long long
using namespace std;



int dp[100001][101];


int main() {

  int X, Y, D ,N;
  cin >> X >> Y >> D >> N;
  int sum = 0;
  vector<int> vec;

  for (int i = 0; i < N; i++) {
    int n, p;
    cin >> n >> p;
    sum += n;
    for( int i =0 ; i<n; i++){
      vec.push_back(p);
    }

  }

  sort(vec.begin(), vec.end());

  // cout << "list :" << endl;
  // for (int a  : vec ) {
  //   cout << a << " ";
  // }
  // cout << endl;

  for (int i = 1; i < (D / Y) * X + 1; i++) {

    for( int j =1 ; j<vec.size()+2; j++){
      if (i - vec[j - 1] > 0 && ((i <= dp[i - vec[j - 1]][j - 1] + vec[j - 1]))) {
        if (dp[i][j - 1] != 0) {
            dp[i][j] = min(dp[i][j - 1], dp[i - vec[j - 1]][j - 1] + vec[j - 1]);
          }
        else {
          dp[i][j] = dp[i - vec[j-1]][j - 1] + vec[j-1];
        }
      }

    if( i <= vec[j-1]) {
        if (dp[i][j - 1] != 0) {
          dp[i][j] = min(dp[i][j - 1], vec[j-1]);
        }
        else {
          dp[i][j] = vec[j-1];
        }
      }


    }
  }

  if (dp[(D / Y) * X ][vec.size()] != 0) {
    cout << dp[(D / Y) * X ][vec.size()] << endl;
  }
  else {

    int ans = 0;
    for( int i =0 ; i<(D/Y); i ++){
      ans = max(dp[i * X][vec.size()] , ans);
    }
    cout << ans << endl;

  }

  // for (int i = 0; i < (D / Y) * X+1; i++) {
  //   cout << i << "번쨰 : ";
  //   for (int j = 0; j < vec.size() + 1; j++) {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;

  // }

  return 0;
}