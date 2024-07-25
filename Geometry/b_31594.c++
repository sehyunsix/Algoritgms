#include<iostream>

using namespace std;

int P[8][3]={
  {0,0,0},
  {0,0,1},
  {0,1,0},
  {0,1,1},
  {1,0,0},
  {1,0,1},
  {1,1,0},
  {1,1,1}
};


int main(){


  int n;
  int count;
  cin >> n;


  for ( ; n>0; n--){
    int t[4][2]={0,};
    cin >>t[0][0]>>t[1][0]>>t[2][0]>>t[3][0];
    for(int i=0; i<4;i++){
      count =0;
      for(int j=0; j<4;j++){
          int distance =0;
          if(i==j) continue;
          for(int k=0;k<3;k++){
              distance += abs(P[t[i][0]][k]-P[t[j][0]][k]);
        }
        if(distance==1) count++;
      }

      if(count==2){
        t[i][1]=1;
      }

    }
    bool check = true;
    for(int i=0;i<4;i++){
      if(t[i][1]==0){
        check = false;
        break;
      }
    }
    if(check){
      cout << "YES"<<endl;
    }
    else{
      cout << "NO"<<endl;

    }
  }

}

