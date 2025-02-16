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
//1450
vector<int> chk;


void dfs(ll sum, int level, int prev ,vector<int>& v, vector<ll>& s  ) {
  if (level == v.size()) {
    return;
  }
  for (int i = prev+1; i < (int)v.size(); i++) {
    sum += v[i];
    chk.push_back(i);
    s.push_back(sum);
    dfs(sum, level + 1,i, v, s);
    chk.pop_back();
    sum -= v[i];
  }
  return;
}

int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);

int N, C;
cin >> N >> C;

int n1 = N/2;
int n2 = N - N / 2;

vector<int> v1;
vector<int> v2;

for (int i = 0; i < n1; i++) {
  int tmp;
  cin >> tmp;
  v1.push_back(tmp);
}

for (int i = 0; i < n2; i++) {
  int tmp;
  cin >> tmp;
  v2.push_back(tmp);
}

vector<ll> s1 = {0};
vector<ll> s2 = {0};

dfs(0LL ,0, -1, v1,s1);
dfs(0LL, 0, -1, v2, s2);
sort(s1.begin(), s1.end());
sort(s2.begin(), s2.end());


ll ans = 0;
for (int i = 0; i < (int) s2.size();i++) {
  int st = -1;
  int en = s1.size()-1;
  while (st < en) {
    int mid = (st + en + 1) / 2;
    if (C- s1[mid] >= s2[i]) {
      st = mid;
    }
    else {
      en = mid - 1;
    }
  }
  // cout << "st : " << st << endl;
  ans += (st + 1);
  // cout << "add ans : " << ans << endl;

}

cout << ans << endl;

return 0;
}