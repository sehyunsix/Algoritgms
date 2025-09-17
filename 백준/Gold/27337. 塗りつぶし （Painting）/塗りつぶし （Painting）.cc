// 백준 23723번
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int m[500][500];
bool visited[500][500];
int g[500][500];

int nxny[4][2]={
    {1,0},
    {-1,0},
    {0,1},
    {0,-1}
};


bool cmp(pair<int,int> a, pair<int,int> b ){
    return a.second > b.second;
}


typedef struct Ground{
    int color;
    int size;
    set<int> adj;

}Ground;

Ground garray[250000];



void print2DMap( int map2d[500][500] ,int n ,int m ){
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cout << map2d[i][j];
        }
        cout<<endl;
    }
}

void connect(int grounId1, int groundId2){

};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M;
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        for(int j=0;j<M;j++){           
           cin >>  m[i][j];
        }
    }

    

    //뭉텅이
    int groundId =0;
    for(int i=0;i<N;i++){
        for(int j=0; j<M;j++){
            if(!visited[i][j]){
                
                int color= m[i][j];
                int groundSize =1;
                visited[i][j] = true;
                g[i][j] = groundId;

                queue< pair<int,int> > q;
                q.push({i,j});
                 while(!q.empty()){

                    pair<int,int> curr= q.front();
                    q.pop();
                    
                    for(int n=0;n<4;n++){
                        pair<int,int> next={
                            curr.first + nxny[n][0],
                            curr.second+ nxny[n][1]
                        };

                        if(next.first <0 || next.first >=N || next.second<0 || next.second>=M) continue;
                        if(visited[next.first][next.second]) continue;
                        if(m[next.first][next.second] != color) continue;
                        
                        visited[next.first][next.second] = true;
                        g[next.first][next.second] = groundId;
                        groundSize++;
                        q.push(next);
                    }
                }
                garray[groundId].color=color;
                garray[groundId].size= groundSize;
                groundId++;
            }
        }
    }

    //연결
    for(int i=0;i<N;i++){
        for(int j=0; j<M; j++){
            for(int n=0; n<4; n++){
                pair<int,int> next ={
                    i+nxny[n][0],
                    j+nxny[n][1]
                };
                if(next.first <0 || next.first >=N || next.second<0 || next.second>=M) continue;
                if(g[i][j] != g[next.first][next.second]){
                    garray[g[i][j]].adj.insert(g[next.first][next.second]);
                    garray[g[next.first][next.second]].adj.insert(g[i][j]);
                }
            }
        }
    }

    // print2DMap(g,N,M);

    int sol=0;
    if (groundId ==1) {
        cout << garray[0].size << endl;
        return 0;
    }

    for(int i=0; i<groundId; i++){
        map<int, int> colorSum;
        for(auto adjId : garray[i].adj){
            colorSum[garray[adjId].color] += garray[adjId].size;
        }
        vector<pair<int,int>> v(colorSum.begin(), colorSum.end());
        sort(v.begin(),v.end(),cmp);
        pair<int,int> p =v.front();
        sol =max(sol , p.second+garray[i].size);        
        
    }

   

    cout << sol;
    


    /**
     * 
     * 전략을 생각해보면
     * 
     * 같은 뭉텅이들을 일단 모두 구한다. bfs로 ...
     * 
     * 그리고 뭉터이들의 연결 관계를 모두 구한다. 
     * 
     * 뭉텅이들은 bfs로 구할 수 있다. 그런데 뭉텅이를 구하면서 옆에 있는 뭉텅이를 구할 순 없을까?
     * 
     * bfs를 두번하면 그렇게 구할 수 있을 것 같다.
     * 
     * 예를 들어 첫번쨰 bfs에서는 그냥 뭉텅이만 구한다.
     * 
     * 두번쨰 bfs에서는 각 영역에 연결된 노드를 구한다. 
     * 
     * 만약 다른 땅에 도착했으면, 연결로 표시한다. 그럼 엣지가 만들어진다. 
     * 
     * 영역에 대한 id 고유번호를 가지고 있고, 각 영역의 색깔을 가지고 있으면 된다.
     * 
     * 자 그러면 영역에 대해서 연결이 됬다고, 하면 각 노드마다 연결이 된 id들을 알 수 있을 것이다.
     * 
     * 이 id들을 하나의 색깔로 groupby sum을 하자. 그러면 각 노드에서 가장 큰 색깔을 알 수 있다.
     * 
     * 그러면 여기서 가장 큰 sum을 찾을 수 있다.
     * 
     * 가장 큰 sum을 찾았다는 것은, 그 sum + 현재 노드 id sum을 하면된다. 이거의 max를 찾으면된다.
     * 
     * 자 그러면  어차피 500*500 으로 돌면되는데. 연결된 영역이  그렇게 많치는 않을 것 같다.
     * 
     * 만약에 n이 너무 느리다면, priority_queue를 써도 된다. 어차피 가장 큰 값 만 기억하면 되니깐.
     */
    

    
    return 0;
}