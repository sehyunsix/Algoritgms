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
bool cmp(pair<int, int>& a, pair<int, int>& b) {
  if (a.second == b.second) {
    return a.first < b.first;
  }
  return a.second < b.second;
}
int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
int N;
cin >> N;
vector<pair<int, int>> v(N);
for (int i = 0; i < N; i++) {

  int p1,p2;
  cin >> p1 >> p2;
  v[i] = { p1,p2 };
}

sort(v.begin(), v.end(), cmp);

for (auto p : v) {
  cout << p.first << " " << p.second << endl;
}

return 0;
}