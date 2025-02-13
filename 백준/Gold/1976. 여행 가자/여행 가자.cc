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

int findHead(int x) {
  if (x == parent[x]) return x;
  parent[x] = findHead(parent[x]);
  return parent[x];
}

void merge(int x, int y) {
  parent[findHead(x)] = parent[findHead(y)];
 }

int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);



int N, M;
cin >> N >> M;
parent = vector<int>(N, 0);
bool adj[N][N];

for (int i = 0; i < N;i++) {
  parent[i] = i;
}


for (int i = 0; i < N;i++) {
  for (int j = 0; j < N; j++) {
    bool tmp;
    cin >> adj[i][j];
  }
}

for (int i = 0; i < N-1;i++) {
  for (int j = i + 1; j < N; j++) {
    if (adj[i][j]) {
      merge(i, j);
    }
  }
}

int prev = -1;
for (int i = 0; i < M; i++) {
  int tmp;
  cin >> tmp;
  if (prev == -1) {
    prev = findHead(tmp-1);
    continue;
  }
  if (prev != findHead(tmp-1)) {
      cout << "NO" << endl;
      return 0;
    }

}

cout << "YES" << endl;



return 0;
}