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
int main() {

cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
int N;
cin >> N;
vector<int> v(N);
double sum = 0;
for (int i = 0; i < N; i++) {
  cin >> v[i];
  sum += v[i];

}

int max_num = 0;
for (int i = 0; i < N; i++) {
  if (max_num < v[i]) {
    max_num = v[i];
  }
}

double avg = sum / (N * max_num) * 100;
cout << avg << endl;






return 0;

}
