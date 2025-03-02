
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
int N, M;
int dis[201][201];
vector<vector<int>> adj;

int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
// 제일 큰 높이가 가장 작은 weight를 가지는 경로를 찾아야됨
// 정점이 모두 타는 시간 != 간선이 모두 타는 시간
// 간선 중에 제일 늦게 타는 간선은 길이가 가장 긴 간선?
//
cin >> N >> M;

for (int j = 0; j < N;j++) {
  for (int i = 0; i < N; i++) {
    if (i == j) dis[i][j] = 0;
    else dis[i][j] = INT32_MAX;

  }
}


for (int i = 0; i < M; i++) {
  int x, y, w;
  cin >> x >> y >> w;
  adj.push_back({ x-1,y-1,w });
  dis[x - 1][y - 1] = min(dis[x - 1][y - 1], w);
  dis[y - 1][x - 1] = min(dis[y - 1][x - 1], w);
}

for (int k = 0; k < N;k++) {
  for( int i =0 ; i<N; i++){
    for (int j = 0; j < N;j++) {
      if (dis[i][k] != INT32_MAX && dis[k][j] != INT32_MAX)
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      // cout << i << " " << j << " "<< k <<" " << dis[i][k] << " " << dis[k][j] << endl;
    }
 }
}

// for (int i = 0; i < N; i++) {
//   for (int j = 0; j < N;j++) {
//     cout<<  dis[i][j] << " ";
//   }
//   cout << endl;
// }
double ans = INT32_MAX;
for (int i = 0; i < N; i++) {
  double maxLiveTime = 0;
  double res = 0;
  for (int j = 0; j < M;j++) {
    double l = adj[j][2];
    double t1 = dis[i][adj[j][0]];
    double t2 = dis[i][adj[j][1]];
    if (t1 > t2) swap(t1, t2);
    if (t2 - t1 < l) res =t2+ (l - (t2 - t1)) / 2.0;
    else res = t1+ l;
    maxLiveTime = max(maxLiveTime, res);
  }
  // cout << maxLiveTime << endl;
  ans = min(maxLiveTime, ans);
}
cout << fixed;
cout.precision(1);
cout << ans << endl;
return 0;
}