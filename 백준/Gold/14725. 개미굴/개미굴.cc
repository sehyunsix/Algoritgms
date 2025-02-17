#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<queue>
#include <string>
#include<math.h>
#include<map>
#define ll long long
#define P 1000000007
#define endl "\n"
using namespace std;

typedef struct node {
  string value;
  vector<node> childs;
}node;



bool cmp(node a, node b){
  return a.value < b.value;
}

void insert(node& curr, int level, vector<string>& inputs) {
  if (level + 1 == (int)inputs.size()) {
    return;
  }
  bool chk = false;
  for (node& c : curr.childs) {
    if (inputs[level + 1] == c.value) {
      chk = true;
      insert(c, level + 1, inputs);
    }
  }
  if (!chk) {
    curr.childs.push_back({ inputs[level + 1], vector<node>() });
    insert(curr.childs[curr.childs.size()-1], level + 1, inputs);
  }
  return;
}

void dfs(node& curr, int level) {
  string s = "";
  for (int i = 0; i < level;i++) {
    s += "--";
  }
  // cout << level << endl;
  if (level != -1)  cout << s << curr.value << endl;
  sort(curr.childs.begin(), curr.childs.end(), cmp);
  for (node& c : curr.childs) {
    dfs(c, level + 1);
  }
}

int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);

int N;
cin >> N;
node root = { "*" ,vector<node>() };
for (int i = 0; i<N;i++) {
  int M;
  cin >> M;
  vector<string> s;
  for (int i = 0; i < M;i++) {
    string tmp;
    cin >> tmp;
    s.push_back(tmp);
    // cout << "insert done" << endl;
  }
  insert(root, -1, s);

}

dfs(root, -1);

return 0;
}