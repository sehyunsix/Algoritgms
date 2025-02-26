#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<queue>
#include <string>
#include<math.h>
#include<map>
#define ll long long
#define endl "\n"
using namespace std;
int D, P;
int prevDp[100001];
int nextDp[100001];
int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
cin >> D >> P;
vector<int> L, C;
for (int j = 0; j <P;j++) {
  int l, c;
  cin >> l >> c;
  L.push_back(l);
  C.push_back(c);
}

for (int j = 0; j<D+1;j++) {
  prevDp[j] = -1;
}

prevDp[0] = INT32_MAX;
for (int i = 1; i <= P;i++) {
  for (int j = 0; j < D + 1;j++) {
    if (prevDp[j] != -1) nextDp[j] = prevDp[j];
    if (j - L[i] >= 0 && prevDp[j - L[i]] != -1) {
      nextDp[j] = max(min(prevDp[j - L[i]], C[i]), nextDp[j]);
    }
  }
  for( int j =0 ; j<D+1; j++){
    prevDp[j] = nextDp[j];
  }
}

cout << prevDp[D] << endl;

return 0;
}