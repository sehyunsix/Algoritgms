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

double getPosDistance(pair<int, int> a, pair<int, int> b) {
  return sqrt(pow((a.first - b.first), 2) + pow((a.second - b.second), 2));
}

class Circle {
public:
  pair<int, int> pos;
  int radius;

  Circle(pair<int, int> pos, int radius) {
    this->pos = pos;
    this->radius = radius;
  }

  bool isInclue(Circle c) {
    return getPosDistance(c.pos, this->pos) + c.radius < this->radius;
  }
};

bool cmp(Circle a, Circle b) {
  return a.radius < b.radius;
}

int main() {
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
int T;
cin >> T;
for (int t = 0; t < T; t++) {
  int x1, y1, x2, y2, N;
  cin >> x1 >> y1 >> x2 >> y2 >> N;
  vector<Circle> v;

  Circle st({ x1,y1 }, 0);
  Circle en({ x2,y2 }, 0);

  for (int i = 0; i < N; i++) {
    int x, y, r;
    cin >> x >> y >> r;
    v.push_back(Circle({ x,y }, r));
  }


  sort(v.begin(), v.end(), cmp);

  int bigCircleIdx = v.size();
  for (int i = 0; i < v.size();i++) {
    if (v[i].isInclue(st) && v[i].isInclue(en)) {
      bigCircleIdx = i;
      break;
    }
  }


    int stCircleCnt = 0;
  for (int i = 0; i <= bigCircleIdx - 1;i++) {
    if (v[i].isInclue(st)) {
      stCircleCnt++;
    }
  }

  int enCircleCnt = 0;
  for (int i = 0; i <= bigCircleIdx - 1;i++) {
    if (v[i].isInclue(en)) {
      enCircleCnt++;
    }
  }
  // cout << stCircleCnt <<" " <<enCircleCnt << endl;
  cout << stCircleCnt + enCircleCnt << endl;
}
return 0;
}
