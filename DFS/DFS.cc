#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;


int v, e; // 정점의 개수, 간선의 개수
vector<vector<int>> graph; // 인접 리스트
vector<bool> isVisited; // 정점 방문 여부 저장

void input_1(){
    cin >> v >> e;
    // 메모리 공간 할당 및 초기화
    graph.resize(v+1);
    isVisited.resize(v+1, false);


    for(int i = 0; i < e; i++){
    	int s, e;
        cin >> s >> e;
        // 양방향 간선을 연결시킨다.
        graph[s].emplace_back(e);
        graph[e].emplace_back(s);
    }
}

void DFS(int cur){
    isVisited[cur] = true;
    cout << "방문한 노드 : " << cur << '\n';

    // 현재 정점과 간선으로 연결되어 있는 모든 정점들을 둘러본다.
    for(int i = 0; i < graph[cur].size(); i++){
    	int next = graph[cur][i];
        // 만일 방문하지 않았다면 매개변수로 전달하여 DFS를 재귀적으로 호출한다.
        if(!isVisited[next]){
        	DFS(next);
        }
    }
}
int main(){
    input_1();
    // 1번 정점부터 방문 시작
    DFS(1);
    return 0;

}

