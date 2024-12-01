   #include<iostream>
   #include<algorithm>
   #include<vector>
   #include<memory.h>
   #include<queue>
   #define ll long long
   using namespace std;



   int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(NULL);
      cout.tie(NULL);
      priority_queue<int>left_queue;
      priority_queue<int ,vector<int> ,greater<int>> right_queue;
      int N;
      cin >> N;
      int center=0;
      cin >> center;
      cout << center << "\n";;
      for(int i=1; i<N; i++){
            int tmp,new_center;
            cin >> tmp;
            // cout << " l : " << left_queue.size() << " r : "<< right_queue.size() <<endl;
            if(i%2==1){
               // cout<<"right" ;
               right_queue.push(tmp);
               new_center = right_queue.top();
               // cout<<"new center"<< new_center <<endl ;
               if(center >= new_center){
                  right_queue.pop();
                  right_queue.push(center);
                  center =new_center;
                  if(!left_queue.empty()){
                  new_center=left_queue.top();
                  if(center < new_center){
                     left_queue.pop();
                     left_queue.push(center);
                     center =new_center;
                  }
                  }
               }
            }
            else{
                  // cout<<"left" ;
                left_queue.push(tmp);
                new_center = left_queue.top();
               if(center <= new_center){
                  left_queue.pop();
                  left_queue.push(center);
                  center =new_center;
               }
               new_center=right_queue.top();
               if(!right_queue.empty()){
               if(center >= new_center){
               right_queue.pop();
               right_queue.push(center);
               center =new_center;
               }
               }

            }
            cout << center << "\n";;

      }

   }