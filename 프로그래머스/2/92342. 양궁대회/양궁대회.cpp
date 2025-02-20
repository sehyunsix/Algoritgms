#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> board;
vector<int> sol;
vector<int> apeach;
int maxDiffScore =0;

int calDiffScore(vector<int> board){
    int apeachScore =0;
    int lionScore =0;
    for(int i=0; i<11; i++){
       if(board[i] ==0 && apeach[i] ==0) continue;
       if(board[i] > apeach[i] ) lionScore += 10-i;
       else apeachScore += 10-i;
    }
    return lionScore -apeachScore;
}

bool cmp (vector<int> a, vector<int> b){
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    return a > b;
}


void dfs(int n ,int level){
    if(n==0 ||level == 11 ) {
        board[10] += n;
        int diffScore =calDiffScore(board);
        if(maxDiffScore > diffScore) return;
        if(maxDiffScore < diffScore){
            maxDiffScore = diffScore;
            sol = board;
            return;
        }
        if(cmp(board, sol)) sol =board;
        return;
    }
    
    for(int i=0; i<=n; i++){
        board[level] = i;
        dfs(n-i, level+1);
        board[level]=0;
    }
    return;
}


vector<int> solution(int n, vector<int> info) {
    board = vector<int>(11, 0 );
    sol = vector<int>(11 ,0);
    apeach = info;
    dfs(n,0);
    vector<int> answer = sol;
    if(maxDiffScore == 0) return {-1};
    return answer;
}