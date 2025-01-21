#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<queue>
#include <string>
#include<math.h>
#define ll long long
#define P 1000000007
using namespace std;

bool m[10000][10000];

int p2[20];

void draw_tri(int r, int c, int level) {

  if (level == 0) {
    m[r][c] = 1;
    m[r + 1][c - 1] = 1;
    m[r + 1][c + 1] = 1;
    for( int i =0 ; i<5; i++){
      m[r + 2][c - 2+i] = 1;
    }
    return;
  }
  draw_tri(r, c, level - 1);
  draw_tri(r + 3 * p2[level - 1], c - 3 * p2[level - 1], level - 1);
  draw_tri(r + 3 * p2[level - 1], c + 3 * p2[level - 1], level - 1);
  return ;
}

int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
int N ,M;
cin >> N;
M = N - 1;
p2[0] = 1;
for( int i =1 ; i<21; i++){
  p2[i] = 2 * p2[i - 1];
}
int tmp = N / 3;
int level = 0;

while (tmp > 1) {
  tmp = tmp / 2;
  level += 1;
}

draw_tri(0, N - 1, level);

for (int i = 0; i < N; i++) {
  for (int j = 0; j < 2*M+1;j++) {
    if (m[i][j]) {
      cout << "*";
    }
    else {
      cout << " ";
    }
  }
  cout << endl;
}



return 0;
}