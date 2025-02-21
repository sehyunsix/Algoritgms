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
  return a.second < b.second;
}

int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);

int N;
cin >> N;
vector<pair<int, int>> paths;

for (int i = 0; i < N;i++) {
  int st, en;
  cin >> st >> en;
  if (st > en) swap(st, en);
  paths.push_back({ st,en });
}
sort(paths.begin(), paths.end(),cmp);

int L;
cin >> L;
int ans = 0;
priority_queue <int, vector<int>, greater<int>> q;
for (int i = 0; i < N; i++) {
  while (!q.empty() && paths[i].second - q.top() > L) {
    // cout << "pop " << q.top() << " " << endl;
    q.pop();
  }
  // cout << "push " << paths[i].first << " " << paths[i].second << endl;
  if (paths[i].second - paths[i].first > L) continue;
  q.push(paths[i].first);
  ans = max(ans, (int) q.size());
}

cout << ans << endl;


return 0;
}