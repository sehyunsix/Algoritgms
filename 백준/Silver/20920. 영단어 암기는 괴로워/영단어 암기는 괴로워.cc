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
vector<string> v;
map<string, int> m;
bool cmp(string& a, string& b) {
  if (m[a] == m[b]) {
    if (a.size() == b.size()) {
      return a < b;
    }
    return a.size() > b.size();
  }
  return m[a] > m[b];

}
int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
int N, M;
cin >> N >> M;

for( int j =0 ; j<N ;j++){
  string tmp;
  cin >> tmp;
  if (tmp.size() >= M) {
    if (m.find(tmp) == m.end()) {
      v.push_back(tmp);
      m[tmp] = 0;
    }
    else {
      m[tmp] += 1;
    }
  }
  }

sort(v.begin(), v.end(), cmp);

for (auto s : v) {
  cout << s << endl;
}

return 0;
}