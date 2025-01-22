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

bool cmp(const int& a, const int& b) {
  return (a > b);
}

int main() {
  cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);

vector<int> w_list , v_list;
int tmp;
for (int i = 0; i < 10; i++) {
  cin >> tmp;
  w_list.push_back(tmp);
}

for (int i = 0; i < 10; i++) {
  cin >> tmp;
  v_list.push_back(tmp);
}

sort(w_list.begin(), w_list.end(), cmp);
sort(v_list.begin(), v_list.end(), cmp);

int ans1 = w_list[0] + w_list[1] + w_list[2];
int ans2 = v_list[0] + v_list[1] + v_list[2];

cout << ans1 << " " << ans2 << "\n";


return 0;
}