   #include<iostream>
   #include<algorithm>
   #include<vector>
   #include<memory.h>
   #include<queue>
   #define ll long long
   using namespace std;
   // 12764 싸지방에 간 준하

   typedef struct User{
      int start_time;
      int finsh_time;
      int seat_number;
   }User;

   typedef struct CompaerStartime{
   bool operator()(User const& a,User const& b){
         return a.start_time >  b.start_time;
   } }CompaerStartime;


   typedef struct CompaerFinshtime{
   bool operator()(User const& a,User const& b){
         return a.finsh_time >  b.finsh_time;
   }}CompaerFinshtime;



   priority_queue<User,vector<User>,CompaerStartime > start_queue;
   priority_queue<User,vector<User>,CompaerFinshtime> finsh_queue;
   priority_queue<int, vector<int> ,greater<int>> empty_seat_number_queue;



   int main(){
      int N;
      cin >> N;
      int max_seat_number = 0;
      vector<int> seat_counter;
      for(int i=0; i<N;i++){
         int start, finish;
         cin >> start >> finish;
         start_queue.push({start,finish,0});
      }

      while(!start_queue.empty()){
         User next = start_queue.top();
         start_queue.pop();
         int next_seat_number;
         while(!finsh_queue.empty() && next.start_time> finsh_queue.top().finsh_time ){
            empty_seat_number_queue.push(finsh_queue.top().seat_number);
            finsh_queue.pop();
         }
         if(!empty_seat_number_queue.empty()){
            next_seat_number=empty_seat_number_queue.top();
            empty_seat_number_queue.pop();
            seat_counter[next_seat_number-1]++;
         }
         else{
            seat_counter.push_back(1);
            max_seat_number++;
            next_seat_number = max_seat_number;
         }
         next.seat_number=next_seat_number;
         // cout << next_seat_number << endl;
         finsh_queue.push(next);
      }

      cout << seat_counter.size() << endl;
      for(int c : seat_counter){
         cout <<  c << " ";
      }


   }