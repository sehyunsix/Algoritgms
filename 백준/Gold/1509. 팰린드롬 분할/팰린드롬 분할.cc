#include<iostream>
#include<vector>
#include<string>

int dp[2501] = { 1,1 };
using namespace std;
int main() {

  string p;
  cin >> p;

  // for (int i = 0; i < p.size() + 1;i++) {
  //   dp[i] = 1;
  // }
  for (int i = 1; i < p.size();i++) {
    int next = i;
    int count = 0;
    int min = 1e9;
    while (next >= 0) {
      if (p[i] != p[next]) {
        next -= 1;

      }
      else {
        int start = next;
        int end = i;
        int count = 0;
        while (true) {
          // cout << start << " " << end << endl;
          if (start > end) {
            break;
          }
          else if (start == end) {
            count += 1;
            break;
          }
          start += 1;
          end -= 1;
          if (p[start] != p[end]) {
            count = 0;
            break;
          }
          else {
            count += 2;
          }

        }
        // cout << count << endl;

        if (count > 0) {
          int res = dp[i - count] + 1;
          if (min > res) {
            min = res;
          }
        }

        next -= 1;
      }
    }
    dp[i] = min;
  }
  // for (int i = 0; i < p.size(); i++) {
  //   cout << dp[i] << " ";
  // }
  cout << dp[p.size() - 1];
}




