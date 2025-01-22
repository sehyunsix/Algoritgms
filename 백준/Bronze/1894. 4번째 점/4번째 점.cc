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
int main() {
cin.tie(0);
cout.tie(0);
cout << fixed;
cout.precision(3);

ios_base::sync_with_stdio(false);

double x1, y1, x2, y2 ,x3,y3,x4,y4;

while (!(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4).eof()
  ) {

  pair<double, double> p1 = { x1, y1 };
  pair<double, double >p2 = { x2, y2 };
  pair<double, double> p3 = { x3, y3 };
  pair<double, double >p4 = { x4, y4 };

  pair<double, double>  ans, tmp;
  if (p1 == p3) {

    tmp.first = p1.first - p2.first;
    tmp.second = p1.second - p2.second;
    ans.first = p4.first - tmp.first;
    ans.second = p4.second - tmp.second;

  }
  else if (p1 == p4) {
    tmp.first = p1.first - p2.first;
    tmp.second = p1.second - p2.second;
    ans.first = p3.first - tmp.first;
    ans.second = p3.second - tmp.second;

  }
  else if (p2 == p3) {
    tmp.first = p2.first - p1.first;
    tmp.second = p2.second - p1.second;
    ans.first = p4.first - tmp.first;
    ans.second = p4.second - tmp.second;

  }
  else if (p2 == p4) {
    tmp.first = p2.first - p1.first;
    tmp.second = p2.second - p1.second;
    ans.first = p3.first - tmp.first;
    ans.second = p3.second - tmp.second;

  }
  cout << ans.first <<" "<< ans.second << endl;

}
  return 0;
}
