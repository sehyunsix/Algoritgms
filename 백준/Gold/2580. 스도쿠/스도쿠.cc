#include<iostream>
#include<queue>
#include <cstdlib>
struct cd{
    int x;
    int y;
};

using namespace std;
int N,x=0; 
int y=0;
int solvNumver =0;
int noVisit = 0;
int zeroNumber =0;
int numarray[9][9]={0};
cd checkarray[15];
cd zeroarray[81];
int solv(cd*);
bool check(int,int,int);
bool checkX(int,int);
bool checkY(int,int);
bool cehckQ(int,int,int);
int main(){

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            scanf("%d",numarray[i]+j);
            if(*(numarray[i]+j)==0){
                zeroarray[zeroNumber].x = j;
                zeroarray[zeroNumber].y = i;
                zeroNumber += 1;
                
            }
        }
    }
    solv(zeroarray);

    return 0;
    }
   

int solv(cd* zeroPt){
    
    
    if(zeroPt==zeroarray+zeroNumber){
    printf("\n");
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            printf("%d ",*(numarray[i]+j));
        }
        printf("\n");
    }
        
         return -1;
    }
        
        for(int i=1;i<10;i++){
          

            if(check((*zeroPt).x,(*zeroPt).y,i)){
            numarray[(*zeroPt).y][(*zeroPt).x] = i;
            
            if(solv(zeroPt+1)==-1){
                return -1;
            }
            }


        }
        
         numarray[(*(zeroPt)).y][(*(zeroPt)).x] = 0;
        
     
    return 0;
    
}
bool checkX(int y,int num){
    for(int i=0;i<9;i++){
       if(numarray[y][i] == num){
        return false;
       }
    }
    return true;
}

bool checkY(int x, int num){
    for(int i=0;i<9;i++){
       if(numarray[i][x] == num){
        return false;
       }
}
return true;
}
bool checkQ(int x, int y, int num){
    int x1,y1;
    if(x<3){
        x1 =0;}
    else if(x<6){
        x1 = 3;}
    else{
        x1 =6;}
   if(y<3){
        y1 =0;}
    else if(y<6){
        y1 = 3;}
    else{
        y1 =6;}
   for(int i=y1;i<y1+3;i++){
        for(int j=x1;j<x1+3;j++){
           if(numarray[i][j] == num){
                return false;
           }
        }
   }
   return true;
    
}
bool check(int x, int y, int num){ 
    

    if(checkQ(x,y,num)&&checkX(y,num)&&checkY(x,num)){
        return true;
    }
    return false;

}
  
