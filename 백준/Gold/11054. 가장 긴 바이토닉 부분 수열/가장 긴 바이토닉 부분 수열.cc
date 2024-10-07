#include<iostream>


int a[1001];
int lcs[1001];
int lds[1001];


using namespace std;

int main() {


  int N;
  cin >> N;
  for (int i = 1; i < N + 1; i++) {

    cin >> a[i];

  }

  for (int i = 1; i < N + 1; i++) {

    int max = 0;
    for (int j = 0;j < i;j++) {
      if (a[j] < a[i]) {
        if (max < lcs[j] + 1) {
          max = lcs[j] + 1;
        }
      }
    }


    lcs[i] = max;
  }


  for (int i = 1; i < N + 1; i++) {

    int max = 0;
    for (int j = 0;j < i;j++) {
      if (a[N + 1 - j] < a[N + 1 - i]) {
        if (max < lds[N + 1 - j] + 1) {
          max = lds[N + 1 - j] + 1;
        }
      }
    }
    lds[N + 1 - i] = max;
  }

  // for (int i = 1; i < N + 1;i++) {

  //   cout << lds[i] << " ";
  // }
  // cout << endl;
  int res = 0;
  for (int i = 1; i < N + 1;i++) {
    if (res < lds[i] + lcs[i]) {
      res = lds[i] + lcs[i];
    }
  }
  cout << res - 1 << endl;

}
