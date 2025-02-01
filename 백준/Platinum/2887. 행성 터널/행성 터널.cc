#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<queue>
#include <string>
#include<math.h>
#define ll long long
#define P 1000000007
#define endl "\n"
#define INF 2000000001
using namespace std;
int N;




//x = 0 y=1 z=2
int sci_list[100000][3];
bool visited_list[100000];
bool cmp( pair<int,int>  a , pair<int,int> b){
  return a.first < b.first;
}


typedef struct custom_greater {
  bool operator()(const pair<int, int> a, const pair<int, int> b) {
    return a.first > b.first;
  }
}custom_greater;

int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);

cin >> N;
vector<vector<int>> node_list;
vector<pair<int,int>> coord[3];


for (int i = 0; i < N; i++) {
  int x , y , z;
  cin >> x >> y >> z;
  node_list.push_back({ x,y,z });
  coord[0].push_back({x ,i});
  coord[1].push_back({y ,i});
  coord[2].push_back({z ,i});
}

for (int i = 0; i < 3; i++) {
  sort(coord[i].begin(), coord[i].end(), cmp);
}

for(int i=0; i< N; i++){
  for (int j = 0;j < 3;j++) {
    sci_list[coord[j][i].second][j] = i;
  }
}


// for(int i=0; i<3; i++){
//   for(auto p : coord[i]){
//     cout << p.first << "-"<<p.second << " ";
//   }
//   cout << endl;
// }


priority_queue<pair<int, int>, vector<pair<int, int>>, custom_greater> q;
int count = 0;
int key_id = 0;
q.push({ 0,0 });
// q.push({ 0,0 });
// q.push({ 1,0 });
int answer = 0;
int dis = 0;
while (count < N) {
  // cout << count << endl;
  while ((!q.empty()) && (visited_list[q.top().second])) {
    q.pop();
  }
  if(q.empty()){
    break;
  }
  pair<int, int> node = q.top();
  // cout << "pop  value : " << node.first <<"key : "<< node.second << endl;

  q.pop();
  // cout << "pop after value : " << q.top().first << "key : " << q.top().second << endl;

  visited_list[node.second] = true;
  answer += node.first;
  // cout << "pop  value : " << node.first <<"key : "<< node.second << endl;
  count += 1;
  for (int i = 0; i < 3; i++) {
    int idx = sci_list[node.second][i];
    if (idx - 1 > -1 && !visited_list[coord[i][idx - 1].second]) {
      dis = abs(coord[i][idx].first - coord[i][idx - 1].first);
      // cout << "push : dis " << dis << "key : " << coord[i][idx - 1].second << "type : " << i<<"idx: " << idx - 1 << endl;
      q.push({ dis, coord[i][idx - 1].second });
    }

    if (idx + 1 < N && !visited_list[coord[i][idx + 1].second]) {
      dis = abs(coord[i][idx].first - coord[i][idx + 1].first);
      // cout << "push  : dis" << dis << "key : "<<coord[i][idx + 1].second<<"type : "<< i <<"idx: " <<idx+1 << endl;
      q.push({ dis, coord[i][idx + 1].second });
    }
  }


}



cout << answer << endl;

return 0;
}