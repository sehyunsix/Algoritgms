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
ll nCk[53][53];

int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  for (int n = 1; n <= 52;n++) {
    nCk[n][0] = 1;
    nCk[n][1] = n;
    nCk[n][n] = 1;
  }

  for (int i = 2;i <= 52;i++) {
    for (int k = 2; k <= i - 1; k++) {
      nCk[i][k] = (nCk[i - 1][k - 1] + nCk[i - 1][k]);
    }
  }


  if (N < 4) {
    cout << 0 << endl;
  }
  else if (N <= 39) {
    ll  sum = 0;
    for (int i = 1; i <= N / 4; i++) {
      if (i % 2 == 0) sum -= (nCk[13][i] * nCk[52 - 4 * i][N - 4 * i]);
      else sum += (nCk[13][i] * nCk[52 - 4 * i][N-4*i]);
    }
    sum %= 10007;
    cout << sum << endl;
  }
  else {
    cout << nCk[52][N] % 10007 << endl;;
  }



  return 0;
}