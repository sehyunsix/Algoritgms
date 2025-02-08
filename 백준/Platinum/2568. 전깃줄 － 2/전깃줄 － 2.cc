#include<iostream>
#include<algorithm>
#include<vector>

#define ll long long
#define P 1000000007
#define endl "\n"
using namespace std;

vector<int> dp;
vector<pair<int, int>> v;
int parent[100001];
bool notremove[100001];

bool cmp(pair<int, int> a, pair<int, int> b) {
  return a.second < b.second;
};

int bs(int r, int  l ,int x) {
  int st = 0;
  int en = l+1;
  while (st < en) {
    int mid = (st + en ) / 2;
    if (v[dp[mid]].first > x) {
      en = mid;
    }
    else {
      st = mid + 1;
    }
  }

  return en;


};



int main() {

cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);

int N;
cin >> N;


for (int i = 0; i < N; i++) {
  int p1, p2;
  cin >> p1 >> p2;
  v.push_back({ p1,p2 });
}


sort(v.begin(), v.end(), cmp);
// for (auto a : v) {
//   cout << a.first << " " << a.second << endl;;
// }
// cout << endl;

dp.push_back(0);
for(int i=0; i<N;i++){
  parent[i] = -1;
}

for (int i = 1; i < N; i++) {
  // cout << "dp :";
  // for (auto a : dp) {
  //   cout << a << " ";
  // }
  // cout << endl;
  int idx = bs(0, dp.size() - 1, v[i].first);
  // cout << "size :" << dp.size() <<"idx : "<< idx  << endl;
  if ((int) dp.size() == idx) {
    // cout << "push" << endl;
    parent[i] = dp.back();
    dp.push_back(i);
  }
  else {

    parent[i] = ( idx==0 ? -1 : dp[idx - 1]);
    dp[idx] = i;
  }
}

// cout << "parent " << endl;
// for (int i = 0; i < 10;i++) {
//   cout << parent[i] << " ";
// }

// cout << "lcs size : " << dp.size() << endl;
int idx = dp.back();
// cout << parent[0] << endl;
// cout << "lcs :";
while (idx != -1) {
  notremove[idx] = 1;
  // cout << v[idx].first << " ";
  idx = parent[idx];
}

// cout << endl;
vector<int> ans;
// cout << "lcs :";
for (int i = 0;i < N;i++) {
  if (!notremove[i]) {
    ans.push_back(v[i].first);
  }
  // else{
  //   cout << v[i].first <<" ";
  // }
}
// cout << endl;

cout << ans.size() << endl;
if (!ans.empty()) {
  sort(ans.begin(), ans.end());
  for (auto a : ans) {
    cout << a << endl;
  }
}
return 0;
}
