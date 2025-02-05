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
map<int, int> m;
int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);

int N,M;
cin >> N;
for(int i=0; i<N; i++){
  int tmp;
  cin >> tmp;
  if (m.find(tmp) != m.end()) {
    m[tmp] += 1;
  }
  else {
    m[tmp] = 1;
  }
}

cin >> M;
for (int i = 0; i < M;i++) {
  int tmp;
  cin >> tmp;
  if(m.find(tmp) !=m.end()){
    cout << m[tmp] << " ";
  }
  else{
    cout << 0 << " ";
  }

}


return 0;
}