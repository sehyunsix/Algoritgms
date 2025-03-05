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

int N, K;
cin >> N >> K;

int ans = 0;

// if(a)
vector<int> nums;
while (N > K && K > 1) {
  int pow2 = 1;
  nums.push_back(N);
  while (pow2 <= N) {
    pow2 = pow2 << 1;
  }
  // cout << pow2 / 2 << endl;
  N = N - pow2 / 2;
  K--;
}

if (K == 1 && N>K) {
  int pow2 = 1;
  while (pow2 < N) {
    pow2 = pow2 << 1;
  }
  ans = pow2 / 2 -(N-pow2/2) ;
}
cout <<ans << endl;

return 0;
}