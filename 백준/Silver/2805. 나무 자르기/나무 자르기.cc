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
int N, M;
int a[1000000];

bool T(ll m) {
  ll sum = 0;
  for (int i = 0; i < N; i++) {
    if (a[i] - m > 0) {
      sum += a[i] - m;
    }
  }
  return M <= sum;
}

int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
cin >> N >> M;

for (int i = 0; i < N;i++) {
  cin >> a[i];
}

int st = 0;
int en = 2000000000;
int mid;
int sol;
while (st <= en) {

  mid = (st + en) / 2;
  if (T(mid)) {
    sol = mid;
    st = mid + 1;
  }
  else {
    en = mid - 1;
  }
}

cout << sol << endl;


return 0;
}