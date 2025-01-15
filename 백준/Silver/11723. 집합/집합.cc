#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<queue>
#include <string>
#include<math.h>
#define ll long long
using namespace std;


int s[21];

int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {

    string chk;
    cin >> chk;

    int num;
    if (chk == "add") {
      cin >> num;
      if (s[num] == 0) {
        s[num] = 1;
      }
    }
    else if (chk == "check") {
      cin >> num;
      cout << s[num] << "\n";
    }
    else if (chk == "remove") {
      cin >> num;
      if (s[num] == 1) {
        s[num] = 0;
      }
    }
    else if (chk == "toggle") {
      cin >> num;
      s[num] = (1 + s[num]) % 2;
    }
    else if (chk == "all") {
      for (int i = 1; i < 21; i++) {
        s[i] = 1;
      }
    }
    else if (chk == "empty") {

      for (int i = 1; i < 21; i++) {
        s[i] = 0;
      }
    }
  }
  return 0;
}