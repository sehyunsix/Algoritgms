#include<iostream>

int N,K;
unsigned int prev_list[10001];
unsigned int next_list[10001];
int a[101];

//a[100]

using namespace std;


int main(){
   cin >> N >>K;
  for(int i=0; i<N;i++){
    cin >>a[i];
  }



  next_list[0]=1;
  for(int i=1; i<N+1;i++){
      for(int j=1;j<K+1;j++){


    next_list[j] = prev_list[j];
    if(j-a[i-1]>=0){
    next_list[j] +=next_list[j-a[i-1]];
    }


      // fprintf(stderr,"%u ",next_list[j]);
  }


    for(int h=0;h<K+1;h++){
        prev_list[h]=next_list[h];
      }

  // fprintf(stderr,"\n");

  }
  cout<<next_list[K];

}