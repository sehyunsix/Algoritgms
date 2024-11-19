#include<iostream>
#include<algorithm>
#define ll long long

using namespace std;


int local_sum[10]={
  0,
  1,
  1+2,
  1+2+3,
  1+2+3+4,
  1+2+3+4+5,
  1+2+3+4+5+6,
  1+2+3+4+5+6+7,
  1+2+3+4+5+6+7+8,
  1+2+3+4+5+6+7+8+9
};

ll power_10(ll k){

    ll result =1;
    for(int i=0; i<k; i++){
        result *= 10;
    }
    return result;
}

ll find_sum(ll num ){

    if(num<=0){
      return 0;
    }
    int max_k =0;
    while(power_10(max_k)<=num){
      max_k++;
    }

    ll result =0;
    for(int k=1; k<=max_k; k++){
      ll k_10_1 =power_10(k-1);
      int num_k = (num/k_10_1)%10;

      result += (num/power_10(k))*45*(k_10_1)+local_sum[num_k-1]*(k_10_1)+num_k*(num%k_10_1+1);
      // cout << "result "<<result<<endl;
    }
    return result;
}


int main(){
  ll small, big;
  cin >> small >> big ;


  cout<<find_sum(big)-find_sum(small-1)<<endl;


}