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
ios_base::sync_with_stdio(false);

int d, h, m;
cin >> d >> h >> m;

int r_d = (d -11) *1440;
int r_h = (h-11)*60;
int r_m = m -11;

if (r_d + r_h + r_m < 0) {
  cout << -1;
}
else {
  cout << r_d + r_h + r_m;
}


}