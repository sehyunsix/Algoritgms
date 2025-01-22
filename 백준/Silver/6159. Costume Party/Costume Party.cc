#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<queue>
#include <string>
#include<math.h>
#define ll long long
#define P 1000000007
using namespace std;
int main() {
  cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);

int N, S,tmp;
cin >> N >>S ;
vector<int> cow_list;
for( int i =0 ; i<N; i++){
  cin >> tmp;
  cow_list.push_back(tmp);
}


sort(cow_list.begin(), cow_list.end());

// for (auto i : cow_list) {
//   cout << i << " ";

// }
// cout << endl;

int ans = 0;

for (int i = 0; i < N-1; i++) {
  for (int j = i + 1; j < N;j++) {

    if (cow_list[i] + cow_list[j] > S) {
      break;
    }
    ans += 1;
  }
}


cout << ans << endl;
return 0;
}