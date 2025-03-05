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
int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);

int N, M;
cin >> N >> M;

vector<int> q(N,0);
for( int j =0 ; j<N ;j++){
  q[j] = j + 1;
}
int ans = 0;
for (int j = 0; j < M;j++) {
  int tmp;
  cin >> tmp;
  int idx = -1;

  for (int i = 0; i < q.size(); i++) {
    if (q[i] == tmp) idx = i;
  }
  // cout << "queue :  ";
  // for (auto e : q) {
  //   cout << e << " ";
  // }
  // cout << endl;

  if (idx == 0) {
    q.erase(q.begin());
    continue;
  }


  if (idx < q.size() - idx) {
    int cntLeftMove = idx;
    while (cntLeftMove--) {
      ans++;
      int tmp = q.front();
      q.erase(q.begin());
      q.push_back(tmp);
    }
  }
  else {
    int cntRightMove = q.size() - idx;
    while (cntRightMove--) {
      ans++;
      int tmp = q.back();
      q.pop_back();
      q.insert(q.begin(), tmp);
      // cout << cntRightMove <<"move right queue :  ";
      // for (auto e : q) {
      //   cout << e << " ";
      // }
      // cout << endl;

    }
  }

  q.erase(q.begin());


}

cout << ans << endl;
return 0;
}