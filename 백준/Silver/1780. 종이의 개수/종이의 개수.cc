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

int N;
int m[5000][5000];
int count_minus, count_zero, count_one;
void f(int r, int c, int l) {
  // cout << r << " " << c << " " << l << endl;
  int prev = m[r][c];
  bool chk = true;
  for (int i = 0; i < l; i++) {
    if(!chk){
      break;
    }
    for (int j = 0; j < l; j++) {
      if(prev != m[r + i][c + j]){
        chk = false;
          break;
      }
    }
  }
  // cout << prev << endl;


  if (prev== 1 && chk) {
    count_one++;
    return ;
  }

  if (prev == -1 && chk) {
    count_minus++;
    return ;
  }

  if (prev==0 && chk) {
    count_zero++;
    return ;
  }

  for (int k = 0; k < 3; k++) {
    for (int j = 0; j < 3; j++) {
      f(r + k * l / 3, c + j * l / 3, l / 3);
    }
  }



  return;

}

int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);

cin >> N;
for (int i = 0; i < N; i++) {
  for(int j=0; j<N;j++){
    int tmp;
    cin >> tmp;
    m[i][j] = tmp;
  }
}

f(0, 0, N);

cout << count_minus << endl;
cout << count_zero << endl;
cout << count_one << endl;

return 0;
}