#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <iostream>
using namespace std;

int binararySearch(int input ,int start ,int end, int* array){

    int mid = (start+end)/2;
    if(mid < start || mid > end){
      return -1;
    }
    if(array[mid] == input){
      return mid;
    }
    else if(array[mid]>input){
      return binararySearch(input,start, mid-1, array);

    }
    else{
      return binararySearch(input,mid+1,end, array);
    }

}

int main(){
  int array[10]={1,2,3,4,5,6,7,8,9,10};

  while(1){
  int input;
  cin >> input;
  int result = binararySearch(input,0,9,array);
  cout << result << endl;
  }



}