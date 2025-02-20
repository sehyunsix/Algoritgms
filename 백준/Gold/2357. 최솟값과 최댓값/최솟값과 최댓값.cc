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
vector<int> maxSeg;
vector<int> minSeg;
int treeSize;


void maxSegUpdate(int index, int value) {
  if (index == 0) return;
  if (maxSeg[index] < value) {
    maxSeg[index] = value;
    maxSegUpdate(index / 2, value);
  }
  return;
}

int maxSegFind(int st, int en) {
  int res = INT32_MIN;
  while (st <= en) {
    if (st % 2 == 1) {
      res = max(res, maxSeg[st]);
      st = (st + 1) / 2;
    }
    else {
      st = st / 2;
    }
    if (en % 2 == 0) {
      res = max(res, maxSeg[en]);
      en = (en - 1) / 2;
    }
    else {
      en = en / 2;
    }
  }
  return res;

}

void minSegUpdate(int index, int value) {
  if (index == 0) return;
  if (minSeg[index] > value) {
    minSeg[index] = value;
    minSegUpdate(index / 2, value);
  }
  return;
}


int minSegFind(int st, int en) {
  int res = INT32_MAX;
  while (st <= en) {
    if (st % 2 == 1) {
      res = min(res, minSeg[st]);
      st = (st + 1) / 2;
    }
    else {
      st = st / 2;
    }
    if (en % 2 == 0) {
      res =min(res, minSeg[en]);
      en = (en - 1) / 2;
    }
    else {
      en = en / 2;
    }
  }
  return res;

}




int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);

int N, M;
cin >> N >> M;


treeSize = 1;
while (treeSize <N) {
  treeSize = treeSize << 1;
}
treeSize = 2 * treeSize;

maxSeg = vector<int>(treeSize, INT32_MIN);
minSeg = vector<int>(treeSize, INT32_MAX);


for (int i = 0; i < N;i++) {
  int tmp;
  cin >> tmp;
  maxSegUpdate(i + treeSize / 2, tmp);
  minSegUpdate(i + treeSize / 2, tmp);
}


for (int i = 0; i < M;i++) {
  int st, en;
  cin >> st >> en;
  cout << minSegFind(st-1 + treeSize / 2, en-1 + treeSize / 2) << " " << maxSegFind(st-1 + treeSize / 2, en-1 +treeSize / 2) << endl;
}
return 0;
}