#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>


int main(){
    int n;
    int dp[1001][1001];
    int job[1001][2];
    cin >> n;
    for (int i = 0; i < n; i++){
        int x, y;
        cin>> x >> y;
        dp[0][0] = 0;
        if(i==1){
          dp[0][1] = abs(n- x)+ abs(n -y);
          dp[1][0] = abs(1- x)+ abs(1 -y);
          continue;
        }
        for (int j= 0; j<i; j++){
          if (j==i-1){
              int min = 10000000;
              int min2 = 10000000;
              int temp =0;
              int temp2 =0;
              for (int k = 0; k < i-1; k++){
                temp = dp[k][i-1]+abs(job[k][0]- x)+ abs(job[k][1] -y);
                temp2 = dp[i-1][k]+abs(job[k][0]- x)+ abs(job[k][1] -y);
                if (temp < min){
                  min = temp;
                }
                if (temp2 < min){
                  min2 = temp2;
                }

              }
              dp[j][i] = min;
              dp[i][j] = min2;

          }
          else{
            dp[j][i] = dp[j][i-1]+abs(job[i][0]- x)+ abs(job[i][1] -y);
            dp[i][j] =dp[i][j-1]+abs(job[j][0]- x)+ abs(job[j][1] -y);
          }

        }
\    }
    int min1 = 10000000;
    int min2 = 10000000;
    int ans[n+1];
    int next[2];
    int current[2]={n,n};
    int cur = n;
    
    for (int i = 0; i < cur+1; i++){
      if (dp[i][cur] < min){
        min1 = dp[i][cur];
        current[0]= i
        current[1] = cur;

      }
      if (dp[cur][i] < min){
        min2 = dp[cur][i];
        current[0]= cur
        current[1] = i;

      }
    }
    if (min1 < min2){
      ans[cur] = 1;
      if(current[0] == cur-1){
        int t_min = 10000000;
        for (size_t i = 0; i < cur-1; i++)
        {
          if(dp[cur-1][i] < t_min){
            t_min = dp[i][cur];
            next[1] = cur-1;
            next[0] = i;
          }
        }

      }
      else{
        next[0] = current[0]
        next[1] = current[1]-1;
      }
    }
    else{
      ans[cur] = 2;
       if(current[1] == cur-1){
         int t_min = 10000000;
        for (size_t i = 0; i < cur-1; i++)
        {
          if(dp[cur-1][i] < t_min){
            t_min = dp[i][cur];
            next[1] = cur-1;
            next[0] = i;
          }
        }
      }
      else{
        next[0] = current[0];
        next[1] = current[1]-1;
      }
    }
    cout << min << '\n';
    return 0;


}