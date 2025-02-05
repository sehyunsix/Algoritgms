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
int N;
int tmp[100];
int fib(int n) {
  if (n <= 2) {
    tmp[n] = 1;
    return 1;
  }
  if (tmp[n] != 0) {
    return tmp[n];
  }
  tmp[n] = fib(n - 1) + fib(n - 2);
  return tmp[n];
}
int main() {
  cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
int N;
cin >> N;

cout << fib(N);
return 0;
}
