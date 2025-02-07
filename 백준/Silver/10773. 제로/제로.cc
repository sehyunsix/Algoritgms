#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<queue>
#include<string>
#include<stack>
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
stack<int> s;
for (int i = 0; i < N; i++) {
  int tmp;
  cin >> tmp;
  if (tmp == 0) s.pop();
  else s.push(tmp);
}

int sum = 0;
while (!s.empty()) {
  sum += s.top();
  s.pop();
}

cout << sum<< endl;

return 0;
}