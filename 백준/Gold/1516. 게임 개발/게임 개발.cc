#include<iostream>
#include<vector>

using namespace std;


typedef struct info {

  int time;
  vector<int> edge_list;

}info;

int N;
int dp[501] = { -1, };
info info_list[501];




int solv(int n) {

  if (dp[n] > 0) {
    return dp[n];
  }
  int max = 0;
  int  res = 0;
  for (int i = 0; i < info_list[n].edge_list.size();i++) {
    res = solv(info_list[n].edge_list[i]);
    if (max < res) {
      max = res;
    }
  }
  dp[n] = max+info_list[n].time;
  return dp[n];
}


int main() {

  cin >> N;
  for (int i = 0; i < N; i++) {
    int tmp;

    cin >> tmp;
    info_list[i + 1].time = tmp;
    while (true) {
      cin >> tmp;
      if (tmp == -1) {
        break;
      }
      info_list[i + 1].edge_list.push_back(tmp);
    }


  }


  for (int i = 1; i < N + 1;i++) {
    solv(i);
  }

  for (int i = 1; i < N + 1;i++) {
    cout << dp[i] << endl;
  }

}
