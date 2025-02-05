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
bool m[7000][7000];

void f(int r, int c, int n) {
  // cout << n << endl;
  if (n == 3) {
    // cout <<r <<" "<< c<< endl;
    for (int i = 0; i < 3;i++) {
      for (int j = 0; j < 3;j++) {
        if (!(i == 1 && j == 1)) {
          m[r + i][c + j] = 1;
        }
      }
      }
      return;
  }

  for(int i=0; i<3;i++){
    for(int j=0; j<3; j++){
      if (!(i == 1 && j == 1)) {
        // cout << r + i * n / 3 << " " << c + j * n / 3 << " " << n << endl;
        f(r + i * n / 3, c + j * n / 3, n / 3);
      }
    }
  }
  return;
}
int main() {
  cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);

cin >> N;
f(0, 0, N);

for(int i=0; i<N;i++){
  for (int j = 0; j < N;j++) {
    if (m[i][j] == 1) {
      cout << "*";
    }
    else{
      cout <<" ";
    }
  }
  cout << endl;
}

return 0;
}