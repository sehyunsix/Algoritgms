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
  int N, K;
  int recs[51][4];
  vector<int> gridX;
  vector<int> gridY;
  bool used[100][100];



  bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
      return a.second < b.second;
    }
    return a.first > b.first;
  }

  int getTotalArea(int x1, int y1, int x2, int y2 ) {

    int res = 0;
    int stx = lower_bound(gridX.begin(), gridX.end(), x1) - gridX.begin();
    int enx = lower_bound(gridX.begin(), gridX.end(), x2) - gridX.begin();
    int sty = lower_bound(gridY.begin(), gridY.end(), y1) - gridY.begin();
    int eny = lower_bound(gridY.begin(), gridY.end(), y2) - gridY.begin();
    for (int i = stx; i < enx;i++) {
      for (int j = sty; j < eny;j++) {
        if (used[i][j]) continue;
        used[i][j] = true;
        res += (gridX[i + 1] - gridX[i])*(gridY[j + 1] - gridY[j]);
      }
    }
    return res;
  }

  int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N >> K;
  for (int i = 0;i < N;i++) {
    cin >> recs[i][0] >> recs[i][1] >> recs[i][2] >> recs[i][3];
    gridX.push_back(recs[i][0]);
    gridX.push_back(recs[i][2]);
    gridY.push_back(recs[i][1]);
    gridY.push_back(recs[i][3]);
  }

  sort(gridX.begin(), gridX.end());
  sort(gridY.begin(), gridY.end());


  vector<pair<int,int>> recAreas;
  for (int i = N-1; i > -1; i--) {
    recAreas.push_back({ getTotalArea(recs[i][0], recs[i][1], recs[i][2], recs[i][3]),i });
  }

  sort(recAreas.begin(), recAreas.end(), cmp);

  vector<int> numbers;
  for (int i = 0; i < K; i++) {
    numbers.push_back(recAreas[i].second);
  }

  sort(numbers.begin(), numbers.end());

  for (int i = 0; i < K;i++) {
    cout << numbers[i]+1 << " ";
  }
  cout << endl;


  return 0;
  }