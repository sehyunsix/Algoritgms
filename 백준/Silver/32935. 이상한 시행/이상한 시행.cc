#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<queue>
#include <string>
#include<math.h>
#define ll long long
using namespace std;
int main() {

  vector<int> vec;

  int N;
  ll dp[N];
  memset(dp, 0, N * sizeof(ll));
  ll s = 0;
  cin >> N;

  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    s += num;
    vec.push_back(num);
  }


  sort(vec.begin(), vec.end());
  cout << max(max(-(ll)vec[0], s),0LL) << endl;

  return 0;
}