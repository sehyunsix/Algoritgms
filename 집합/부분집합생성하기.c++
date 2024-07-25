

#include<vector>
#include<iostream>

using namespace std;

vector <int> subset;
int n;

void search(int k){
  if(k==n+1){
    for(int i=0; i<subset.size(); i++){
      cout<<subset[i]<<" ";
    }
    cout<<'\n';

  }else{
    subset.push_back(k);
    search(k+1);
    subset.pop_back();
    search(k+1);
  }
}

int main(){
  cin>>n;
  search(1);

}