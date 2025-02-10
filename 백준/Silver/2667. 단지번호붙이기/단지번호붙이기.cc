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
int dxdy[4][2] = {
  {1,0},
  {-1,0},
  {0,1},
  {0,-1},
};

int m[30][30];
bool visited[30][30];

int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);

int N;
cin >> N;
vector<int> visited_numbers;
for (int i = 0; i < N; i++) {
  for (int j = 0; j < N; j++) {
    char c;
    cin >> c;
    m[i][j] = c - '0';
  }
}

for (int i = 0; i < N; i++) {
  for (int j = 0; j < N; j++) {
    if (m[i][j] == 1 && !visited[i][j]) {
      // cout << "start :"<< i << " " << j << endl;;
      queue<pair<int, int>> q;
      q.push({ i,j });
      visited[i][j] = 1;
      int visited_num = 0;
      while (!q.empty()) {
        pair<int, int> curr = q.front();
        // cout << curr.first << " "<<curr.second << endl;
        visited_num++;
        q.pop();
        for( int i =0 ; i<4; i++){
          pair<int, int> next = { curr.first + dxdy[i][0]  ,curr.second + dxdy[i][1] };
          if (next.first < 0 || next.first >= N || next.second < 0 || next.second >= N || m[next.first][next.second] == 0 || visited[next.first][next.second]) {
            continue;
          }
          q.push(next);
          visited[next.first][next.second] = 1;
        }
      }
      visited_numbers.push_back(visited_num);
    }
  }
}
cout <<visited_numbers.size() << endl;
sort(visited_numbers.begin(), visited_numbers.end());
for (auto n : visited_numbers) {
  cout << n << endl;
}

return 0;
}