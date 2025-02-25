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
vector<int> a(N, 0);
vector<int> b(N, 0);
for (int j = 0; j < N;j++) {
  cin >> a[j];
}
for (int j = 0; j < N;j++) {
  cin >> b[j];
}

sort(a.begin(), a.end(), greater<int>());
sort(b.begin(), b.end());

int ans = 0;
for( int j =0 ; j<N ;j++){
  ans += a[j] * b[j];
}
cout << ans << endl;
return 0;
}
