// 백준 1번
#include <iostream>
#include <vector>
#include <string>
using namespace std;
    


void suffleCards(vector<int>& P, vector<int>& S){
    // cout << "shuffle"<< endl;
    vector<int> newP(P.size());

    for (int i=0; i<P.size(); i++){
            newP[S[i]]=P[i];
    }
    
    for (int i=0; i<P.size(); i++){
            P[i] =newP[i];
    }
}

bool check( vector<int>& P){
    for(int i=0; i<P.size();i++){
        if( P[i] != i%3){
            return false;
        }
    }
    return true;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, tmp;
    vector<int> P;
    vector<int> S;

    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        P.push_back(tmp);
    }
    
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        S.push_back(tmp);
    }

    int cnt = -1;
    int maxN = 1000000;
    while (maxN-->0){
        cnt++;
        if(check(P)) break;
        suffleCards(P,S);
        
    }
    if (maxN==-1){
        cnt = -1;
    }
    cout << cnt << endl;

    return 0;
}