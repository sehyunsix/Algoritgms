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
  char board[10][10];
  int N, M;
  vector<pair<int, int>> dirList;

  int bfs(int s_r, int s_c) {

    vector<int> resList;
    for (auto dir : dirList) {
      string tmp = "";
      queue<pair<int, int>> q;
      q.push({ s_r,s_c });
      while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        tmp = tmp + board[curr.first][curr.second];
        // cout << tmp << endl;
        if (sqrt(stol(tmp)) - (long long)sqrt(stol(tmp)) < 0.000001) {
          // cout << "제곱 수 : " << tmp << endl;
          resList.push_back(stol(tmp));
        }
        pair<int, int> next = { curr.first + dir.first ,curr.second + dir.second };
        if (next.first < 0 || next.first >= N || next.second < 0 || next.second >= M) continue;
        q.push(next);
      }
    }

    if (resList.empty()) return -1;
    sort(resList.begin(), resList.end(), greater<int>());
    return resList[0];
  }
  int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    string row;
    for (int i = 0; i < N; i++) {
      cin >> row;
      for (int j = 0; j < M;j++) {
        board[i][j] = row[j];
      }
    }

    for (int r_d = -9; r_d < 9; r_d++) {
      for (int c_d = -9; c_d < 9; c_d++) {
        if (r_d == 0 && c_d == 0) continue;
        dirList.push_back({ r_d,c_d });
      }
    }

    vector<int> resultList;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M;j++) {
        resultList.push_back(bfs(i, j));
      }
    }

  sort(resultList.begin(), resultList.end(), greater<int>());
  cout << resultList[0] << endl;
  return 0;
  }