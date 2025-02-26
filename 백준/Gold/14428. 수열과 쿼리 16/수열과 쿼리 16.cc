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
int N , treeSize;
vector<ll> seg;


void update(int index, int value) {
  int treeIndex = index - 1 + treeSize / 2;
  seg[treeIndex] = value;
  while(treeIndex>1){
    treeIndex = treeIndex / 2;
    seg[treeIndex] = min(seg[treeIndex * 2], seg[treeIndex * 2 + 1]);
  }
}

int find(int st, int en) {
  int treeStIndex = st - 1 + treeSize / 2;
  int treeEnIndex = en - 1 + treeSize / 2;
  int res = INT32_MAX;
  int minIndex = INT32_MAX;
  // cout << treeStIndex << " "<< treeEnIndex << endl;
  while (treeStIndex <= treeEnIndex) {
    if (treeStIndex % 2 == 1) {
      // cout << "start : " << treeStIndex << endl;
      if (seg[treeStIndex] <= res) {
        int tmp = treeStIndex;
        while (tmp < (treeSize / 2)) {
          int leftChild = tmp * 2;
          int rightChild = tmp * 2 + 1;
          tmp = (seg[leftChild] <= seg[rightChild] ? leftChild : rightChild);
        }
        if (res == seg[treeStIndex]) {
          minIndex = min(minIndex, tmp);
        }
        else {
          minIndex = tmp;
        }
        res = seg[treeStIndex];

      };
      treeStIndex = (treeStIndex + 1) / 2;
    }
    else {
      treeStIndex = treeStIndex / 2;
    }
    if (treeEnIndex % 2 == 0) {
      // cout << "end : " << treeEnIndex << endl;
      if (seg[treeEnIndex] <= res) {
        int tmp = treeEnIndex;
        while (tmp < (treeSize / 2)) {
          int leftChild = tmp * 2;
          int rightChild = tmp * 2 + 1;
          tmp = (seg[leftChild] <= seg[rightChild] ? leftChild : rightChild);
        }
        if (res == seg[treeEnIndex]) {
          minIndex = min(minIndex, tmp);
        }
        else {
          minIndex = tmp;
        }
        res = seg[treeEnIndex];
      }
      treeEnIndex = (treeEnIndex - 1) / 2;
    }
    else {
      treeEnIndex = treeEnIndex / 2;
    }
  }


  return minIndex+1 -(treeSize/2);

}

int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
cin >> N;
treeSize = 1;
while (treeSize < N) {
  treeSize = treeSize << 1;
}
treeSize = treeSize * 2;

seg = vector<ll>(treeSize + 1, INT32_MAX);

for (int i = 0; i < N;i++) {
  int tmp;
  cin >> tmp;
  update(i + 1, tmp);
}

int M;
cin >> M;
for (int j = 0; j < M;j++) {
  int x, y, z;
  cin >> x >> y >> z;
  if (x == 1) update(y, z);
  else if (x == 2) cout << find(y, z) << endl;
}

// for( int j =0 ; j<treeSize ;j++){
//   cout << seg[j] << " ";
// }
// cout << endl;
return 0;
}