#include <string>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
using namespace std;


string tenTok(int n ,int k){
    string res="";
    while(n>0){
        string tmp = to_string(n%k);
        res = tmp+ res;
        n=n/k;
    }
    return res;
}
bool isPrime(long long  n){
    if(n<= 1) return false;
    for(int i=3; i<sqrt(n)+1;i++){
        if(n%i==0)  return false;
    }
    return true;
}
int solution(int n, int k) {
    int answer = 0;
    string numbers =tenTok(n,k);
    string tmp ="";
    for(int i=0; i<numbers.size();i++){
        if(numbers[i] == '0'){
         if(tmp.size() >0){
             answer += isPrime(stoull(tmp));
             tmp="";
         }
        }
        else{tmp += numbers[i];}
    }
    if(tmp.size() >0) answer += isPrime(stoull(tmp));
    return answer;
}