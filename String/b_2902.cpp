#include<iostream>

using namespace std;

int main(){
  string s;
  cin >> s;

  size_t index = s.find('-');
  printf("%c",s[0]);
  while(index != string::npos){
    printf("%c",s[index+1]);
    index = s.find('-', index+1);

  }
}