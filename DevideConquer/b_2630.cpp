#include <iostream>
#include<bitset>
using namespace std;

int m[129][129];
int blue_count;
int white_count;

int solve(int x, int y, int n)
{
  if(n==1 ){
    if(m[x][y]==1){ blue_count += 1; return 1;}
    else{white_count += 1; return 0;}
  }

  int a = solve(x, y, n /2);
  int b= solve(x, y + n / 2, n / 2);
  int c= solve(x+n/2 , y, n/2);
  int d= solve(x+n/2 ,y+n/2 ,n/2 );

  if(a<0 || b<0 || c<0 || d<0){
    return -1;
  }
  // printf("%d %d %d %d", a,b,c,d);
  // printf("%d\n",(a|b|c|d));
  if(a & b & c & d){ blue_count -= 3; return 1;}
  else if((a|b|c|d)==0){white_count -=3; return 0;}
  else{ return -1;}
}

int main()
{

  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> m[i][j];
    }
  }
  solve(0,0,n);
  cout << white_count << '\n'<< blue_count<<'\n';
}
