

#include<vector>
#include<iostream>
#include<stdio.h>

using namespace std;

vector <int> permutation;
int n;
bool choosen[100];

void search(){
if(permutation.size()==n){
  for(int i=0; i<; i++){
    cout<<permutation[i]<<" ";
  }
  cout<<'\n';
}else{
  for(int i=1; i<=n;i++){
    if(choosen[i]) continue;
    choosen[i]=true;
    permutation.push_back(i);
    search();
    choosen[i]=false;
    permutation.pop_back();

  }
}
}


int main(){
    for (int i=0; i<=n; i++){
    choosen[i]=false;
  }

  cin>>n;
  search();
}