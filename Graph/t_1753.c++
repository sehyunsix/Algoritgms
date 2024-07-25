#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<random>
#define INF 987654321


using namespace std;

void make_test_case(){
  int n=20000,v=300000;
  cout << n <<" "<<v<<endl;
  cout <<1<<endl;
  for(int i=1;i<v+1;i++){
    cout << rand()%20000<<" "<<rand()%20000<<" "<<rand()%10<<"\n";
  }

}

int main(){
  make_test_case();
}