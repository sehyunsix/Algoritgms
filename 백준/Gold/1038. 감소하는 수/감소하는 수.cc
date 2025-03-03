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


int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
queue<string> q;
vector<ll> sol;
for (int i = 0; i <= 9; i++) {
  q.push(to_string(i));
}
while (!q.empty()) {
  string curr = q.front();
  q.pop();
  sol.push_back(stol(curr));
  for( int j =0 ; j<curr.back()-'0';j++){
    q.push(curr + to_string(j) );
  }
}
int N;
cin >> N;
cout << (sol.size() - 1 < N ? -1 : sol[N]) << endl;

return 0;
}