#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<queue>
#include <string>
#include<math.h>
#include<map>
#include<stack>
#define ll long long
#define P 1000000007
#define endl "\n"
using namespace std;
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  string numbers;
  while(getline(cin, numbers)){;
  if (numbers == "0") {
    break;
  }
  vector<ll> v;
  string tmp;

  numbers = numbers.substr(numbers.find(' ')+1);
  for (char c : numbers) {
    if ('0' <= c && c <= '9') {
      tmp += c;
    }
    else {
      v.push_back(stoi(tmp));
      tmp = "";
    }
  }
  if (tmp.size() != 0) {
    v.push_back(stoi(tmp));
  }

  int N = v.size();
  stack<pair<ll, ll>> s;
  vector<ll> left_index(N, -1);
  vector<ll> right_index(N, -1);
  for (int i = 0; i < N; i++) {
    while (!s.empty() && s.top().first > v[i]) {
      right_index[s.top().second] = i;
      s.pop();
    }
    s.push({ v[i], i });
  }

  while (!s.empty()) {
    // cout << s.top().first << endl;
    right_index[s.top().second] = N;
    s.pop();
  }

  for (int i = N-1; i >-1; i--) {
    while (!s.empty() && s.top().first > v[i]) {
      left_index[s.top().second] = i;
      s.pop();
    }
    s.push({ v[i], i });
  }

  while (!s.empty()) {
    // cout << s.top().first << endl;
    left_index[s.top().second] = -1;
    s.pop();
  }

  ll sol = 0;
  for (int i = 0; i < N;i++) {
    sol = max((right_index[i] - left_index[i] - 1) * v[i], sol);
  }
  cout << sol << endl;

};

  return 0;
}