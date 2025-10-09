#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <map>
using namespace std;

// segemetn tree
// index를 가짐
// 각 노드가 의미하는 바가 해당 범위에 데이터가 있는 개수를 의미함
// tree의 크기는 2N+1
// 01 부터 N까지 데이터를 비워듬
// N+1부터 2N까지 데이터를 사용함
// 부모 index는  자식/2 임 
// 예를들어 [a , b] 구간에 데이터가 몇개 있는지 알고 있다고 가장해보자
// 데이터가 맞을때까지 [a, b] 구간에 대해서 바이너리 서치하면됨. 그럼 log n *logn 임
// N+a , N+b 부터 시작함
// leftIndex, rightIndex가 있음
// leftIndex가 rigthIndex보다 커지면 상황종료임 ,그때가지 탐색한 노드의 합이 최종 개수임
// whie로 하면 될듯

int segTree[2200000];
int base;
int N;
int findUpIndex(int currIndex, int  relativeIndex){
    
    int num=0;
    int leftIndex=base;
    int rightIndex= base+currIndex;
    while(leftIndex<=rightIndex){
        if(leftIndex % 2 == 1){
            num += segTree[leftIndex];
            leftIndex++;
        }
        if(rightIndex %2==0){
            num += segTree[rightIndex];
            rightIndex--;
        }
        leftIndex /= 2;
        rightIndex /= 2;
    }
    int targetNum= num-relativeIndex; 
    
    // cout << "[up] targetNum : " << targetNum <<endl;
    int targetIndex=1;
    while(targetIndex<base){
        if(segTree[targetIndex*2]>=targetNum){
            targetIndex= targetIndex*2;
        }else{
            targetNum=targetNum-segTree[targetIndex*2];
            targetIndex= targetIndex*2+1;
        }
    }
    // cout << "[up] targetIndex : " << targetIndex-base <<endl;
    return targetIndex-base;
}



int findDownIndex(int currIndex, int  relativeIndex, int n){
    
    int num=0;
    int leftIndex=base;
    int rightIndex= base+currIndex;
    while(leftIndex<=rightIndex){
        if(leftIndex % 2 == 1){
            num += segTree[leftIndex];
            leftIndex++;
        }
        if(rightIndex %2==0){
            num += segTree[rightIndex];
            rightIndex--;
        }
        leftIndex /= 2;
        rightIndex /= 2;
    }
    int targetNum= num+relativeIndex; 
    // cout << "[down] targetNum : "<< targetNum <<"[segTree] size "<<segTree[1] <<endl;
    if(targetNum >segTree[1]){
        return n;
    }
    int targetIndex=1;
    while(targetIndex<base){
        if(segTree[targetIndex*2]>=targetNum){
            targetIndex= targetIndex*2;
        }else{
            targetNum=targetNum-segTree[targetIndex*2];
            targetIndex= targetIndex*2+1;
        }
    }
    // cout << "[down] targetIndex : " << targetIndex-base <<endl;
    return targetIndex-base;
}

void update(int index ,int value){
    index = base+index;
    segTree[index]=value;
    while(index>0){
        int parentIndex =index/2;
        segTree[parentIndex] =segTree[parentIndex*2] +segTree[parentIndex*2+1];
        index=parentIndex;
    }
}

void initialize(int n){
    N=1;
    while(2*n+1>N){
        N <<= 1;
    }
    base = N/2;
    // cout << "Treesize : " << N << " base : "<<base<<endl;
    
    for(int i=0; i<n; i++){
        segTree[base+i]=1;
    }
    
    for(int i=base-1; i>0;i--){
        segTree[i]=segTree[i*2] +segTree[i*2+1];
    }
}


void printSegTree(int n){
    string answer = "";
    for(int i=base; i<base+n;i++){
        char c = segTree[i]?'O':'X';
        answer.push_back(c);
    }
    cout << answer<<endl;
}


string solution(int n, int k, vector<string> cmd) {
   
    int cmdLength= cmd.size();
    
    initialize(n);
  
    stack<int> removes;
    int currIndex=k;
    for( string c : cmd){
        char command= c[0];
        int num;
        int recenRemoveindex =0;
        int downIndex=0;
        // cout << "currIndex :" << currIndex<<endl;
        switch( command){
            case 'U' :
                num =stoi(c.substr(1));
                currIndex=findUpIndex(currIndex,num);
                break;
            case 'D':
                num =stoi(c.substr(1));
                currIndex =findDownIndex(currIndex, num,n);
                break;

            case 'C':
                update(currIndex,0);
                removes.push(currIndex);
                downIndex= findDownIndex(currIndex,1,n);
                // cout << "C : "<<currIndex<<endl; 
                if(downIndex ==n){
                     // cout << "N : "<<currIndex<<endl; 
                    currIndex=findUpIndex(currIndex,0);
                }else{
                    currIndex=downIndex;
                }
                break;
                
            case 'Z':
                update(removes.top(),1);
                removes.pop();
                break;
        }
    
     
    }
    
    string answer = "";
    for(int i=base; i<base+n;i++){
        char c = segTree[i]?'O':'X';
        answer += c;
    }
    return answer;
}

