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
int parent[1000000];
int main() {

  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int maxL = 0;
  parent[0] = -1;
  for (int i = 0; i < N; i++) {
    int mid;
    int st = 1;
    int en = maxL + 1;
    while (st < en) {
      mid = (st + en) / 2;
      if (A[i] <= A[dp[mid]]) en = mid;
      else st = mid + 1;
    }
    if(en ==maxL+1) maxL++;
    dp[en] = i;
    parent[i] =(en==1?-1:dp[en - 1]);
  }

  cout << maxL << endl;

  int idx = dp[maxL];
  stack<int> s;
  while (idx > -1) {
    s.push(A[idx]);
    idx = parent[idx];
  }

  while (!s.empty())
  {
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;

  return 0;
}