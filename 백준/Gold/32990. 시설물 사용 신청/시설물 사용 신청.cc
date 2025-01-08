#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<queue>
#include <string>
#include<math.h>
#define ll long long
using namespace std;
int main() {

  ll  N;
  cin >> N;

  ll ans = 0;
  for (int i = 1; i < ((N + 2) / 2); i++) {
    ans += (N - 2 * i + 1);

  }

  if (ans > 1000000) {
    cout << ans << endl;
    return 0;

  }
  else {
    cout << ans << endl;
    for (int i = 1; i <= N - 1; i++) {
      for (int k = 1; k <= i; k++) {
        if ((N - k) / i > 0) {
          cout << ((N - k) / i) << " ";
          for (int j = k; j + i <= N; j += i) {
            cout << j << " " << j + i << " ";
          }
          cout << "\n";
        }
        }
    }
    }


return 0;

}
