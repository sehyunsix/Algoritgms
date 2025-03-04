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


  int L, R;
  cin >> L >> R;
  string leftNum = to_string(L);

  int cnt = 0;
  for (int i = 0; i < leftNum.size(); i++) {
    if (leftNum[i] == '8') {
      string tmp = leftNum.substr(0, i) + '9';
      for( int j =0 ; j<(int) leftNum.size() -1-i ;j++){
        tmp += '0';
      }
      if (stoi(tmp)> R)  cnt++;
    }
  }
  cout << cnt << endl;

return 0;
}