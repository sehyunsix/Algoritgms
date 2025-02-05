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
vector<ll> v;

int N, M, tmp;
ll cal_number(ll t){

  ll res = 0;
  for (int i = 0; i < M;i++) {
    res += t / v[i] +1;
  }
  return res;


}

int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
cin >> N >> M;


for (int i = 0; i < M;i++) {
  cin >> tmp;
  v.push_back(tmp);
}

if (N <= M) {
  cout << N << endl;
  return 0;
}

ll a = 2000000000;
ll b = 300000;
ll T = a * b;
ll st = 0;
ll en =T;
ll mid;
ll sol = 0;
ll sol_tmp = 0;
ll tmp;
while (st <= en) {
  mid = (st + en) / 2;
  tmp = cal_number(mid);
  if (tmp < N) {
    sol_tmp = tmp;
    sol = mid;
    st = mid + 1;
  }
  else{
    en = mid - 1;
  }
}
// cout << "tmp : " << sol_tmp << endl;
// cout << "time :" << sol << endl;
int count = N - sol_tmp;
int min_number = 100;
int min_index = 0;
for (int i = 0; i < M; i++) {
  // cout << (sol+1) % v[i] << " ";
  if ((sol + 1) % v[i] == 0) {
    count--;
    if (count == 0) {
      min_index = i+1;
    }

  }
  }

// cout << endl;


cout << min_index << endl;




return 0;
}