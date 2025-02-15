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

int T;
cin >> T;
for (int t = 0; t < T; t++) {
  int a, b;
  cin >> a >> b;
  int res = a % 10;
  for (int i = 0; i < b - 1;i++) {
    res = (res * (a % 10)) % 10;
  }
  if (res == 0) {
    res = 10;
  }
  cout << res << endl;


}

return 0;
}