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

vector<ll> seg;
int N, M, K, treeSize;

void Update(int index, int value) {
  int treeIndex = index - 1 + treeSize / 2;
  while (treeIndex > 0) {
    seg[treeIndex] = value;
    ll tmp = (treeIndex % 2 ? seg[treeIndex - 1] : seg[treeIndex + 1]) * value;
    tmp %= P;
    value = tmp;
    treeIndex = treeIndex / 2;
  }
  return;
}

int Find(int st, int en) {
  int treeIndexSt = st - 1 + treeSize / 2;
  int treeIndexEn = en - 1 + treeSize / 2;
  ll res = 1;
  while (treeIndexSt <= treeIndexEn) {
    if (treeIndexSt % 2) {
      res *= seg[treeIndexSt];
      res %= P;
      treeIndexSt = (treeIndexSt + 1) / 2;
    }
    else {
      treeIndexSt = treeIndexSt / 2;
    }
    if (treeIndexEn % 2 == 0) {
      res *= seg[treeIndexEn];
      res %= P;
      treeIndexEn = (treeIndexEn - 1) / 2;
    }
    else
    {
      treeIndexEn = treeIndexEn / 2;
    }
  }
  return res % P ;
}


int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);


cin >> N >> M >> K;

treeSize = 1;
while (treeSize <= N) {
  treeSize =treeSize << 1;
}
treeSize = treeSize * 2;

seg = vector<ll>(treeSize + 1, 0);

for (int i = 0; i < N;i++) {
  int tmp;
  cin >> tmp;
  Update(i+1, tmp);
}

for (int i = 0;i < M + K;i++) {
  int a, b, c;
  cin >> a >> b >> c;
  if (a == 1) Update(b, c);
  if (a == 2) cout << Find(b, c) << endl;;
}


// for (int i = 0;i <treeSize+1;i++) {
//   cout << seg[i] << " ";
// }
// cout << endl;




return 0;
}