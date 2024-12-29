#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<queue>
#include <string>
#include<math.h>
#define ll long long
using namespace std;

bool isleaf[200001];
int levels[200001];
queue<int> q;

int main() {

  int N;
  cin >> N;
  int max_level = 0;

  vector<int> edge_list[N+1];



  for (int i = 0; i < N-1; i++) {
    int a, b;
    cin >> a >> b;
    if (edge_list[a].size() == 3 | edge_list[b].size() == 3) {
      cout << -1;
      return 0;
    }
    edge_list[a].push_back(b);
    edge_list[b].push_back(a);
  }

  if (((N - 1) % 3) != 0) {
    // cout << "not vaild edge size N" << endl;
    cout << -1;
    return 0;
  }

  int tmp = 0;
  int m = (N - 1) / 3;
  while (m > 0) {
    if ((m+1) % 2 != 0) {
      cout << -1;
      return 0;
    }
    m = m / 2;
    max_level += 1;
  }
  // cout << "max level : "<< max_level << endl;

  for (int i = 1; i < N + 1; i++) {
    if (edge_list[i].size() == 1) {
      isleaf[i] = true;
      levels[i] = 0;
      q.push(i);
    }
    else if (edge_list[i].size() != 3) {
      // cout << "not vaild edge size" << endl;
      cout << -1;
      return 0;
    }
  }


  while (!q.empty()) {
   int node = q.front();
    q.pop();
    for (int e : edge_list[node]) {
      if (!isleaf[e]) {
        q.push(e);
        isleaf[e] = true;
        levels[e] = levels[node] + 1;
      }
    }
  }

  int max_num = 0;
  int ans = 0;

  for (int i = 1; i < N + 1; i++) {
    if (max_num < levels[i]) {
      max_num = levels[i];
      ans = i;
    }
  }

  // cout << "level : ";
  // for (int i = 1; i < N + 1; i++) {
  //   cout << levels[i] << " ";
  // }
  // cout << endl;
  if (max_level == max_num) {

      cout << 1 << endl;
      cout << ans << endl;

    }
  else {
    cout << -1;
  }



  return 0;
}