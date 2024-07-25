#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<random>
#include <chrono>
#include <map>
#include<stdio.h>
#define INF 987654321

using namespace std;

struct Edge{
  map< int,int > near_list;
}typedef Edge;


int start_distance[20001];
bool visited[20001]={false};
Edge node_list[20001];

priority_queue<pair<int,int>> pq;

void Dickstra(int n, int v, int start){

  for (int i=1;i<n+1;i++){
    start_distance[i] = INF;
  }



  start_distance[start] =0;
  visited[start] = true;


  pq.push({0,start});

  while(!pq.empty()){
    // printf("pq size %zu\n",pq.size());
    int current_node_num = pq.top().second;
    visited[current_node_num] = true;
    pq.pop();

    map<int,int> near_list = node_list[current_node_num].near_list;


  for (auto iter: near_list){
    int child_node_num = iter.first;
    int weight = iter.second;
    int tmp = start_distance[current_node_num] + weight;

    if(start_distance[child_node_num] > tmp && !visited[child_node_num]){
       start_distance[child_node_num] = tmp;
       pq.push({-start_distance[child_node_num],child_node_num});
     }
  }
  }

}



using namespace std::chrono;
int main(){


  int n,v,start;
  cin >> n >> v >> start;

  auto start_time = high_resolution_clock::now();
  while(v--){
    int node1,node2,weight;
    // cin >> node1 >> node2 >> weight;
    scanf("%d %d %d",&node1,&node2,&weight);
    int* tmp =&node_list[node1].near_list[node2];
    if(*tmp==0){
      *tmp = weight;
    }
    else{
       *tmp = min(*tmp,weight);
    }
  }
  auto stop_time = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop_time - start_time);

  start_time = high_resolution_clock::now();
  cout << "Time :"<< duration.count() << '\n';

  Dickstra(n,v,start);

  for (int i=1;i<n+1;i++){
    if(start_distance[i] == INF){
      // cout << "INF"<<'\n';
      printf("INF\n");

    }
    else{
      // cout << start_distance[i]<<'\n';
      printf("%d\n",start_distance[i]);
    }
  }

stop_time = high_resolution_clock::now();
duration = duration_cast<microseconds>(stop_time - start_time);
cout << "Time :"<< duration.count() << endl;
}






