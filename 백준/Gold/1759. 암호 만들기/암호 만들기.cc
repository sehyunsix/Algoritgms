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
vector<char> arr;
string curr;
int L, C;

void dfs(int n, int level,int prev) {
  if (n == level) {
    int a_c = 0;
    int b_c = 0;
    for (auto tmp : curr) {
      if (tmp == 'a' || tmp == 'e' || tmp == 'i' || tmp == 'o' || tmp == 'u') a_c++;
      else b_c++;
    }
    if (a_c > 0 && b_c > 1) {
      cout << curr << endl;
    }
    return;
  }
  for (int i = prev + 1; i < C;i++) {
    curr += arr[i];
    dfs(n, level + 1,i);
    curr.pop_back();
  }
  return;

}

int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);

cin >> L >> C;
for (int i = 0; i < C; i++) {
  char tmp;
  cin >> tmp;
  if ('a' <= tmp && tmp <= 'z') {
    arr.push_back(tmp);
  }
  sort(arr.begin(), arr.end());
}

dfs(L, 0, -1);
return 0;
}