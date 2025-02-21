#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

int solution(int N, int number) {
    if (N == number) return 1;
    
    vector<unordered_set<int>> dp(9); // dp[i]: i개의 N을 사용하여 만들 수 있는 수 집합
    
    int num = 0;
    for (int i = 1; i <= 8; i++) {
        num = num * 10 + N; // N, NN, NNN, ... 생성
        dp[i].insert(num);
    }
    
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j < i; j++) {
            for (int a : dp[j]) {
                for (int b : dp[i - j]) {
                    dp[i].insert(a + b);
                    dp[i].insert(a - b);
                    dp[i].insert(a * b);
                    if (b != 0) dp[i].insert(a / b);
                }
            }
        }
        if (dp[i].count(number)) return i;
    }
    return -1;
}