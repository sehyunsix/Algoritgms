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

bool a2[100];
bool b2[100];
ll nCk[101][101];

ll  M(int n, int m) {
  if (n == 0) {
    return m+1;
  }
  ll res = 0;
  for( int k =1 ; k<=n ;k++){
    res += (k+m)* nCk[n][k];
  }
  res += m+1;
  return res;
}

int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
ll A, B;
cin >> A >> B;
A = A - 1;
int a_p = 99;
int b_p = 99;
int a_l = 0;
int b_l = 0;

for (int i = 1; i <= 100; i++) {
  nCk[i][1] = i;
  nCk[i][i] = 1;
  nCk[i][0] = 1;
}

for (int i = 1; i <= 100; i++) {
  for (int j = 2; j < i;j++) {
    nCk[i][j] = nCk[i - 1][j - 1] + nCk[i - 1][j];
  }
}

while (A > 0) {
  a2[a_p] = A % 2;
  A = A / 2;
  a_p--;
  a_l++;
}

while (B > 0) {
  b2[b_p] = B % 2;
  B = B / 2;
  b_p--;
  b_l++;
}

ll s_a = 0;
int m_a = 0;
ll s_b = 0;
int m_b = 0;

for (int i = 0; i < 100; i++) {

  if (a2[i] == 1) {
    s_a += M(99-i, m_a);
    m_a += 1;
  }

  if (b2[i] == 1) {
    s_b += M(99-i, m_b);
    m_b += 1;
  }


}
// for (int i = 0; i < 60; i++) {
//   for( int j =0 ; j<60;j++){
//     cout << nCk[i][j] << " ";
//   }
//   cout << endl;
// }

// cout << nCk[50][2] << endl;

// cout << endl;
// cout << b_l << endl;
// cout << s_a << " " << s_b << endl;

cout << s_b - s_a;

return 0;
}