#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<queue>
#include <string>
#include<math.h>
#define ll long long
#define P 1000000007;
using namespace std;
int map[20][20];
int visited[20][20];
int size_number_list[10];
int dxdy[4][2] = {
  {-1,0},
  {0,-1},
  {0,1},
  {1,0},

};
int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);

int N, p_c, t, size, s_r, s_c, e_c;
p_c = 0;
t = 0;
size = 2;
s_r = 0;
s_c = 0;
e_c = 0;
cin >> N;

for (int i = 0; i < N; i++) {
  for( int j =0 ; j<N; j++){
    cin >> map[i][j];
    if (map[i][j] == 9) {
      map[i][j] = 0;
      s_r = i;
      s_c = j;
    }
    else if (map[i][j] !=0 ) {
      p_c += 1;
    }
  }
}
// queue<pair<int, int>> q;
// q.push({ s_r, s_c });
while (p_c > 0) {


  for (int i = 0; i < N; i++) {
    for( int j =0 ; j<N ;j++){
      visited[i][j] = 0;
    }
  }

  queue<pair<int, int>> q;
  q.push({ s_r,s_c });
  while (!q.empty()) {
    pair<int, int> node = q.front();
    // cout << t << endl;
    q.pop();
    for (int i = 0; i < 4;i++) {
      pair<int, int> next = { node.first  + dxdy[i][0] , node.second + dxdy[i][1]};
      if (0 <= next.first && next.first < N && 0 <= next.second && next.second < N && map[next.first][next.second] <= size && !visited[next.first][next.second]) {
        visited[next.first][next.second] = visited[node.first][node.second] + 1;
        q.push({ next.first ,next.second });
      }
    }
  }
  int m = INT32_MAX;
  int m_r, m_c;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N;j++) {
      if (0 < map[i][j] && map[i][j] < size && m > visited[i][j] && visited[i][j] >0) {
        m_r = i;
        m_c = j;
        m = visited[i][j];
      }
      }
  }

  if (m != INT32_MAX) {
      // cout << "eat " << m_r << " " << m_c << " " << map[m_r][m_c] << " " << size << " " << visited[m_r][m_c] << endl;
      map[m_r][m_c] = 0;
      t += visited[m_r][m_c];
      s_r = m_r;
      s_c = m_c;
      p_c -= 1;
      e_c += 1;
      if (size == e_c) {
        size += 1;
        e_c = 0;
      }
  }
  else {
    break;
  }



  p_c = 0;
  for (int i = 0; i < N; i++) {
    for( int j =0 ; j<N ;j++){
      if (0 < map[i][j] && map[i][j] < size) {
        p_c += 1;
      }
    }
  }

}

cout << t;

return 0;
}
