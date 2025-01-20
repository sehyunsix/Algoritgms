#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<queue>
#include <string>
#include<math.h>
#define ll long long
#define P 1000000007
using namespace std;


pair<ll, ll> E_gcd(ll a, ll b) {

  ll p = a / b;
  if (a % b == 1) {
    return { 1, -p };
  }
  pair<ll, ll >  tmp = E_gcd(b, a % b);
  return { (tmp.second)    , ((-p * tmp.second)  + tmp.first )  };
}


ll gcd(ll a, ll b) {
  if (a % b == 0) {
    return b;
  }
  return gcd(b, a % b);
}


int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);



int M;
cin >> M;


ll ans = 0;
for (int i = 0; i < M; i++) {
  ll d, N, S;
  cin >> N >> S;
  d = gcd(N, S);
  N = N / d;
  S = S / d;

  pair<ll, ll > sol = E_gcd(P, N);
  if (sol.second < 0) {
    sol.second = P + sol.second;
  }
  ll inverse_b = sol.second % P;
  // cout << sol.first << " " << sol.second << " " << (sol.second * N) % P << endl;
  ans = ans % P + (inverse_b * S) % P;
  // cout << 3*-961633937  << "\n";
}
cout << ans % P;

return 0;
}
