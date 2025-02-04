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

int N, M;
cin >> N >> M;
vector<int> numbers(N);
vector<int> accum(N + 1,0);

for( int i =0 ; i<N ;i++){
  cin >> numbers[i];
  accum[i + 1] = accum[i] + numbers[i];
}
int ans = 0;
for (int i = 0; i <N; i++) {
  for (int j = i + 1; j < N+1; j++) {
    if (M == accum[j] - accum[i]) {
      ans += 1;
    }
  }
}

cout << ans << endl;

return 0;
}
