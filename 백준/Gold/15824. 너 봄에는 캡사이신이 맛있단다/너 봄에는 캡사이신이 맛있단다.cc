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

int pow2(int  n) {
  if (n == 0) return 1;
  ll a = pow2(n / 2) % P;
  if (n % 2) return (a * a * 2) % P;
  else return (a * a) % P;
}


int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
vector<ll> v;
int N;
cin >> N;
v.resize(N);
for (int i = 0; i < N; i++) {
  cin >> v[i];
}

sort(v.begin(), v.end());

ll res = 0;

for (int i = 0; i < N; i++) {
  ll tmp = v[i] * pow2(i) - v[i] * pow2(N - i - 1);
  res += tmp;
  res %= P;
}

cout << res << endl;


return 0;
}