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

bool cmp(pair<int,int> a, pair<int,int> b) {
    return -a.second-a.first < -b.second-b.first;

}

int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);

int N;
cin >> N;
vector<pair<int, int>> v;
for (int j = 0; j < N;j++) {
  int x, y;
  cin >> x >> y;
  if (x > y) swap(x, y);
  v.push_back({ x,y });
}

sort(v.begin(), v.end(),cmp);

int ans = 0;
for (int i = 0; i < N / 2; i++) {
  ans -= v[i].second;
  // cout << v[i].first<<" "<< v[i].second << v[i].first-v[i].second<< endl;
}

for (int i = N / 2; i < N; i++) {
  ans += v[i].first;
  // cout << v[i].first << " " << v[i].second << v[i].first - v[i].second<< endl;
}



cout << ans << endl;

return 0;
}