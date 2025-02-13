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
cin >> N;

parent = vector<int>(N + 1, 0);
groupSize = vector<int>(N + 1, 0);
for (int i = 0; i < N + 1; i++) {
  parent[i] = i;
  groupSize[i] = 1;
}


priority_queue<vector<int>, vector<vector<int>>, cmpCost> q;

for (int i = 0; i < N;i++) {
  int tmp;
  cin >> tmp;
  q.push({ 0, i + 1 ,tmp });
}

int adj[N][N];

for (int i = 0; i < N;i++) {
  for (int j = 0; j < N; j++) {
    cin >> adj[i][j];
  }
}

for (int i = 0; i < N-1;i++) {
  for (int j = i + 1; j< N;j++) {
    q.push({ i + 1,j + 1, adj[i][j] });
  }
}


int cntEdge = 0;
int ans = 0;
while (!q.empty() && cntEdge < N ) {
  vector<int> curr = q.top();
  q.pop();
  int head1 = findHead(curr[0]);
  int head2 = findHead(curr[1]);
  if (head1 != head2) {
    merge(head1, head2);
    cntEdge++;
    ans += curr[2];
  }
}
if (N != cntEdge ) {
  cout << -1 << endl;
}
else {
  cout << ans << endl;
}
  return 0;
}