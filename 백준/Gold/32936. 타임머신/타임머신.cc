#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<queue>
#include <string>
#include<math.h>
#define ll long long
using namespace std;

vector<int> edge_list[200001];
int dis[200001];
int disB[200001];
int disN[200001];


queue<int> q;

int main() {
  int N, M, a, b, c;
  cin >> N >> M >> a >> b >> c;


  for( int i =0 ; i<N+1; i++){
    dis[i] = -1;
    disB[i] = -1;
    disN[i] = -1;
  }

  for (int i = 0; i < M; i++) {
    int prev, next;
    cin >> prev >> next;
    edge_list[prev].push_back(next);
  }

  q.push(1);
  dis[1]=0;


  while (!q.empty()) {
    int node = q.front();
    q.pop();
    for (int e : edge_list[node]) {
      if (dis[e] == -1) {
        dis[e] = dis[node] + 1;
        q.push(e);
      }
    }
  }

  disB[b] = 0;
  q.push(b);

  while (!q.empty()) {
    int node = q.front();
    q.pop();
    for (int e : edge_list[node]) {
      if (disB[e] == -1) {
        disB[e] = disB[node] + 1;
        q.push(e);
      }


    }
  }

  disN[N] = 0;
  q.push(N);

  while (!q.empty()) {
    int node = q.front();
    q.pop();
    for (int e : edge_list[node]) {
      if (disN[e] == -1) {
        disN[e] = disN[node] + 1;
        q.push(e);
      }
    }
  }

  if (dis[a] == -1 | disB[N] == -1 ) {
    if (dis[N] == -1) {
      cout << "x" << endl;
    }
    else {
      cout << dis[N] << endl;
    }
  }
  else {

    if ( (disN[a] >0 | disB[a]>0) && disB[a] < c) {
      cout << "-inf" << endl;
    }
    else {

      int ans = min(dis[a] + disB[N] - c, dis[N]);
      cout << ans << endl;

    }

  }






}