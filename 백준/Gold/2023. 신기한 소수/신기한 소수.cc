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

bool isprime(int n) {
  if (n == 1) {
    
    return false;
  }
  for (int i = 2; i < (int)sqrt(n) + 1; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

string curr;
int N;
void dfs(int level) {
  if (level == N) {
    int tmp = stoi(curr);
    if (isprime(tmp)) {
      cout << curr << endl;
    }
    return;
  }

  string tmp = curr;
  for (int i = 1; i <= 9;i ++) {
    if (!isprime(stoi(curr + (char)(i + '0')))) {
      continue;
    }
    curr = curr + (char)(i + '0');
    dfs(level + 1);
    curr = tmp;
  }
}

int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
cin >> N;
dfs(0);
// cout << isprime(N) << endl;;

return 0;
}