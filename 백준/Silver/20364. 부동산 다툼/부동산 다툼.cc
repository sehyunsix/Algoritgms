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
bool visited[(1<<20)+1];

int canGo(int x) {
  int tmp = x;
  int res = INT32_MAX;
  while (x > 1) {
    if (visited[x]) {res = min(res, x);}
    x = x / 2;
  }
  if (res == INT32_MAX) {
    visited[tmp] = true;
    return 0;
  }
  return res;
}

int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
cin >> N >> M;
for (int i = 0; i < M;i++) {
  int x;
  cin >> x;
  cout << canGo(x) << endl;
}
return 0;
}