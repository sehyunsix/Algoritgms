   #include<iostream>
   #include<algorithm>
   #include<vector>
   #include<memory.h>
   #include<queue>
   #define ll long long
   using namespace std;

   int dir[4][2]= {
      {0,-1},
      {-1,0},
      {0,1},
      {1,0},
   };

   int rl_to_v(int a, int b){
      int r,res;
      if(a<=b && a<-b){
         r=abs(a);
         res =(2*r+1)*(2*r+1)-4*r-(b+r);
      }
      else if(a>b && a<=-b){
         r=abs(b);
         res =(2*r+1)*(2*r+1)-2*r-(r-a);
      }
      else if(a<b && a>=-b){
         r=abs(b);
         res =(2*r+1)*(2*r+1)-6*r-(r+a);
      }
      else if(a>=b && a>=-b){
         r=abs(a);
         res =(2*r+1)*(2*r+1)-(r-b);
      }

      return res;
   }


   int main(){


      int r1,c1,r2,c2;
      cin >> r1 >>c1 >>r2 >> c2;
      int max_num=0;

      for(int i=r1; i<=r2;i++){
         for(int j=c1; j<=c2; j++){
            int tmp  =rl_to_v(i,j);
           if(max_num<tmp)
            max_num= tmp;
         }
      }

      int char_num=0;
      while(max_num>0){
         max_num /= 10;
         char_num++;
      }

      for(int i=r1; i<=r2;i++){
         for(int j=c1; j<=c2; j++){
            cout.width(char_num);
            cout.fill(' ');
            cout << rl_to_v(i,j)<<' ';
         }
         cout << endl;
      }

   }