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
    using namespace std;

    int N;
    int m[21][21];
    int sol = 0;
    bool isvalid[21][21];
    char control[4] = {
      'U','R','L','D'
    };

    void update(char d);


    void dfs(int depth) {
      // cout << depth << endl;
      // for (int i = 0; i < N; i++) {
      //   for (int j = 0; j < N;j++) {
      //     cout << m[i][j] << " ";
      //   }
      //   cout << endl;
      // }

      if (depth == 5) {
        for (int i = 0; i < N; i++) {
          for( int j =0 ; j< N;j++){
            sol = max(m[i][j], sol);
          }
        }

        // cout << "end  ==== " << endl;
        return;
      }
      int tmp[21][21];
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N;j++) {
          tmp[i][j] = m[i][j];
        }
      }
      for (int k = 0; k < 4; k++) {


        update(control[k]);
        dfs(depth + 1);

        for (int i = 0; i < N; i++) {
          for (int j = 0; j < N;j++) {
            m[i][j] = tmp[i][j];
          }
        }

      }
      return;


    }

    void update(char d) {

      for (int i = 0; i < N; i++) {
        for( int j =0 ; j<N ;j++){
          isvalid[i][j] = 1;
        }
      }

      switch (d)
      {
      case 'R':

        for (int i = 0; i < N; i++) {
          for (int j = N-2; j > -1; j--) {

            if (m[i][j] != 0) {

              int k = j + 1;
              while ((k < N-1) && m[i][k] == 0) {
                k++;
              }

              if (m[i][k] == 0) {
                m[i][k] = m[i][j];
                m[i][j] = 0;
                continue;
              }

              if (m[i][k] == m[i][j] && isvalid[i][k]) {
                m[i][k] = 2 * m[i][j];
                m[i][j] = 0;
                isvalid[i][k] = 0;

              }
              else {

                m[i][k - 1] = m[i][j];

              }


              if (k - 1 != j) {
                m[i][j] = 0;
              }


            }
          }

        }
        /* code */
        break;

        case 'L':
          for (int i = 0; i < N; i++) {
            for (int j = 1; j < N; j++) {

              if (m[i][j] != 0) {

                int k = j-1;
                while ((k > 0) && m[i][k] == 0) {
                  k--;
                }
                if (m[i][k] == 0) {
                  m[i][k] = m[i][j];
                  m[i][j] = 0;
                  continue;
                }

                if (m[i][k] == m[i][j] && isvalid[i][k]) {
                  m[i][k] = 2 * m[i][j];
                  m[i][j] = 0;
                  isvalid[i][k] = 0;
                }
                else {
                  m[i][k + 1] = m[i][j];

                }
                if (k + 1 != j) {
                  m[i][j] = 0;
                }
              }
            }

          }
          /* code */
          break;

        case 'D':
          for (int i = N-2; i >-1; i--) {
            for (int j = 0; j < N; j++) {

              if (m[i][j] != 0) {

                int k = i + 1;
                while ((k < N-1) && m[k][j] == 0) {
                  k++;
                }
                if (m[k][j] == 0) {
                  m[k][j] = m[i][j];
                  m[i][j] = 0;
                  continue;
                }

                  if (m[k][j] == m[i][j] && isvalid[k][j]) {
                    m[k][j] = 2 * m[i][j];
                    m[i][j] = 0;
                    isvalid[k][j] = 0;
                  }
                  else {
                    m[k - 1][j] = m[i][j];


                  }


                if (k - 1 != i) {
                  m[i][j] = 0;
                }
              }
            }

          }
          /* code */
          break;


        case 'U':
          for (int i = 1; i < N ; i++) {
            for (int j = 0; j < N; j++) {

              if (m[i][j] != 0) {

                int k = i -1;
                while ((k > 0) && m[k][j] == 0) {
                  k--;
                }
                if (m[k][j] == 0) {
                  m[k][j] = m[i][j];
                  m[i][j] = 0;
                  continue;
                }
                // cout << "source " << i << " " << j << "target" << k << " " << j << endl;
                if (m[k][j] == m[i][j] && isvalid[k][j]) {

                  m[k][j] = 2 * m[i][j];
                  m[i][j] = 0;
                  isvalid[k][j] = 0;
                }
                  else {
                    m[k + 1][j] = m[i][j];

                  }

                if (k + 1 != i) {
                  m[i][j] = 0;
                }
              }
            }

          }
          /* code */
          break;



      default:
        break;
      }


    }


    int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; i++) {
      for( int j =0 ; j<N;j++){
        cin >> m[i][j];
      }
    }

    // update('R');
    // update('L');
    // update('L');
    // update('D');
    // for (int i = 0; i < N; i++) {
    //   for( int j =0 ; j<N ;j++){
    //     cout << m[i][j] << " ";
    //   }
    //   cout << endl;
    // }

    dfs(0);

    cout << sol << endl;




    return 0;
    }