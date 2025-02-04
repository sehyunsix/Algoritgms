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
int m[N + 1][N + 1];
int a[N][N];

for (int i = 0; i < N + 1;i++) {
  for (int j = 0; j < N+1;j++) {
    m[i][j] = 0;
  }
}


for( int i =0 ; i<N ;i++){
  for( int j =0 ; j<N ;j++){
    cin >> a[i][j];
  }
}

for (int i = 0; i < N;i++) {
  for (int j = 0; j < N; j++) {
    m[i + 1][j + 1] = m[i + 1][j] + m[i][j + 1] - m[i][j] + a[i][j];
  }
}

for (int i = 0; i <M; i++) {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  cout << m[x2][y2] - m[x1-1][y2] - m[x2][y1-1] + m[x1-1][y1-1] << endl;
}




return 0;
}