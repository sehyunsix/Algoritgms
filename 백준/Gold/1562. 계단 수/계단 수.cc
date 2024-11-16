#include <iostream> //iostream이라는 헤더를 가져온다

using namespace std; //namespace의 std 모듈을 사용한다


int main() { //메인메소드의 시작지점이다.

    int N;
    cin  >> N;
    long long dp[100][10][1024]={0,};

    // memset(dp ,0 ,sizeof(long long));
    for(int i=0; i<100;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<1024;k++){
                dp[i][j][k]=0;
            }
        }
    }

    // cout  << "debug";

    for(int j=0; j<10; j++){

         dp[0][j][1<<j] =1;

    }

    // cout  << "debug";

    for(int i=1; i<N; i++){
        for(int j=0; j<10; j++){
            for(int k=0; k<1024; k++){
                // cout << (k | 1 << j) <<endl;

                if(j==0) {
                    dp[i][j][ k | 1 << j]  += dp[i-1][j+1][k];
                    dp[i][j][ k | 1 << j]  %=  1000000000;
                }
                else if(j==9){
                     dp[i][j][ k | 1 << j]  += dp[i-1][j-1][k];
                    dp[i][j][ k | 1 << j]  %=  1000000000;

                }
                else{
                dp[i][j][ k | 1 << j]  += dp[i-1][j-1][k];
                dp[i][j][ k | 1 << j]  += dp[i-1][j+1][k];
                dp[i][j][ k | 1 << j]  %=  1000000000;
                    }
                   dp[i][j][ k | 1 << j]  %=  1000000000;

                }
            }
        }

    long long result=0;

    for(int i=1; i<10; i++){
        result +=dp[N-1][i][1023];
        result %= 1000000000;
    }
    // cout <<"debug"<<endl;

    cout << result;
    // cout <<"debug"<<endl;

    }



