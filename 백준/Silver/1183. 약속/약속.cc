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
int N;
cin >> N;
vector<int> nums(N, 0);

for (int i = 0; i < N; i++) {
  int a, b;
  cin >> a >> b;
  nums[i] = b - a;
}

sort(nums.begin(), nums.end());

// for (auto n : nums) {
//   cout << n << " ";
// }
// cout << endl;
if (nums.size() % 2) {
  cout << 1 << endl;
}
else {

  cout << nums[(N-1) / 2 + 1] - nums[(N-1) / 2] + 1 << endl;
}



return 0;
}