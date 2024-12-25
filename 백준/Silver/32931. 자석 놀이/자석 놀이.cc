#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<queue>
#include<string>
#include<math.h>
#define ll long long
using namespace std;

ll S[2][200000];
ll dp[2][200000];

int main(){

  int N;

  cin >> N;

  for(int i=0; i< 2;i++){
    for(int j=0; j< N; j++){
      cin >> S[i][j];
    }
  }

  dp[0][0]=max(S[0][0]+ S[1][0],S[0][0]);
  dp[1][0]=S[1][0]+S[0][0];

  for(int i=1;i<N;i++){

    dp[0][i] = max(max(dp[0][i-1]+S[0][i],dp[1][i-1]+S[1][i]+S[0][i]),dp[0][i-1]+S[0][i]+S[1][i]);
    dp[1][i] = max(max(dp[1][i-1]+S[1][i],dp[0][i-1]+S[1][i]+S[0][i]),dp[1][i-1]+S[0][i]+S[1][i]);


  }

  cout << dp[1][N-1];


  return 0;
}
