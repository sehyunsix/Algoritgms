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

char m[1500][1500];
int visited[1500][1500];
int dxdy[4][2] = {
  {-1,0},
  {1,0},
  {0,-1},
  {0,1},
};
int N, M;
vector<pair<int, int>> birds;

bool query(int x) {
  vector<vector<bool>> tmp_visited(N, vector<bool>(M, 0));
  pair<int, int> st = birds[0];
  pair<int, int> en = birds[1];
  queue<pair<int,int>> q;
  q.push(st);
  tmp_visited[st.first][st.second] =true;
  while (!q.empty()) {
    pair<int, int> curr = q.front();
    q.pop();
    for (int i = 0;i < 4;i++) {
      pair<int, int> next = { curr.first + dxdy[i][0] ,curr.second + dxdy[i][1] };
      // cout<< next.first << " "<<next.second<< endl;
      if (next.first < 0 || next.first >= N || next.second < 0 || next.second >= M) {
        continue;
      }
      if (tmp_visited[next.first][next.second]) {
        continue;
      }
      if (visited[next.first][next.second] > x) {
        continue;
      }
      q.push(next);
      tmp_visited[next.first][next.second] = true;
    }
  }

  // for(int i=0; i<N;i++){
  //   for (int j = 0; j < M; j++) {
  //     cout << tmp_visited[i][j] << endl;
  //   }
  // }

  // cout <<x  <<" "<< tmp_visited[en.first][en.second] << endl;
  return tmp_visited[en.first][en.second];
}

int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
cin >> N >> M;

for(int i=0; i<N;i++){
  for(int j=0; j<M;j++){
    cin >> m[i][j];
  }
}

for(int i=0; i<N;i++){
  for(int j=0; j<M;j++){
    visited[i][j] = INT32_MAX;
  }
}

queue<pair<int, int>> q;
for (int i = 0; i < N; i++) {
  for(int j=0; j<M;j++){
    if (m[i][j] == '.' || m[i][j]=='L') {
      q.push({ i,j });
      visited[i][j] = 0;
    }
    if(m[i][j]=='L'){
      birds.push_back({ i,j });
    }
  }
}

while (!q.empty()) {
  pair<int, int> curr = q.front();
  q.pop();
  for (int i = 0; i < 4;i++) {
    pair<int, int> next = { curr.first + dxdy[i][0] , curr.second + dxdy[i][1] };
    if (next.first < 0 || next.first >= N || next.second < 0 || next.second >= M) {
      continue;
    }
    if (visited[next.first][next.second] != INT32_MAX) {
      continue;
    }

    q.push({ next.first,next.second });
    visited[next.first][next.second] = visited[curr.first][curr.second] + 1;
  }
}

int st = 0;
int en = 3001;

while (st < en) {
  int mid = (st + en) / 2;
  if (query(mid)) {
    en = mid;
  }
  else {
    st = mid + 1;
  }
}

cout << en << endl;


return 0;
}