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
int N =1000000;
int treeSize;
int baseIdx;
vector<int> segTree;

void update(int idx, int value) {

  int updateIdx = baseIdx + idx - 1;
  int updateVal = segTree[updateIdx] + value;
  while (updateIdx > 0) {
    segTree[updateIdx] = updateVal;
    updateIdx = updateIdx / 2;
    updateVal = segTree[updateIdx * 2] + segTree[updateIdx * 2 + 1];
  }
  return;
}

int find(int x) {
  int Idx = 1;
  while (Idx < baseIdx) {
    if (segTree[Idx * 2] >= x) {
      Idx = Idx * 2;
    }
    else {
      x = x - segTree[Idx * 2];
      Idx = Idx * 2 + 1;
    }

  }
  update(Idx - baseIdx + 1, -1);
  return Idx - baseIdx + 1;
}


int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);

treeSize = 1;
while (treeSize < N) {
  treeSize = treeSize << 1;
}
baseIdx = treeSize;
treeSize = treeSize << 1;

segTree = vector<int>(treeSize + 1, 0);

int q;
cin >> q;
while (q--) {
  int a, b, c;
  cin >> a;
  if (a == 2) {
    cin >> b >> c;
    update(b, c);
  }
  if (a == 1) {
    cin >> b;
    cout << find(b) << endl;;
  }
}
return 0;
}