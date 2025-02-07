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
int T,N;
int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);

cin >> T;
for (int i = 0; i < T; i++) {
  string commands;
  string array;
  cin >> commands;
  cin >> N;
  cin >> array;
  int st = 0;
  string tmp = "";
  deque<int> dq;
  bool reverse = 0;
  bool error = false;

  for (char c : array) {
    if ('0' <= c && c <= '9') {
      tmp += c;
    }
    else {
      if (!tmp.empty()) {
        dq.push_back(stoi(tmp));
        // cout << tmp;
        tmp = "";

      }
    }
  }
  for (char command : commands) {
    // cout << command << endl;
    if (command == 'R') {
      reverse = (reverse + 1) % 2;
      continue;
    }
    if (command == 'D' && reverse==1) {
      // cout << "pop" << endl;
      if (dq.empty()) {
          error = true;
        }
        else {
          dq.pop_back();
        }
      }
    if (command == 'D' && reverse==0) {
      // cout << "pop" << endl;
      if (dq.empty()) {
          error = true;
        }
        else {
          dq.pop_front();
        }
      }
  }

  if (error) {
    cout << "error" << endl;
    continue;
  }
  if (reverse) {
    cout << "[";
    while (!dq.empty()) {
      if (dq.size() == 1) {
        cout << dq.back();
      }
      else {
        cout << dq.back() << ",";
      }
      dq.pop_back();
    }
    cout << "]";
  }

  else {
    cout << "[";
    while (!dq.empty()) {
      if (dq.size() == 1) {
        cout << dq.front();
      }
      else {
        cout << dq.front() << ",";
      }
      dq.pop_front();
    }
    cout << "]";
  }
  cout << endl;

}
  return 0;
}