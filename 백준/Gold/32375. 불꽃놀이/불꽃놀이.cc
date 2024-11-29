   #include<iostream>
   #include<algorithm>
   #include<vector>
   #include<memory.h>
   #define ll long long
   using namespace std;
   // 32375 불꽃놀이;

   // bool cmp(ll a, ll b){
   //   if(a<=b){
   //       return 1;
   //   }
   //   return 0;
   // }

   int lower_bound(int start, int end, ll target, vector<ll>& vec){
      int mid;
      int s = start;
      int e = end;
      // cout << "target : "<<target << endl;
      while(s<=e){
         mid = (s+e)/2;
         if(vec[mid] >= target){
            e =mid;
            if(s==e){
               break;
            }
         }
         else{
            s= mid+1;
            if(s>e){
               return vec.size();
            }
         }
      }
   return e;

   }


   int main(){

      ll N, K;

      cin >> N >> K ;

      vector<ll> vec;

      for(int i= 0; i<N ;i++){
         ll tmp;
         cin >> tmp;
         vec.push_back(tmp);
      }

      sort(vec.begin(),vec.end());


      int lower_bound_K= lower_bound(0,vec.size()-1, K,vec);




         int result = vec.size()-lower_bound_K;
         if(lower_bound_K >=vec.size()) {
            result =0;
         }
         int left_index =0;
         int right_index = lower_bound_K -1;


      while(left_index<right_index){
         if((vec[left_index]+vec[right_index]) >= K ){
            result++;
            left_index++;
            right_index--;
         }
         else{
            left_index++;
         }
      }



      if(result==0){
         cout << -1;
      }
      else{
         cout << result;
      }



   }