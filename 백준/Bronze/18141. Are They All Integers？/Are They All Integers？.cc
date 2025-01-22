#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<queue>
#include <string>
#include<math.h>
#define ll long long
#define P 1000000007
using namespace std;
int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);


int N ,tmp;
cin >> N;
vector<int> v;

for (int i = 0; i < N; i++) {
  cin >> tmp;
  v.push_back(tmp);
}

vector<int> d;

int chk = 0;
for (int i = 0; i < N - 1; i++) {
  for (int j = i + 1; j < N; j++) {
    for (int k = 0; k < N; k++) {
      if (k != j && k != i) {
        if ((v[i] - v[j]) % v[k] != 0) {
          chk += 1;
        };
      }
    }
  }
}




if (chk == 0) {
  cout << "yes";
}
else {
  cout << "no";
}

return 0;
}
