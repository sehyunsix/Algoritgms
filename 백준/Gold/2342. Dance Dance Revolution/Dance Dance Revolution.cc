#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<queue>
#include <string>
#include<math.h>
#include<sstream>
#define ll long long
using namespace std;

ll prev_list[5][5];
ll next_list[5][5];

int f[5][5] = {
  {1, 2, 2, 2, 2},
  {2, 1, 3, 4, 3},
  {2, 3, 1, 3, 4},
  {2, 4, 3, 1, 3},
  {2, 3, 4, 3, 1},
};


int main() {

  string number_list;
  getline(cin, number_list);
  stringstream ss(number_list);
  vector<int> a;
  int num;
  while (ss >> num) {
    a.push_back(num);
  }
  int N = a.size()-1;

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5;j++) {
      prev_list[i][j] = -1;
    }
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5;j++) {
      prev_list[i][j] = -1;
    }
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5;j++) {
      next_list[i][j] = INT32_MAX;
    }
  }



  prev_list[0][0] = 0;

  for (int i = 0; i < N; i++) {

    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 5; k++) {

          if (prev_list[k][j] > -1) {
            next_list[a[i]][j] = min(f[k][a[i]] + prev_list[k][j], next_list[a[i]][j]);
          }

          if (prev_list[j][k] > -1) {
            next_list[j][a[i]] = min(f[k][a[i]] + prev_list[j][k], next_list[j][a[i]]);
          }

      }
    }

    for (int k = 0; k < 5; k++) {
      for (int j = 0; j < 5; j++) {
        if (j != a[i] && k !=a[i]) {
          next_list[k][j] = INT32_MAX;
          next_list[j][k] = INT32_MAX;
        }
      }
    }

    // for (int i = 0; i < 5; i++) {
    //   for (int j = 0; j < 5; j++) {
    //       cout << next_list[i][j] << " ";
    //       // ans = min(ans, next_list[i][j]);
    //   }
    //   cout  <<endl;
    // }
    // cout << " =========" << endl;


    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 5; k++) {
        prev_list[j][k] = next_list[j][k];
        next_list[j][k] = INT32_MAX;
      }
    }
  }


  ll ans = INT32_MAX;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (i != j) {
        // cout << prev_list[i][j] << " ";
        ans =max(min(ans, prev_list[i][j]),0LL);
      }
    }
    // cout << endl;
  }

  cout << ans<<endl;
  return 0;

}