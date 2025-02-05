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
int sol;
void f(int start, int mid, int end ,int depth) {
  if (depth == 0) {
    return;
  }
  f(start, end, mid, depth - 1);
  sol += 1;
  cout << start << " " << end << endl;
  f(mid, start, end, depth - 1);

}

int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
int N;
cin >> N;

int sol = 1;
for (int i = 0; i < N;i++) {
  sol = sol * 2;
}
cout << sol - 1 << endl;
f(1, 2, 3, N);


return 0;
}