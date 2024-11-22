#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#define ll long long
#define MAP_SIZE 19683
using namespace std;


int BINGO_INDEX[8][3]={
  {0,1,2},
  {3,4,5},
  {6,7,8},
  {0,3,6},
  {1,4,7},
  {2,5,8},
  {0,4,8},
  {2,4,6},
};

int board_result[200000][2]={0,};
int p3[9]={1,};
int map[9]={0};
ll win_x=0;
ll win_o=0;

bool check_win(int player){
    bool result =0;
    for(int i=0; i <8; i++){
      bool tmp = 1;
      for(int j=0;j<3;j++){
       tmp = (tmp && ( player == map[BINGO_INDEX[i][j]] ));
      }
      result = result || tmp;
    }
    return result;
}

int get_key(int* map ){
    int key =0;
    for(int i =0; i <9; i++){
      key += map[i]*p3[i];
    }
    return key;
}

void dfs(int player , int key){


    int opp = 3-player;

    if(check_win(opp)){
      // cout << "key : "  << key << "player " << 2-(depth%2) <<endl;

      board_result[key][opp-1]=1;
      board_result[key][player-1]=0;

      // for(int i=0; i<3; i++){
      //   for(int j=0; j<3; j++){
      //     cout << map[i*3+j]<< " ";
      //   }
      //   cout <<endl;
      // }
    }
    else{

    board_result[key][0]=0;
    board_result[key][1]=0;

    for(int i=0; i<9;i++){
      if( map[i] ==0){

      map[i] = player;
      int next_key = get_key(map);
      dfs(opp,next_key);
      board_result[key][0] += board_result[next_key][0];
      board_result[key][1] += board_result[next_key][1];
      map[i] = 0;

      }
    }

    }

}

int main(){


  for(int i=1; i<9; i++){
      p3[i]=p3[i-1]*3;
  }

  memset(board_result ,-1, 200000*2*sizeof(int));

  dfs(1 ,0);



  int T;
  cin  >> T;
  for(int t=0; t<T; t++){

    int depth =0;
    win_x=0;
    win_o=0;
    int num_x=0;
    int num_o=0;

    for(int i=0; i< 9;i++){
        char value;
        cin >> value;
        if(value == 'X'){
          map[i]=1;
        }
        else if (value == 'O'){
          map[i]= 2;
        }
        else{
          map[i]=0;
        }
    }

    int key =get_key(map);
    cout << board_result[key][0] << " " << board_result[key][1] << endl;

  }


}