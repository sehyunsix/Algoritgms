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

int dxdy[8][2] =
{
{ -2 ,-1 },
{ -2, 1 },
{ -1 ,2 },
{ -1, -2 },
{ 2 ,-1 },
{ 2, 1 },
{ 1 ,2 },
{ 1, -2 },
};

int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);


int T;
cin >> T;
for (int t = 0; t < T; t++) {
  int N;
  cin >> N;
  pair<int, int> st;
  pair<int, int> en;
  cin >> st.first >> st.second;
  cin >> en.first >> en.second;

  vector<vector<int>> visited(N, vector<int>(N, -1));

  queue<pair<int,int>> q;
  q.push(st);
  visited[st.first][st.second] =0;
  pair<int, int> next;
  pair<int, int> curr;
  while (!q.empty()) {
    curr = q.front();
    q.pop();
    for (int i = 0; i < 8;i++) {
      next = { curr.first + dxdy[i][0] , curr.second + dxdy[i][1] };
      if (next.first < 0 || next.first >= N || next.second < 0 || next.second >= N || visited[next.first][next.second] != -1) {
        continue;
      }
      q.push(next);
      visited[next.first][next.second] = visited[curr.first][curr.second] + 1;
    }
  }
  cout << visited[en.first][en.second] << endl;





}


return 0;
}