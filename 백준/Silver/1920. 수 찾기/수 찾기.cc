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
int N, M;
bool bs(int M);
vector<int> v;
int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);

cin >> N;
for (int i = 0; i < N;i++) {
  int tmp;
  cin >> tmp;
  v.push_back(tmp);
}

sort(v.begin(), v.end());

cin >> M;
for( int i =0 ; i<M; i++){
  int tmp;
  cin >> tmp;
  cout << bs(tmp) << endl;
}



return 0;
}

bool bs(int M){
  int st = 0;
  int en = N-1;
  bool sol =false;
  int mid;
  while (st <= en) {
    mid = (st + en) / 2;
    // cout << st <<" "<< en <<" "<< mid <<endl;
    if (v[mid] >= M) {
      if(v[mid]==M){
        sol = true;
      }
      en = mid - 1;
    }else{
      st = mid + 1;
    }
  }

  return sol;

}