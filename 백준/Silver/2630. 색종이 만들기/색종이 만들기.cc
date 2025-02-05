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
int N, w_c, b_c;
bool m[128][128];
int f(int r, int c, int l) {

  if (l == 1) {
    if (m[r][c] == 1) return 1;
    else return 0;
  }

  int tmp[2] = { 0,0 };

  int res = -1;
  res = f(r, c, l / 2);
  if (res != -1)tmp[res]++;
  res = f(r + l / 2, c, l / 2);
  if (res != -1)tmp[res]++;
  res = f(r, c + l / 2, l / 2);
  if (res != -1) tmp[res]++;
  res = f(r + l / 2, c + l / 2, l / 2);
  if (res != -1)  tmp[res]++;


  if (tmp[0] == 4) return 0;
  else if (tmp[1] == 4) return 1;
  w_c += tmp[0];
  b_c += tmp[1];
  return -1;
}


int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
cin >> N;
for (int j = 0; j <N ;j++) {
  for( int i =0 ; i<N; i++){
    cin >> m[i][j];
  }
}

int res =f(0, 0, N);
if (res == 1)  b_c += 1;
if (res == 0)  w_c += 1;
cout << w_c << endl;
cout << b_c << endl;


return 0;
}