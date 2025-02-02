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
using namespace std;

// 1 2 3 1
// x1 x2 x3 x1
// y1 y2 y3 y1

int CCW(pair<ll, ll> A, pair<ll, ll> B, pair<ll, ll> C) {

  ll res = (A.first * B.second + B.first * C.second + C.first * A.second) - (A.second * B.first + B.second * C.first + C.second * A.first);
  if (res == 0) {
    return 0;
  }
  else if (res > 0) {
    return 1;
  }
  else {
    return -1;
  }

}



bool intersect(pair<int, int> v[4]) {

  int p1p2 = CCW(v[0], v[1], v[2]) * CCW(v[0], v[1], v[3]);
  int p3p4 = CCW(v[2], v[3], v[0]) * CCW(v[2], v[3], v[1]);
  bool result = p1p2 <= 0 && p3p4 <= 0;

  // if (v[0] == v[3] || v[0] == v[2] || v[1] == v[3] || v[1] == v[2]) {
  //   return 1;
  // }

  if (p1p2 == 0 && p3p4 == 0) {

    if (v[0] > v[1]) {
      swap(v[0], v[1]);
    }
    if (v[2] > v[3]) {
      swap(v[2], v[3]);
    }
    return (v[1] >= v[2] && v[3] >= v[0]);

  }
  return result;
}

int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);

  int x1, y1, x2, y2, x3, y3, x4, y4;

  cin >> x1 >> y1 >> x2 >> y2;
  cin >> x3 >> y3 >> x4 >> y4;



  pair<int, int> A = { x1,y1 };
  pair<int, int> B = { x2,y2 };
  pair<int, int> C = { x3,y3 };
  pair<int, int> D = { x4,y4 };
  pair<int, int > v[4] = {
    A,B,C,D
  };

  cout << intersect(v) << endl;


return 0;
}
