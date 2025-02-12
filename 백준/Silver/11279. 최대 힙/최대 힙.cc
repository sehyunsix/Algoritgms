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
priority_queue<int> q;
cin >> N;
for (int i = 0; i < N; i++) {
  int tmp;
  cin >> tmp;
  if (tmp == 0) {
    if (q.empty()) {
      cout << 0 << endl;
    }
    else {
      cout << q.top() << endl;
      q.pop();
    }
  }
  else {
    q.push(tmp);
  }
}

return 0;
}