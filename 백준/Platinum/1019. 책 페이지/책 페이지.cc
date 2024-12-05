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

      ll p10[11];

      int main(){
         p10[0]=1;
         for(int i=1; i<11; i++){
            p10[i]=10*p10[i-1];
         }
         string str_N;
         cin >> str_N;
         ll N = stoi(str_N);

         ll res[10];
         memset(res,0 ,10*sizeof(ll));

         ll tmp ,i_num ,remainder;
         for(int i=0; i<str_N.size();i++){
            tmp =N/p10[i+1];
            remainder =N%p10[i];
            i_num =(N/p10[i])%10;

            for(int j=0; j<10;j++){
               res[j] += tmp*p10[i];
            }
            res[0] -= p10[i-1];

            res[i_num] +=remainder+1;

            if(i>=str_N.size()-1){
                for(int j=1; j<i_num; j++ ){
                  res[j] += p10[i];
               }
            }
            else{
               for(int j=0; j<i_num; j++ ){
                  res[j] += p10[i];
               }
            }


         }
         for(int i=0;i<10;i++){
            cout << res[i] << " ";
         }

      }