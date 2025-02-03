#include <stdio.h>
int N,M;
int main(void){
scanf("%d %d",&N,&M);
int arr[100];
for(int i=0;i<N;i++){
    scanf("%d",&arr[i]);
}



int max =0;
int sum =0;
for(int i=0; i<N-2;i++){
    for(int j=i+1; j<N-1; j++){
        for(int k=j+1; k<N; k++){
            sum =arr[i]+arr[j]+arr[k];
            if(sum<=M){
                if(sum>max){
                    max =sum;
                    
                }
            }
        }
    }
}
printf("%d",max);
return 0;
}

