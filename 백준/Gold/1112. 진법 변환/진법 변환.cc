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

string makeBase(int n, int x) {
  string res = "";
  while (n > 0) {
    string tmp = to_string(n % x) ;
    n = n / x;
    res += tmp;
  }
  return res;
}

string makeMinusBase(string base, int x) {

  bool remainder = 0;
  int idx = 0;
  int len = base.size();
  do {
    if (idx == len){
      base += '0';
      len++;
    }
    if (idx % 2) {
      base[idx] = base[idx] + remainder;
      base[idx] = (base[idx] - '0') % x + '0';
      if (base[idx] - '0' == 0) {
        if ((base[idx]-'0') / x) remainder = 1;
        idx++;
        continue;
      }else{
        base[idx] = x  - (base[idx] - '0') + '0';
        remainder = 1;
      }
    }
    else {
      base[idx] = base[idx] + remainder;
      remainder = (base[idx] - '0') / x;
      base[idx] = (base[idx] - '0') % x + '0';
    }
    idx++;
  } while (remainder > 0 || idx <= len - 1);

  return base;
}

string makeMinusTwice(string base, int x) {

  int remainder = 0;
  int idx = 0;
  int len = base.size();
  do {
    if (idx == len) {
      base += '0';
      len++;
    }
    if (base[idx] - '0' == 0) {
      base[idx] = base[idx] + remainder;
      remainder = 0;
      idx++;
      continue;
    }
    base[idx] = x - (base[idx] - '0') + '0';
    base[idx] = base[idx] + remainder;
    base[idx] = (base[idx] - '0') % x + '0';
    if ((base[idx] - '0') == 0) remainder = 0;
    else remainder = 1;
    idx++;
  } while (remainder > 0 || idx <= len - 1);

  return base;
}

int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
int N, M;
cin >> N >> M;
string res;
if(N==0){
  cout<< 0 << endl;
  return 0;
}
if(N>0){
  if (M < 0) {
    res = makeMinusBase(makeBase(N, abs(M)), abs(M));
  }else{
    res= makeBase(N, abs(M));
  }
}
else{
  if (M < 0) {
     res = makeMinusTwice(makeMinusBase(makeBase(abs(N), abs(M)), abs(M)),abs(M));
  }
  else {
    res = makeBase(abs(N), M);
  }
}

reverse(res.begin(), res.end());
int i =0;
while (res[i] == '0') {
  i++;
}
res = res.substr(i);
if (N < 0 && M>0) {
  string m = "-";
  cout << m + res << endl;
}else{
  cout << res << endl;
}



return 0;
}