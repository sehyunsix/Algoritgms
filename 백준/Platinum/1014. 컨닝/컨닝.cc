      #include<iostream>
      #include<algorithm>
      #include<vector>
      #include<memory.h>
      #include<queue>
      #include <string>
      #include<math.h>
      #define ll long long
      using namespace std;

      //1014
      bool vaild_state[10][1024];
      bool new_obstcal_map[1024][10];
      int weight_list[11][1024];
      bool obstacle_map[10][10];
      bool row_state[10]={0,};
      int p2[10];
      int N, M;

      int get_key(bool* row_state){
         int key= 0;
         for(int i=0; i<M;i++){
            key += row_state[i]*p2[i];
         }
         return key;
      }

      void dfs(bool* isobstcale ,int depth ,int row_index,int update_key){
         if(depth == M){
            // cout <<"row state : ";
            // for(int i=0; i<M;i++){
            //    cout << row_state[i] <<" ";
            // }
            // cout <<"\n";
            int key = get_key(row_state);
            vaild_state[row_index][key]=1;
            int new_weight =0;
            for(int i=0; i<M; i++) {
               if(row_state[i]==1)
               new_weight++;}

            weight_list[row_index][key]=max(weight_list[row_index+1][update_key]+new_weight, weight_list[row_index][key]);
            return;
            }

         int tmp=0;

         tmp = row_state[depth];
         row_state[depth]=0;
         dfs(isobstcale, depth+1,row_index,update_key);
         row_state[depth] = tmp;

         if(depth>0){
               if(!isobstcale[depth] && ( row_state[depth-1] != 1)){
                  tmp = row_state[depth];
                  row_state[depth]=1;
                  dfs(isobstcale, depth+1, row_index,update_key);
                  row_state[depth]= tmp;
               }
         }
         else{
            if(!isobstcale[depth]){
               tmp = row_state[depth];
               row_state[depth]=1;
               dfs(isobstcale, depth+1, row_index ,update_key);
               row_state[depth]= tmp;
            }
         }

         return;

      }




      int main(){
         int T;
         cin >> T;
         p2[0] =1;

         for(int i=1; i<10; i++){
            p2[i] =2* p2[i-1];
         }

         for(int t=0; t<T; t++){
            cin >> N >> M;
            char m[N][M];

            for(int i=0; i<11; i++){
               for(int j=0;j<1024;j++){
                  weight_list[i][j]=0;
               }
            }

            for(int i=0; i<N; i++){
               for(int j=0; j<M; j++){
                  cin >>m[i][j];
                  if(m[i][j]=='x'){
                     obstacle_map[i][j]=1;
                  }
                  else{
                     obstacle_map[i][j]=0;
                  }
               }
            }


            dfs(obstacle_map[N-1],0,N-1,0);

            for(int i=N-2; i>-1;i--){
                  bool is_obstcal[M];
                  //  memset(new_obstcal_map ,0,1024*11*(sizeof(bool)));
                  for(int r=0; r<1024;r++){
                     for(int c=0; c<10;c++){
                         new_obstcal_map[r][c]=0;
                     }
                  }

                   for(int r=0; r<10;r++){
                     row_state[r]=0;
                     }


                   for(int k=0; k<1024;k++){
                     if(vaild_state[i+1][k]){
                        for(int j=0; j<M; j++){
                              if((k >>j) % 2==1){
                                 if(j+1<M){
                                       new_obstcal_map[k][j+1] = 1;
                                                }
                                 if(j-1>-1){
                                       new_obstcal_map[k][j-1] = 1;
                                             }
                              }
                           }
                     }

                     }

                  int vaild_state_num=0;
                  for(int j=0; j<1024;j++){

                     if(vaild_state[i+1][j]){
                        vaild_state_num +=1;
                        // cout<<"new_obscal_map:";
                        //   for(int k=0; k<M;k++){
                        //       cout << new_obstcal_map[j][k] <<" ";
                        //    }
                        // cout<<endl;
                        //  cout<<"obstacle_map:";
                        //   for(int k=0; k<M;k++){
                        //       cout << obstacle_map[i][k] <<" ";
                        //    }
                        // cout<<endl;
                        // cout << "is_obstcale ";
                         for(int k=0; k<M;k++){
                              is_obstcal[k]= (new_obstcal_map[j][k] | obstacle_map[i][k]);
                              // cout << is_obstcal[k] <<" ";
                           }
                        //    cout << endl;
                         dfs(is_obstcal,0,i ,j);
                     }


                  }
                  // for(int k=0; k<1024; k++){
                  //       cout << weight_list[i][k] <<" ";
                  //       }
                  //       cout <<endl;
                  // cout <<"vaid_state num : "<<vaild_state_num <<endl;
            }
            int res = 0;
            for(int i=0; i<1024; i++){
               res = max(weight_list[0][i],res);
            }

            cout << res << endl;

         }
      }