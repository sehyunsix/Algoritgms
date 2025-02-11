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
int N;
int visited[1001];
int arr[4] = {
  1, 5, 10, 50
};
void dfs(int sum, int level,int prev) {

  if (level == N) {
    visited[sum] = 1;
    return;
  }

  for (int i = prev; i < 4;i++) {
    // cout << sum << endl;
    sum += arr[i];
    dfs(sum, level + 1 ,i);
    sum -= arr[i];
  }

  return;
}

int main() {

cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);

int ans = 0;
cin >> N;
dfs(0, 0,0);
for (int i = 0;i < 1001; i++) {
  ans += visited[i];
}
cout << ans << endl;

return 0;
}