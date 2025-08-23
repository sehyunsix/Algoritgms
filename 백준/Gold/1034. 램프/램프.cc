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


/**
 * @brief
 * 알고리즘 생각
 *
 *
 *
 * @return int
 */
struct rowData{
    ll rowNumber;
    int zeroCnt;
    int oneCnt;

 } typedef rowData;


int N,M,K;

map<ll, int> m;

ll pow2(int n ){
  ll res= 1;
  for(int i=0;i<n;i++){
    res <<= 1;
  }
  return res;
}

int getOneCnt(ll n){
  int res=0;
  while(n>0){
   res += n &1;
   n >>= 1;
  }
  return res;
}

bool cmp(pair<ll,int> a ,pair<ll,int> b){
  return a.second > b.second;
}

int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);


cin >> N >> M;


for( int i =0 ; i<N ;i++){
  ll row = 0;

  for(int j=0; j<M; j++){
     char c;
     cin >> c;
     int tmp = c -'0';
     row += tmp*pow2(M-j-1);

  }
  m[row] += 1;

}
cin >> K;

// cout << "map :" <<endl;
// for (auto a : m){
//   cout <<  a.first  << endl;
// }

vector<pair<ll,int>> v(m.begin(),m.end());

sort(v.begin(), v.end(),cmp);

int ans =0;
for( auto a : v){
  //  cout << a.first <<", "<<a.second << ","<<  getOneCnt(a.first)<<endl;;
   int zeroCnt =M - getOneCnt(a.first);
  //  int oneCnt = getOneCnt(a.first);
   if ( (K%2== zeroCnt%2 && K >= zeroCnt)){
     ans = a.second;
     break;
   }
}

cout << ans << endl;
// cout << getOneCnt(7)<<endl;
return 0;
}