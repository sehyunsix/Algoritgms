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

vector<int> plus_array;
vector<int> minus_array;
int find_lower_bound(int M);
int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);

int N;
cin >> N;


for (int i = 0; i < N; i++) {
  int tmp;
  cin >> tmp;
  if (tmp > 0) {
    plus_array.push_back(tmp);
  }
  if(tmp < 0){
    minus_array.push_back(-tmp);
  }
}


ll min = INT64_MAX;
pair<int, int> sol;

if (!plus_array.empty()) {
  sort(plus_array.begin(), plus_array.end());
  if(plus_array.size() >=2){
    if (min >= plus_array[1] + plus_array[0]) {
      min = plus_array[1] + plus_array[0];
      sol.first = plus_array[0];
      sol.second = plus_array[1];
    }
  }

}

if (!minus_array.empty()) {

sort(minus_array.begin(), minus_array.end()  );
  if(minus_array.size() >=2){
    if (min >= minus_array[1] + minus_array[0]) {
      min = minus_array[1] + minus_array[0];
      sol.first = -minus_array[1];
      sol.second = -minus_array[0];
    }
  }
}





if (plus_array.empty()) {
  cout << sol.first <<" "<< sol.second << endl;
  return 0;
}

if (minus_array.empty()) {
  cout << sol.first <<" "<< sol.second << endl;
  return 0;
}


for (int i = 0; i < minus_array.size();i++) {

  int lb = find_lower_bound(minus_array[i]);

  if (lb == -1) {
    if(min>=abs(plus_array.back()-  minus_array[i])){
      min = abs(plus_array.back() - minus_array[i]);
      sol.first = -minus_array[i];
      sol.second = plus_array.back();
    }
  }
  else {
    if (lb == 0) {
      if (min >= abs(plus_array[0] - minus_array[i])) {
        min = abs(plus_array[0] - minus_array[i]);
        sol.first = -minus_array[i];
        sol.second = plus_array[0];
      }
    }
    else {
      if(abs(minus_array[i] -plus_array[lb]) < abs(minus_array[i] -plus_array[lb-1])){
        if (min >= abs(plus_array[lb] - minus_array[i])) {
        min = abs(plus_array[lb] - minus_array[i]);
        sol.first = -minus_array[i];
        sol.second = plus_array[lb];
      }
      }else{
        if (min >= abs(plus_array[lb-1] - minus_array[i])) {
          min = abs(plus_array[lb-1] - minus_array[i]);
          sol.first = -minus_array[i];
          sol.second = plus_array[lb-1];
        }

      }

    }

  }


}


cout << sol.first <<" "<< sol.second << endl;

return 0;
}

int find_lower_bound(int M ){
  int st = 0;
  int en = plus_array.size() - 1;
  int res = -1;
  int mid;
  while (st <= en) {
    mid = (st + en) / 2;
   if(plus_array[mid]>= M){
     res = mid;
     en =mid - 1;
   }
   else{
    st = mid +1;
   }
  }
  return res;
}
