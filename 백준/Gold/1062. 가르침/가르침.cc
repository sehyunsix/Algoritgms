#include<iostream>
#include<vector>
#include<string>

using namespace std;


//bit string이 포함된다는 것을 어떻게 표현하지?

// A bit > C bit
// C가 1안 자리가 A도 1이면됨

int N, K;
int answer= 0;
long  masked[50];
int totalCount =0;
const string filterString = "antic";
vector<string> v;   
bool isAntic(char c){
    for(char d : filterString){
        if(d==c){
            return true;
        }
    }
    return false;
}

bool isLeftIncludeRight(long left ,long right){
    
    while(right){
        bool rightLeftMostBit = right & 1;
        bool leftLeftMostBit =left & 1;
        if(rightLeftMostBit & !leftLeftMostBit){
            return false;
        }
        left >>= 1;
        right >>= 1;
    }
    return true;
}

void dfs(int currDepth , int endDepth , long bitMask, int lastIdx ){
    // cout << totalCount++ << " " << currDepth << " "<< endDepth<< endl;
    if( currDepth == endDepth){
        int wordCnt=0;
        for(int i=0; i<N;i++){
            if(isLeftIncludeRight(bitMask,masked[i])){
                // cout << v[i] << endl;
                wordCnt++;
            }
            
        }
        // cout << "===" << wordCnt << " bitmask : "<<bitMask << "masked " << masked[0] <<"===" << endl;
        answer= max(answer, wordCnt);
        return;
    }
    
    for(int i=lastIdx; i<26;i++){

        char alpha ='a' +i;
        if(!isAntic(alpha)){
            bitMask = bitMask | 1 << i;
            dfs(currDepth+1, endDepth, bitMask ,i+1);
            bitMask = bitMask & (~(1<<i));
        }
    }   
    return;
}

int main() {


    cin >> N >> K;

    
    for(int i=0; i<N; i++){
        string tmp;
        cin >> tmp;
        v.push_back(tmp);
        for( char c : tmp ){
            if(!isAntic(c)){
                masked[i] = masked[i] | (1 << (c-'a'));
            }
        }
    }

    // cout <<"input finish" << endl;

    if(K<5) {
        cout << 0 << endl;
        return 0;
    }

    dfs(0,K-5,0,0);
    
    
    cout << answer << endl;
    
    return  0;


}