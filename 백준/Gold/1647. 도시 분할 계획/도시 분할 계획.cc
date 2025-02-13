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

typedef struct cmpCost {

  bool operator()(vector<int>& a, vector<int>& b) {
    return a[2] > b[2];
  }
}cmpCost;


int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);

int N, M;
cin>>  N >> M;

parent = vector<int>(N + 1, 0);
groupSize = vector<int>(N + 1, 0);
for (int i = 1; i < N + 1; i++) {
  parent[i] = i;
  groupSize[i] = 1;
}

priority_queue<vector<int>, vector<vector<int>>, cmpCost> q;

for (int i = 0; i < M;i++) {
  int x, y, c;
  cin >> x >> y >> c;
  q.push({ x,y,c });
}

int cntEdge = 0;
int ans = 0;
int max_edge = 0;
while (!q.empty() && cntEdge < N - 1) {
  vector<int> curr = q.top();
  q.pop();
  int head1 = findHead(curr[0]);
  int head2 = findHead(curr[1]);
  if (head1 != head2) {
    // cout << curr[2] << endl;
    max_edge = max(curr[2], max_edge);
    merge(head1, head2);
    cntEdge++;
    ans += curr[2];
  }
}

cout << ans-max_edge << endl;
return 0;
}