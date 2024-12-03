   #include<iostream>
   #include<algorithm>
   #include<vector>
   #include<memory.h>
   #include<queue>
   #include <string>
   #define ll long long
   using namespace std;


   vector<int> edge_list[50];
   bool cmp(int a, int b){
      return a>b;
   }
   int dfs(int node){
      int m=0;

      if(!edge_list[node].empty()){
         vector<int> tmp_list;
         for(int e : edge_list[node]){
            //   m=max(m,dfs(e));
            tmp_list.push_back(dfs(e));
         }
         sort(tmp_list.begin(),tmp_list.end(),cmp);
         for(int i=0; i<edge_list[node].size();i++){
            tmp_list[i] += i+1;
         }
         int m = *max_element(tmp_list.begin(),tmp_list.end());
         return m;
      }
      else{
         return 0;
      }
   }

   int main(){

      int N,root;
      cin >> N;
      cin >> root;
      for(int i=1; i<N;i++){
         int tmp;
         cin >> tmp;
         edge_list[tmp].push_back(i);
      }
      cout << dfs(0) << endl;

   }