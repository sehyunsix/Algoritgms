// 백준 14572번
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define MAX_LEN 100000



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,K,D,M,tmp;
    vector<vector<int>> p(MAX_LEN , vector<int>());
    vector<int> d(MAX_LEN, 0);
    
    cin >> N >> K >> D;

    vector<int> s(N);
    for(int i = 0; i < N; i++) {
        s[i] = i;
    }
    for(int i=0; i<N;i++){
        cin >> M >> d[i];
        for(int j=0; j<M;j++){
            cin >> tmp;
            p[i].push_back(tmp-1);
        }
    };

    sort(s.begin(), s.end(), [&d](int a, int b) {return d[a] < d[b];
    });

    int start=0, end=0, currDiff=0, currScore=0, bestScore=0;
    int maxD =0, minD=INT32_MAX;
    vector<int> currSolCnt(30 ,0);

    while(end<=N-1){
        minD=d[s[start]];
        maxD=d[s[end]];
        currDiff =maxD - minD;

        if(currDiff>D){
            currDiff += s[start];
            for(auto& solIdx : p[s[start]]){
                currSolCnt[solIdx]--;
            }
            start++;
            currDiff -= s[start];
            continue;
        }

        for(auto& solIdx : p[s[end]]){
                currSolCnt[solIdx]++;
        }
        int allSolCnt = 0;
        int totalSolCnt = 0;
        for(auto& solCnt : currSolCnt){
            if(solCnt){
                totalSolCnt++;
                if(solCnt==(end-start+1)){
                    allSolCnt++;
                }
            }
        }
        
        // cout << "currSolCnt : ";
        // for(auto& i : currSolCnt){
        //     cout << i << " ";
        // }
        // cout << endl;
        // cout << "total sol Cnt "  << totalSolCnt << endl;
        // cout << "all sol Cnt "  << allSolCnt << endl;


        currScore =(totalSolCnt -allSolCnt)* (end -start+1);
        bestScore = max(currScore, bestScore);
        end++;
    }
    cout << bestScore << endl;
    

    
    return 0;
}