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
int N, M ,ans, cntCivil,cntNight;
int scores[16];
int adj[16][16];
bool died[16];

void dfs(int level) {
  // cout << "died : ";
  // for (int j = 0; j < N;j++) {
  //   cout<< died[j] << " ";
  // }
  // cout << endl;
  if (died[M] || cntCivil == 0) {
    ans = max(cntNight, ans);
    return;
  }
  if (cntCivil % 2 == 0) {
    // cout << "morning " << endl;
    int maxIdx = -1;
    int maxScore = INT32_MIN;
    for (int i = 0; i < N;i++) {
      if (died[i]) continue;
      if (maxScore < scores[i]) {
        maxScore = scores[i];
        // cout << "score :" << scores[i] << endl;
        maxIdx = i;
      }
    }
    // cout << "died : " << maxIdx << endl;
    died[maxIdx] = 1;
    if (M != maxIdx) cntCivil--;

    dfs(level + 1);

    died[maxIdx] = 0;
    if (M != maxIdx) cntCivil++;
  }
  else {
    for (int i = 0; i < N;i++) {
      // cout << "night : "<< i << endl;
      if (died[i] || i == M) continue;
      // cout << "died : " << i <<"cntCivil :" << cntCivil << endl;
      died[i] = 1;
      for (int j = 0; j < N;j++) {
        if (died[j]) continue;
        scores[j] += adj[i][j];
      }
      cntCivil--;
      cntNight++;

      dfs(level + 1);

      cntNight--;
      cntCivil++;
      for (int j = 0; j < N;j++) {
        if (died[j]) continue;
        scores[j] -= adj[i][j];
      }
      died[i] = 0;

    }

  }

  // return;
}

int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);

cin >> N;
cntCivil = N - 1;
for (int i = 0; i < N;i++) {
  cin >> scores[i];
}

for (int i = 0;i < N;i++) {
  for (int j = 0; j < N; j++) {
    cin >> adj[i][j];
  }
}

cin >> M;
dfs(0);
cout << ans << endl;


return 0;
}