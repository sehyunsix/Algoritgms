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
    int L, K, C;
    vector<int> pos;
    int ans2 = 0;

    bool query(int x) {
      int leftPos = 0;
      int prevPosIndex = -1;
      int cntCut = C;
      int firstCutPos;
      // cout << "x :" << x << endl;
      while (cntCut > 0 && L -leftPos > x) {
        // cout << cntCut << endl;
        int st = prevPosIndex;
        int en = pos.size() - 1;
        while (st < en) {
          int mid = (st + en + 1) / 2;
          // cout << "mid :" << mid << endl;
          if (pos[mid] <= leftPos + x) st = mid;
          else en = mid - 1;
        }
        if (st == prevPosIndex) return false;
        if (cntCut == C) firstCutPos = st;
        leftPos = pos[st];
        prevPosIndex = st;
        // cout << "leftPos : " << leftPos << endl;
        cntCut--;
      }
      // cout << "remain :" << L - leftPos << endl;
      if (L - leftPos > x) return false;
      // cout << "first : " << firstCutPos << endl;
      ans2 = (cntCut > 0 ? 0 : firstCutPos);
      // cout << "ans2 " << ans2 << endl;


      return true;
    }

    bool firstPosQuery(int x, int p) {
      int leftPos = pos[p];
      int prevPosIndex = ans2;
      int cntCut = C - 1;
      // cout << x << p << endl;
      while (cntCut > 0 && L - leftPos > x) {
        int st = prevPosIndex;
        int en = pos.size() - 1;
        while (st < en) {
          int mid = (st + en + 1) / 2;
          if (pos[mid] <= leftPos + x) st = mid;
          else en = mid - 1;
        }
        if (st == prevPosIndex) return false;
        leftPos = pos[st];
        prevPosIndex = st;
        cntCut--;
      }
      if (L - leftPos > x) return false;
      return true;

    }

    int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> L >> K >> C;
    for (int i = 0; i < K; i++) {
      int tmp;
      cin >> tmp;
      pos.push_back(tmp);
    }

    sort(pos.begin(), pos.end());
    pos.erase(unique(pos.begin(), pos.end()), pos.end());

    int st = 1;
    int en = L;
    while (st < en) {
      int mid = (st + en) / 2;
      if (query(mid)) en = mid;
      else st = mid + 1;
    }
    int ans1 = en;

    st = 0;
    en = ans2;
    while (st < en) {
      int mid = (st + en ) / 2;
      if (firstPosQuery(ans1 ,mid)) en =mid;
      else st = mid + 1;
    }
    // cout << "en :" << en << endl;
    ans2 = pos[en];

    cout << ans1 << " " << ans2 << endl;

    return 0;
    }