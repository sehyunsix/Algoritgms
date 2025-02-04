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

bool cmp(string a, string b) {

  if (a.size() == b.size()) {
    return a < b;
  }
  return a.size() < b.size();

}

int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);


int N;
cin >> N;
vector<string> v(N);
for (int j = 0; j < N;j++) {
  cin >> v[j];
}
sort(v.begin(), v.end(), cmp);
string tmp;
for (auto a : v) {
  if (tmp.size() > 0) {
    if (tmp == a) {
      continue;
    }
  }
  cout << a << endl;
  tmp = a;
}
return 0;
}