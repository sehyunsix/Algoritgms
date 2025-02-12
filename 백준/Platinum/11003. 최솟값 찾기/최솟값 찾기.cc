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


typedef struct cmpPair {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
  }
}cmpPair;

int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);

priority_queue<pair<int, int>, vector<pair<int, int>>, cmpPair> q;

int N, L;
cin >> N >> L;
for (int i = 0; i < N; i++) {
  int tmp;
  cin >> tmp;
  if (q.empty()) {
    q.push({tmp,i });
    cout << tmp << " ";
    continue;
  }
  else {
    if (L > i) {
      q.push({ tmp,i });
      cout << q.top().first << " ";
      continue;
    }

    q.push({ tmp,i });
    while (q.top().second <= i-L) {
      q.pop();
    }
    cout << q.top().first << " ";
  }
}


return 0;
}