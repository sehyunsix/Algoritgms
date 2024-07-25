#include<iostream>

using namespace std;
char o[3][4]={
{'G','.','.','.'},
{'.','I','.','T'},
{'.','.','S','.'}

};

int main(){
int k= 0;
cin >> k;
for(int i=0;i<3;i++){
for (int n=0;n<k;n++){
for(int j=0;j<4;j++){
  for(int l=0;l<k;l++)
  cout << o[i][j];
}
cout << endl;
}
}

}