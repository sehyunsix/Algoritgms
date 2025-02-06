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
vector<int> v;
int N, M, tmp;
int bisect1(int x);
int bisect2(int x);
int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);


cin >> N;
for (int i = 0; i < N;i++) {
  cin >> tmp;
  v.push_back(tmp);

}

sort(v.begin(), v.end());

cin >> M;
for (int i = 0; i < M; i++) {
  cin >> tmp;
  int r = bisect1(tmp);
  int l = bisect2(tmp);
  cout << r - l << " ";
}




return 0;
}

int bisect1(int x) {
  int st = -1;
  int en = N - 1;
  int mid;
  while (st < en) {
    mid = (st + en + 1) / 2;

    if (v[mid] <= x) {
      st = mid;
    }
    else {
      en = mid - 1;
    }
  }

  return st;
}

int bisect2(int x) {
  int st = -1;
  int en = N - 1;
  int mid;
  while (st < en) {
    mid = (st + en + 1) / 2;

    if (v[mid] < x) {
      st = mid;
    }
    else {
      en = mid - 1;
    }
  }

  return st;
}