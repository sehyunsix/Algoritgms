#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<queue>
#include <string>
#include<math.h>
#include<stack>
#define ll long long
#define P 1000000007
#define endl "\n"
using namespace std;


int N;
int A[10000001];
int dp[1000001];
int M[1000000];
int main() {

cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);

cin >> N;

for( int i =0 ; i<N; i++){
  cin >> A[i];
}




int fixed_start = 0;
int max_lcs_len = 0;
for (int i = 0; i < N; i++) {

  // for (int i = 1; i < max_lcs_len + 1; i++) {
  //   cout << dp[i] << " ";
  // }
  // cout << endl;

  if (max_lcs_len == 0) {

    max_lcs_len += 1;
    dp[1] = 0;
    dp[0] = -1;
    M[0] = -1;
  }
  else {

    int mid;
    int start = 1;
    int end = max_lcs_len;
    int target = A[i];

    while (start <= end) {
      mid = (start + end) / 2;
        if (A[dp[mid]] >= target) {
          end = mid;
          if (start == end) {
            break;
          }
        }
        else{
          start = mid + 1;
        }
    }
    if (start == max_lcs_len + 1) {
      max_lcs_len += 1;
      M[i] = dp[max_lcs_len-1];
      dp[max_lcs_len] = i;
    }
    else {
      M[i] = dp[end-1];
      dp[end] = i;
    }
  }

}
int ans1 = 0;
int ans2 = 0;

cout << max_lcs_len << endl;

int peak_idx = dp[max_lcs_len];
// cout << peak_idx << endl;
stack<int> s;
int next_idx = peak_idx;
while (next_idx > -1) {
  // cout << next_idx<< endl;
  s.push(A[next_idx]);
  next_idx = M[next_idx];
}
// for (int j = 0; j < peak_idx;j++) {
//   cout << A[dp[j]] << " ";
// }
// cout << endl;

// for( int j =0 ; j<peak_idx+1 ;j++){
//   cout << M[j] << " ";
// }
// cout << endl;

while (!s.empty())
{
  cout << s.top() << " ";
  s.pop();
}
cout << endl;




return 0;
}