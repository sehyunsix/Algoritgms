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


vector<int> parent;
vector<int> groupSize;

int findHead(int x) {
  if (x == parent[x]) return x;
  parent[x] = findHead(parent[x]);
  return parent[x];
}

void merge(int x, int y) {

  int headx = findHead(x);
  int heady = findHead(y);
  if (groupSize[headx] >= groupSize[heady]) {
    parent[heady] = headx;
    groupSize[headx] += groupSize[heady];
  }
  else {
    parent[headx] = heady;
    groupSize[heady] += groupSize[headx];
  }
}

int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);

int N, M;

cin >> N >> M;
parent = vector<int>(N, 0);
groupSize = vector<int>(N, 0);
for (int i = 0; i < N;i++) {
  parent[i] = i;
  groupSize[i]= 1;
}

for (int i = 0; i < M; i++) {
  int x, y;
  cin >> x >> y;
  if (findHead(x) == findHead(y)) {
    cout << i+1 << endl;
    return 0;
  }
  merge(x, y);
}

cout << 0 << endl;

return 0;
}