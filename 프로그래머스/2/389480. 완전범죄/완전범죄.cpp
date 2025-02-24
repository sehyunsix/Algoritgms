#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 1e9;
int dp[41][121][121];  // dp[i][a][b]: i번째 물건까지 고려했을 때 A의 흔적 a, B의 흔적 b일 때의 최소 A 흔적 값

int solution(vector<vector<int>> info, int n, int m) {
    int itemCount = info.size();

    // DP 배열 초기화 (불가능한 경우 INF로 설정)
    for (int i = 0; i <= itemCount; i++)
        for (int a = 0; a <= n; a++)
            for (int b = 0; b <= m; b++)
                dp[i][a][b] = INF;

    // 초기 상태: 아무 물건도 선택하지 않았을 때 흔적은 0
    dp[0][0][0] = 0;

    // DP 계산
    for (int i = 0; i < itemCount; i++) {
        int a_trace = info[i][0], b_trace = info[i][1];

        for (int a = 0; a < n; a++) {
            for (int b = 0; b < m; b++) {
                if (dp[i][a][b] == INF) continue;

                // A 도둑이 훔치는 경우
                int new_a = min(n, a + a_trace);
                int new_b = b;
                dp[i + 1][new_a][new_b] = min(dp[i + 1][new_a][new_b], dp[i][a][b] + a_trace);

                // B 도둑이 훔치는 경우
                new_a = a;
                new_b = min(m, b + b_trace);
                dp[i + 1][new_a][new_b] = min(dp[i + 1][new_a][new_b], dp[i][a][b]);
            }
        }
    }

    // 정답 찾기
    int result = INF;
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < m; b++) {
            result = min(result, dp[itemCount][a][b]);
        }
    }

    return (result == INF) ? -1 : result;
}
