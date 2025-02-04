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


    int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<ll> numbers(N);
    vector<ll> accum(N + 1,0);
    vector<ll> mod_array(1001,0);


    for (int i = 0; i < N;i++) {
      cin >> numbers[i];
      accum[i + 1] = accum[i] % M + numbers[i] % M;
    }

    for (int i = 0; i < N + 1;i++) {
      int md = accum[i] % M;
      mod_array[md] += 1;
    }

    ll sol = 0;
    for (int i = 0; i < M;i++) {
      if (mod_array[i] >= 2) {
        sol += mod_array[i] * (mod_array[i] - 1) / 2;
      }
      }

    cout << sol << endl;
    return 0;
    }