#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<queue>
#include <string>
#include<math.h>
#include<map>
#include<stack>
#define ll long long
#define P 1000000007
#define endl "\n"
using namespace std;
int N, M, cnt;
vector<vector<int>> childs;
vector<int> discovers;
stack<int> s;
vector<bool> finished;

int  dfs(int node , bool& answer) {
  s.push(node);
  discovers[node] = cnt++;

  int parent = discovers[node];
  for (auto c : childs[node]) {
    if (discovers[c] == -1) {
      parent = min(parent, dfs(c,answer));
    }
    else if (!finished[c]) {
      parent = min(parent, discovers[c]);
    }
  }

  if (parent  == discovers[node]) {
    vector<bool>isCycle(2*N + 1, 0);
    int tmp;
    do {
      tmp = s.top();
      s.pop();
      finished[tmp] = true;
      int target = (tmp > N ? tmp - N : tmp + N);
      if (isCycle[target]) answer = false;
      else isCycle[tmp] = true;
    } while (tmp != node);
  }

  return parent;

}

int main() {

cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);


cin >> N >> M;

childs.resize(2 * N + 1);
discovers = vector<int>(2 * N + 1, -1);
finished = vector<bool>(2 * N + 1, 0);


for (int i = 0; i < M; i++) {
  int x, y;
  cin >> x >> y;

  int tmpx = (-x > 0) ? -x : abs(x) + N;
  int tmpy= (y > 0) ? y : abs(y) + N;
  childs[tmpx].push_back(tmpy);
  if (x == y) continue;
  tmpx = (x > 0) ? x : abs(x) + N;
  tmpy = (-y > 0) ? -y : abs(y) + N;
  childs[tmpy].push_back(tmpx);
}

bool answer = true;

for (int j = 1; j < 2 * N + 1;j++) {
  if (!finished[j]) {
    dfs(j, answer);
  }
}

cout << answer << endl;
return 0;
}