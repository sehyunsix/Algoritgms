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

vector<vector<int>> childNodes;
vector<int> v;

void dfs(int start, int end) {
  if (start> end) {
    return;
  }
  if (start == end) {
    cout << v[end] << endl;
    return;
  }
  int mid_index = end+1;
  for (int i = start + 1; i <= end;i++) {
    if (v[start]< v[i]) {
      mid_index = i;
      break;
    }
  }
  dfs(start + 1, mid_index - 1);
  dfs(mid_index, end);
  cout << v[start] << endl;
}

int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
int tmp;
while (!(cin >> tmp).eof()) {
  v.push_back(tmp);
}

int N = v.size();
dfs(0 , N-1);


return 0;
}