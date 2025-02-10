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
int N ,K ;

vector<vector<int>> distance_list;
vector<pair<int, int>> pos_list;
bool query(int fuel) {
  vector<vector<int>> edge_list(N+2, vector<int>());
  for (int i = 0; i < N + 1; i++) {
    for (int j = i+1; j < N + 2; j++) {
      if (fuel >= distance_list[i][j]) {
          edge_list[i].push_back(j);
          edge_list[j].push_back(i);
      }
    }
  }
  vector<int> visited(N + 2, INT32_MAX);
  queue<int> q;
  q.push(0);
  visited[0] = 0;
  int next;
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    for (auto next : edge_list[curr]) {
      if (visited[next] == INT32_MAX) {
        q.push(next);
        visited[next]=visited[curr]+1;
      }
    }
  }
  // cout << fuel << " " << visited[pos_list.size() - 1] << endl;
  return (visited[pos_list.size()-1] <= K+1);

}

int cal_distance(pair<int, int> a, pair<int, int> b) {
  return (int)sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second))/10 + 1;
}

int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
cin >> N >> K;
distance_list = vector<vector<int>>(N + 2, vector<int>(N + 2, INT32_MAX));
pos_list.push_back({ 0,0 });
for(int i=0; i<N; i++){
  int x , y;
  cin>> x >> y;
  pos_list.push_back({ x,y });
}
pos_list.push_back({ 10000,10000 });

// for(auto pos :pos_list){
//   cout << pos.first << " " << pos.second << endl;
// }
for (int i = 0; i < N + 1;i++) {
  for (int j = i+1; j < N + 2;j++) {
    distance_list[i][j] = cal_distance(pos_list[i], pos_list[j]);
  }
}

// for (int i = 0; i < N + 2;i++) {
//   for (int j =0; j < N + 2;j++) {
//     cout << distance_list[i][j] << " ";
//   }
//   cout << endl;
// }

int st = 0;
int en = 1000000001;
int mid;
while (st < en) {
  mid = (st + en) / 2;
  // cout << mid << endl;
  if (query(mid)) {
    // cout << "correct" << endl;
    en = mid;
    }
    else {
      st = mid + 1;
    }
}
cout << en << endl;

return 0;
}