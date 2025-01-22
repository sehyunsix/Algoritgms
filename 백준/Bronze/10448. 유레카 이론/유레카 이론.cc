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


int tri_num_list[1001];

int main() {
  cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);

int T;
cin >> T;



vector<int> tri_list;

int tmp = 1;
int n = 1;
while (tmp < 1000) {
  tri_list.push_back(tmp);
  n += 1;
  tmp = n * (n + 1) / 2;
}




for (int i = 0; i < tri_list.size(); i++) {
  for (int j = i; j < tri_list.size();j++) {
    for (int k = j; k < tri_list.size();k++) {
      if ((tri_list[i] + tri_list[j] + tri_list[k]) <= 1000) {
        // cout << tri_list[i] + tri_list[j] + tri_list[k] << endl;
        tri_num_list[tri_list[i] +tri_list[j] + tri_list[k]] = 1;
      }
      else {
        break;
      }
    }
  }
}


for (int i = 0; i < T; i++) {
  int N;
  cin >> N;
  cout << tri_num_list[N] << "\n";
}


return 0;
}
