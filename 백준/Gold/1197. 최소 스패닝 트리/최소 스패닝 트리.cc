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
int N, V;
vector<vector<int>> edges;
int parents[10001];
int groupSize[10001];

bool cmp(vector<int>& a, vector<int>& b) {
  return a[2] < b[2];
}

int findHead(int x) {
  if (x == parents[x]) return x;
  parents[x] = findHead(parents[x]);
  return parents[x];
}

void merge(int x, int y) {
  int headX = findHead(x);
  int headY = findHead(y);
  if (groupSize[headX] < groupSize[headY]) swap(headX, headY);
  parents[headY] = headX;
  groupSize[headX] += groupSize[headY];
  return;
}


int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
cin >> N >> V;

for (int j = 1; j <N+1;j++) {
  parents[j] = j;
}
for (int j = 1; j < N + 1;j++) {
  groupSize[j] = 1;
}

for (int i = 0; i < V;i++) {
  int x, y, z;
  cin >> x >> y >> z;
  edges.push_back({ x,y,z });
}

sort(edges.begin(), edges.end(), cmp);
int ans = 0;
int cntEdge = 0;
for (int i = 0; i < (int)edges.size()&& cntEdge<N-1;i++) {
  int headA = findHead(edges[i][0]);
  int headB = findHead(edges[i][1]);

  if (headA == headB) continue;
  merge(headA, headB);
  ans += edges[i][2];
  cntEdge++;
}
cout << ans << endl;

return 0;
}