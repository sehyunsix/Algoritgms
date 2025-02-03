#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<queue>
#include <string>
#include<math.h>
#define ll long long
#define P 1000000007
#define endl "\n"
#define INF 1000000000;
using namespace std;
int a[1000001];
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  vector<int> v;
  int N;
  cin >> N;
  for (int i = 1; i < 100001; i++) {
    a[i] = INF;
  }
  a[1] = 1;
  a[0] = 0;
  for (int i = 2; i < N+1; i++) {
    for (int j = 1; j * j <= i; j++ ){
          a[i] = min(a[i -j*j]+1 ,a[i]);
      }
  }



  cout << a[N] << endl;
  return 0;
}