   #include<iostream>
   #include<algorithm>
   #include<vector>
   #include<memory.h>
   #include<queue>
   #include <string>
   #include<math.h>
   #define ll long long
   using namespace std;

   //1016




   int main(){

   ll min_num,max_num;
   cin >> min_num >> max_num;
   int number = (int)sqrt(max_num); // 구하고자 하는 소수의 범위
   int primeNum[number+1];
   for (int i = 2; i <= number; i++)
    {
        primeNum[i] = i;
    }

    for (int i = 2; i <= sqrt(number); i++)
    {
        // primeNum[i] 가 0이면 이미 소수가 아니므로 continue
        if (primeNum[i] == 0)
            continue;
        // i*k (k<i) 까지의 수는 이미 검사했으므로 j는 i*i 부터 검사해준다.
        for (int j = i * i; j <= number; j += i)
            primeNum[j] = 0;

    }

   vector<int> prime_power_list;
   for(int i=2; i<=number; i++){
      if(primeNum[i] !=0 ){
         prime_power_list.push_back(primeNum[i]);
      }
   }

   int n= max_num-min_num+1;
   bool is_prime_power_divided[n+1];
   memset(is_prime_power_divided, 0, (n+1)*sizeof(bool));
   // cout << "debug" << endl;
   for(ll  p : prime_power_list){
      ll pp =p*p;
      // cout << p <<  endl;
      ll start =  min_num + (pp - min_num% pp);
      if(min_num%pp ==0){
         start= min_num;
      }
      // cout << "start " << start <<" P " << p <<  endl;
      for(ll i=start; i<max_num+1; i+=pp){
         if(i%pp==0){
             is_prime_power_divided[i-min_num] =1;
         }
      }
   }

   int res=0;
   for(int i=0; i<n; i++){
      if(is_prime_power_divided[i] ==0){
         res++;
      }
   }

   cout << res << endl;



   }