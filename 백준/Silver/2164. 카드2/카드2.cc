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
queue<int> q;
for (int i = 1; i < N+1; i++) {
  q.push(i);
}
while (q.size() > 1) {
  q.pop();
  int tmp = q.front();
  q.pop();
  q.push(tmp);
}


cout << q.front() << endl;

return 0;
}