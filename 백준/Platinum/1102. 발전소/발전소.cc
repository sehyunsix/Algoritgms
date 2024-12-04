      #include<iostream>
      #include<algorithm>
      #include<vector>
      #include<memory.h>
      #include<queue>
      #include <string>
      #include<math.h>
      #define ll long long
      using namespace std;
      #define MAX_WEIGHT 100000000

      //1016

      typedef struct visited_node{
         int node_num;
         int distance;
      }vistied_node;



      typedef struct com_vistied_node{
         bool operator()(visited_node const& a, visited_node const& b){
            return a.distance > b.distance;
         }
      }com_vistied_node;


      bool visited[16]={0,};
      int weight_list[16][16];
      int m[1000000];
      int p2[16];
      int N,P;

      int get_key(bool* v){
            int key= 0;
            for(int i=0; i<N; i++){
               key += v[i]*p2[i];
            }
            return key;

      }

      int dfs(int node , int key ,int depth)
         {
         if(depth==P-1){
            int res =MAX_WEIGHT;
            for(int i=0; i<N; i++){
                  if(!visited[i]){
                  int min_weight =MAX_WEIGHT;
                  for(int j=0; j<N; j++){
                     if(visited[j]){
                     min_weight  = min(min_weight, weight_list[j][i]);
                     }
                  }
                  res = min(res,min_weight );
                  }
            }
            if(res ==MAX_WEIGHT){
               m[key]=-1;
               return -1;
            }
            else{
               m[key]=res;
               return res;
            }
         }

         int res = MAX_WEIGHT;
         for(int i=0; i< N; i++){
            if(!visited[i]){

            int min_weight =MAX_WEIGHT;
            for(int j=0; j<N; j++){
               if(visited[j]){
               min_weight  = min(min_weight, weight_list[j][i]);
               }
            }
            visited[i] =true;
            int new_key =get_key(visited);
            if(m[key]==-2){
               res = min(res, dfs( i ,new_key,depth+1)+min_weight );
            }
            else{
               res = min(res,m[new_key]+min_weight );
            }
            visited[i]=false;
            }
         }
         // cout<< "res :" <<res<< endl;
         if(res==MAX_WEIGHT){
            return -1;
         }

         if(m[key] == -2){
            m[key] =res;
         }
         return res;
   }


      int main(){

         priority_queue<visited_node, vector<visited_node> ,com_vistied_node> next_queue;
         cin >> N;
         int visted_num =0;

         p2[0]=1;
         for(int i=1; i<16; i++){
            p2[i]= 2*p2[i-1];
         }

         for(int i=0; i<1000000;i++){
            m[i]=-2;
         }

         for (int i=0; i<N; i++){
            for(int j=0; j<N; j++){
               cin >> weight_list[i][j];
            }
         }


         int cnt_y =0;
         for(int i=0; i<N; i++){
            char tmp;
            cin >> tmp;
            if(tmp =='Y'){
               visited[i] =true;
               cnt_y++;
            }
         }

         cin >> P;
         P = P-cnt_y;
         if(P<=0){
            cout << 0;
            return 0;
         }
         if(cnt_y==0 ){
            cout << -1;
            return 0;
         }

         int res=MAX_WEIGHT;
         for(int i=0; i<N; i++){
            if(visited[i]){

            res =min(res, dfs(i,get_key(visited),0));
            }
         }

         cout << res;

      }