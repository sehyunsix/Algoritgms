#include<iostream>
#include<algorithm>
#include <cstdlib>
using namespace std;
int compare(const void* a, const void* b)
{
	const int* x = (int*) a;
	const int* y = (int*) b;
 
	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;
 
	return 0;
}
 
int main()
{   int N,M,num;
    cin>>N;
     int m[N];
    for(int i=0;i<N;i++){
        scanf("%d",m+i);
    }
    cin>>M;
    qsort(m,N,sizeof(m[0]),compare);
    while(M--){
        scanf("%d",&num);
        printf("%d\n",binary_search(m,m+N,num));
    }
    
    return 0;
	
	}

    

