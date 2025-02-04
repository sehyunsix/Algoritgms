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

for( int i =0 ; i<N ;i++){
  cin >> numbers[i];
}
int tmp = 0;
for (int i = 0; i < M;i++) {
  tmp += numbers[i];
}

int sol = tmp;
for( int j =1 ; j<N-M+1 ;j++){
  tmp = tmp - numbers[j - 1] + numbers[j + M-1];
  sol = max(sol, tmp);
}

cout << sol << endl;

return 0;
}