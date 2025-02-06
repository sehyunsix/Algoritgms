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

int N;
vector<int> v;


int bs(int x ,int l);
int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
cin >> N;

for (int i = 0; i < N; i++) {
  int tmp;
  cin >> tmp;
  v.push_back(tmp);
}

sort(v.begin(), v.end());
// for (auto t : v) {
//   cout << t << " ";
// }
// cout << endl;
int min = INT32_MAX;
pair<int, int > p;
for (int i = 0; i < N-1; i++) {
  int closer_idx = bs(-v[i], i+1);
  // cout << v[i] << " " << v[closer_idx] << endl;
  int res = abs(v[closer_idx] + v[i]);
  if (min > res) {
    min = res;
    p.first = closer_idx > i ? v[i] : v[closer_idx];
    p.second = closer_idx > i ? v[closer_idx] : v[i];
  }
}

cout << p.first << " " << p.second << endl;


return 0;
}


int bs(int x ,int l) {

  int st = l;
  int en = N;
  int mid;
  while (st < en) {
    mid = (st + en) / 2;
    if (v[mid]>=x) {
      en = mid;
    }
    else {
      st = mid + 1;
    }
  }

  if (en == l) {
    return l;
  }
  else if(en==N){
    return N-1;
  }
  else {
    int res = abs(x - v[en]) > abs(x - v[en - 1]) ? en-1 : en;
    return  res;
  }


}