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
#define ERROR 0.00001
// #define DEBUG
  using namespace std;

  int N;
  vector<int> edge_list[3000];
  bool visit_list[3000];
  int sol;

  typedef struct lane {
    pair<int, int> p1;
    pair<int, int> p2;

  }lane;

  typedef struct equation{
    int v_coff;
    int c_coff;

  }equation;


  pair<equation,equation> make_eqs(lane a) {
    // eq x_eq.first *t + x_eq.second *1
    equation x_eq, y_eq;
    x_eq.v_coff = -a.p1.first + a.p2.first;
    x_eq.c_coff = a.p1.first;
    y_eq.v_coff = -a.p1.second + a.p2.second;
    y_eq.c_coff = a.p1.second;
    return { x_eq, y_eq };
  }

  bool solve_eq(pair<equation, equation> eq1s, pair<equation, equation> eq2s) {

    vector<double>  s_x = { (double) eq1s.first.v_coff ,  -1 * (double)eq2s.first.v_coff , (double) eq2s.first.c_coff - eq1s.first.c_coff };
    vector<double>  s_y = { (double) eq1s.second.v_coff ,  -1 * (double)eq2s.second.v_coff , (double)eq2s.second.c_coff - eq1s.second.c_coff };
    #ifdef DEBUG
    cout << "s_x: ";
    for (int i = 0; i < 3; i++) {
      cout << s_x[i] << " ";
    }
    cout << endl;
    cout << "s_y: ";
    for (int i = 0; i < 3; i++) {
      cout << s_y[i] << " ";
    }
    cout << endl;
    #endif

    double A[2][2] = { {s_x[0] ,s_x[1]} ,
      {s_y[0] ,s_y[1]}
    };

    double B[2] = {
      s_x[2], s_y[2]
    };

    double det_A = A[0][0] * A[1][1] - A[0][1] * A[1][0];

    if (abs(det_A)> 0.0000001) {
      vector<vector<double>> I_A;
      I_A = {
        {A[1][1]/det_A, -1 * A[0][1]/det_A },
        {-1 * A[1][0]/det_A, A[0][0]/det_A }
      };
      double t = I_A[0][0] * B[0] + I_A[0][1] * B[1];
      double k = I_A[1][0] * B[0] + I_A[1][1] * B[1];
      if (0-ERROR <= t && t <= 1+ERROR && 0-ERROR <= k && k <= 1+ERROR) {
        return true;
      }
    }
    else {

      double a = A[0][0];
      double ak = A[0][1];
      double b = A[1][0];
      double bk = A[1][1];
      if (a != 0 && b != 0) {
        double k = ak / a;
        if (B[0] / a == B[1] / b) {
          if (0 <= B[0] / a && B[0] / a <= 1 && 0 <= B[0] / a - k && 0 <= B[0] / a - k) {
            return true;
          }
          if (k != 0 && 0 <= (B[0] / a - 1) / (k) && (B[0] / a - 1) / (k) <= 1) {
            return true;
          }
          if (k != 0 && 0 <= (B[0] / a) / (k) && (B[0] / a) / (k) <= 1) {
            return true;
          }
          if ((k == 0 && B[0] / a == 1) || (k == 0 && B[0] / a == 0)) {
            return true;
          }
        }
      }

      if (a == 0 && b == 0) {
        if (B[0] == 0 && B[1] == 0) {
          return true;
        }
      }

      if (a != 0 && b == 0 && B[1] == 0) {
          double k = ak / a;

          if (0 <= B[0] / a && B[0] / a <= 1 && 0 <= B[0] / a - k && 0 <= B[0] / a - k) {
            return true;
          }
          if (k != 0 && 0 <= (B[0] / a - 1) / (k) && (B[0] / a - 1) / (k) <= 1) {
            return true;
          }
          if (k != 0 && 0 <= (B[0] / a) / (k) && (B[0] / a) / (k) <= 1) {
            return true;
          }
          if ((k == 0 && B[0] / a == 1) || (k == 0 && B[0] / a == 0)) {
            return true;
          }

      }

      if (a == 0 && b != 0 && B[0] == 0) {
        double k = bk / b;


        if (0 <= B[1] / b && B[1] / b <= 1 && 0 <= B[1] / b - bk / b && 0 <= B[1] / b - bk / b) {
          return true;
        }
        if (k != 0 && 0 <= (B[1] / b - 1) / (k) && (B[1] / b - 1) / (k) <= 1) {
          return true;
        }
        if (k != 0 && 0 <= (B[1] / b) / (k) && (B[1] / b) / (k) <= 1) {
          return true;
        }
        if ((k == 0 && B[1] / b == 1) || (k == 0 && B[1] / b == 0)) {
          return true;
        }

      }

      return false;

    }

    return false;

  }

  bool check_cross(lane a, lane b) {

    pair<equation, equation> eq1s, eq2s;
    eq1s = make_eqs(a);
    eq2s = make_eqs(b);
    // cout << solve_eq(eq1s, eq2s) << endl;
    return solve_eq(eq1s, eq2s);
  }

  void dfs(int node , int& num) {
    visit_list[node] = true;
    num += 1;

    for (int e : edge_list[node]) {
      if (!visit_list[e]) {
        dfs(e ,num);
      }
    }
  }

  int main() {

  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> N;
  vector<lane> lv;


  for( int i =0 ; i<N ; i++){
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    lv.push_back({ {x1,y1},{x2,y2} });
  }

  for (int i = 0; i< N-1;i++) {
    for (int j = i + 1; j < N; j++) {
      #ifdef DEBUG
      cout << "check cross : " << i << " " << j << endl;
      #endif
      if (check_cross(lv[i], lv[j])) {
        edge_list[i].push_back(j);
        edge_list[j].push_back(i);
      }
    }
  }

  #ifdef DEBUG
  cout << "edge_list" << endl;
  for (int j = 0; j < N;j++) {
    cout << j << " : ";
    for (auto e : edge_list[j]) {
      cout << e << " ";
    }
    cout << endl;
  }
  #endif

  int ans1 = 0;
  int ans2 = 0;

  for (int i = 0; i < N;i++) {
    int tmp = 0;
    if (!visit_list[i]) {
        dfs(i, tmp);
    }
    if (tmp > 0) {
      ans1 += 1;
    }
    ans2 = max(tmp, ans2);


  }

  cout << ans1 << endl;
  cout << ans2 << endl;
  // cout << (1 ^ 0) << endl;
  // cout << (1 ^ 1) << endl;
  // cout << (0 ^ 0) << endl;

  return 0;
  }