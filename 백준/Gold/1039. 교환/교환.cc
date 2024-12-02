   #include<iostream>
   #include<algorithm>
   #include<vector>
   #include<memory.h>
   #include<queue>
   #include <string>
   #define ll long long
   using namespace std;


   bool visited[1000000][10]={0,};
   int main(){
      int res =0;
      int N, K;
      cin >> N >> K;
      string s= to_string(N);
      queue<pair<string,int>> bfs_queue;
      bfs_queue.push({s,0});
      while(!bfs_queue.empty()){
         pair<string,int> current = bfs_queue.front();
         bfs_queue.pop();
         string cur_str = current.first;
         int cur_int = stoi(cur_str);
         int cur_dpth = current.second;
         for(int i=0; i<s.size()-1; i++){
               for(int j=i+1; j<s.size(); j++){
                  string tmp_str = cur_str;
                  if(i != 0 || tmp_str[j] !='0'+0 ){
                     swap(tmp_str[i], tmp_str[j]);
                     int next_int =stoi(tmp_str);
                     if(!visited[next_int][cur_dpth+1] && cur_dpth <K-1){
                     visited[next_int][cur_dpth+1]=true;
                     bfs_queue.push({tmp_str,cur_dpth+1});
                     }
                     // cout << tmp_str << " "<<cur_dpth<<endl;
                     if(cur_dpth ==K-1){
                        res = max(res, next_int);
                     }
                  }
               }
            }
      }
      if(res !=0 ){
      cout << res << endl;
      }else{
      cout << -1 << endl;
      }



   }