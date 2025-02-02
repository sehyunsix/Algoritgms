#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<queue>
#include <string>
#include<math.h>
#define ll long long
#define P 1000000007
#define endl "\n"
using namespace std;
int N, K;
bool cmp(const pair<int, int> a, const pair<int, int> b) {
  return a.first < b.first;
}

int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
cin >> N >> K;


vector<pair<int, int>> M;
for (int i = 0; i < N; i++) {
  int m ,v;
  cin >> m >> v;
  M.push_back({ m,v });
}

vector<int> C;
for (int i = 0; i < K; i++) {
  int c;
  cin >>c ;
  C.push_back(c);
}


sort(M.begin(), M.end(), cmp);
sort(C.begin(), C.end());
ll answer = 0;
priority_queue<int, vector<int>, less<int>>  q;
int m_idx = 0;
for (int i = 0; i < K; i++) {

  while (M[m_idx].first <= C[i] && m_idx <N) {
    q.push(M[m_idx].second);
    m_idx++;
  }
  if (!q.empty()) {
    answer += q.top();
    q.pop();
  }
}

cout << answer << endl;

return 0;
}