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

int car_list[101];


int main() {
  cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);

int a, b, c;
cin >> a >> b >> c;
int cost[4] = { 0, a, b, c };
for (int i = 0; i < 3; i++) {
  int s, t;
  cin >> s >> t;
  for( int j =s ; j<t; j++){
    car_list[j]+= 1;
  }
}

int ans = 0;
for (int i = 1; i < 101; i++) {
  ans += car_list[i]*cost[car_list[i]];
}

cout << ans  << "\n";

return 0;
}