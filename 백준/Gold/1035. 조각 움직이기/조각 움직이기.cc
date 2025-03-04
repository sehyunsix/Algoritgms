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
int N;
int ans = INT32_MAX;
int visited[10][5][5];
bool dfsVisited[25];
int board[5][5];
int dxdy[4][2] = {
  {-1,0},
  {1,0},
  {0,-1},
  {0, 1},
};

vector<int> nodes;
vector<int> parents;
vector<int> groupSize;

int findHead(int x){
  if(x==parents[x]) return x;
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

bool checkAdj(vector<int>& nodes) {
  for (int j = 0; j < N;j++) {
    parents[j]=j;
    groupSize[j] = 1;
  }
  for (int i = 0; i < N - 1;i++) {
    for (int j = i + 1; j < N;j++) {
      int r1 = nodes[i] / 5;
      int c1 = nodes[i] % 5;
      int r2 = nodes[j] / 5;
      int c2 = nodes[j] % 5;
      if (abs(r1 - r2) + abs(c1 - c2) == 1) {
        // cout << "merge :" << i << " "<< j << endl;
        merge(i, j);
       }
    }
  }

  int root = findHead(0);
  for (int j = 1; j < N; j++) {
    if (findHead(j) != root) return false;
  }
  return true;
}


void dfs( int level, int sum) {

  if (level == N) {
    if (checkAdj(nodes)) {

      ans = min(ans, sum);
      // cout << "groupSize : ";
      // for (auto size : groupSize) {
      //   cout << size << " ";
      // }
      // cout << endl;
      // cout << "parents : ";
      // for (auto parent : parents) {
      //   cout << parent << " ";
      // }
      // cout << endl;
      // cout << "nodes : ";
      // for (auto node : nodes) {
      //   cout << node << " ";
      // }
      // cout << endl;
      // cout << "ans : " << ans << endl;
    }
    return;
  }
      for (int i = 0; i < 25; i++) {
        if (!dfsVisited[i]) {
          dfsVisited[i] =1;
          nodes.push_back(i);
          dfs(level + 1, sum + visited[level][i / 5][i % 5]);
          nodes.pop_back();
          dfsVisited[i] =0;
        }
      }
}


int main() {

cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);

vector<pair<int,int>> pieces;
for (int i = 0;i <5;i++) {
  for (int j = 0; j < 5;j++) {
    char tmp;
    cin >> tmp;
    if(tmp =='*') pieces.push_back({i,j});
  }
}


N= pieces.size();
fill(&visited[0][0][0], &visited[0][0][0] + 10 * 5 * 5, -1);
parents = vector<int>(N, 0);
groupSize = vector<int>(N, 0);

for (int s = 0; s<N; s++) {
  pair<int, int> start = pieces[s];
  queue<pair<int, int>> q;
  q.push(start);
  visited[s][start.first][start.second] =  0;
  while (!q.empty()) {
    pair<int, int> curr = q.front();
    q.pop();
    for(int i=0; i<4;i++){
      pair<int, int> next = { curr.first + dxdy[i][0], curr.second + dxdy[i][1] };
      if (next.first < 0 || next.first >= 5 || next.second < 0 || next.second >= 5)continue;
      if (visited[s][next.first][next.second] != -1)continue;
      visited[s][next.first][next.second] = visited[s][curr.first][curr.second] + 1;
      q.push(next);
    }
  }
}
// for (int s = 0; s < (int)pieces.size(); s++) {
//   cout << "=======" << endl;
//   for (int i = 0; i < 5;i++) {
//     for (int j = 0; j < 5;j++) {
//       cout << visited[s][i][j] << " ";
//     }
//     cout << endl;
//   }
// }
memset(dfsVisited, 0, sizeof(dfsVisited));
dfs(0, 0);
cout << ans << endl;
// 120 * 12650  25*24*23*22*21
return 0;
}