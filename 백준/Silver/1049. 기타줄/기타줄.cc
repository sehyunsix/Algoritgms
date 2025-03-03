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

vector<int> packages(M,0);
vector<int> ones(M,0);
for( int j =0 ; j<M ;j++){
  cin >> packages[j] >> ones[j];
}

sort(packages.begin(), packages.end());
sort(ones.begin(), ones.end());

int sixPrice = (packages[0] < ones[0] * 6 ? packages[0] : ones[0] * 6);
int remainPrice = (packages[0] < ones[0] * (N % 6) ? packages[0] : ones[0] * (N % 6));
cout << N / 6 * sixPrice +remainPrice  << endl;

return 0;
}