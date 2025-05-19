#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;
bool visited[24][5];

map<string, int> day = {
  {"MON", 0},
  {"TUE", 1},
  {"WED", 2},
  {"THU", 3},
  {"FRI", 4}
};

int main() {

  // 모든 경우의 수업의 수를 만들었을때를 파악해야한다. 2^10이므로 가능

  int N, M;
  cin >> N >> M;
  vector<vector<pair<int, int>>> classList(N, vector<pair<int, int>>());
  vector<int> classScore(N, 0);

  for (int i = 0; i < N; i++) {
    int  number, score;
    cin >> score >> number;
    classScore[i] = score;
    for (int j = 0; j < number; j++) {
      string dayStr;
      int start;
      cin >> dayStr >> start;
      classList[i].push_back({ day[dayStr] ,start });
    }
  }



  // for (int i = 0; i < N; i++) {

  //   for (auto classInfo : classList[i]) {
  //     cout << classInfo.first << " " << classInfo.second <<" /";
  //   }
  //   cout << endl;
  // }

  int maxScore = 0;
  int possiblites = 1 << N;
  for (int k = 0; k < possiblites; k++) {
    int tmpScore = 0;
    bool success = true;
    for (int r = 0; r < 24;r++) {
      for (int c = 0; c < 5;c++) {
        visited[r][c] = false;
      }
    }

    // cout << "check" << endl;
    for (int i = 0; i < N; i++) {
      if (k & (1 << i)) {
          for (pair<int,int> classInfo : classList[i]) {
            int day = classInfo.first;
            int start = classInfo.second;
            if (visited[start][day] == 1) {
              // cout<<"fail" << i ;
              success = false;
              break;
            }
            visited[start][day] = true;
          }
          if (!success) break;
          // cout << i;
          tmpScore += classScore[i];
        if (success) {
          // cout << "success" << tmpScore << endl;
          maxScore = max(tmpScore, maxScore);
        }
      }
    }
    // cout << endl;


  }

  cout << (maxScore >= M?"YES":"NO" ) << endl;

}

