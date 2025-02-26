#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<queue>
#include <string>
#include<math.h>
#include<map>
#define ll unsigned long long
#define P 1000000007
#define endl "\n"
using namespace std;
string dp[251];

string stringSum(string a, string b) {
  string res = "";
  int remainder=0;
  if (a.size() < b.size()) {
    swap(a, b);
  }

  int idxA = a.size() - 1;
  int idxB = b.size() - 1;
  while (idxA >= 0 || remainder > 0) {
    int n1 = (idxA >= 0 ? a[idxA]-'0' : 0);
    int n2 = (idxB >= 0 ? b[idxB]-'0' : 0);
    int c = n1 + n2 + remainder;
    remainder = c / 10;
    res = to_string(c % 10) + res;
    idxA--;
    idxB--;
  }
  return res;
}


int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);

dp[0] = "1";
dp[1] = "1";



for (int i = 2; i < 251; i++) {
  dp[i] = stringSum(dp[i - 1], stringSum(dp[i - 2], dp[i - 2]));
}



int N;
while (!(cin >> N).eof()) {
  cout << dp[N] << endl;
}


return 0;
}