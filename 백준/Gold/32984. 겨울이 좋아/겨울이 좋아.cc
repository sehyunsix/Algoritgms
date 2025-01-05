#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<long long> A, B;

// 판별 함수: x일 동안 모든 낙엽을 제거할 수 있는가?
bool canFallInDays(long long x) {
  long long specialUses = 0; // 특별한 능력을 사용할 수 있는 총 횟수
  for (int i = 0; i < N; i++) {
    // (A[i] - B[i] * x): x일 동안 떨어지지 않는 나뭇잎의 개수
    long long remaining = A[i] - B[i] * x;
    if (remaining > 0) {
      // 남은 나뭇잎을 모두 제거하기 위해 필요한 능력 사용 횟수
      long long requiredUses = (remaining + B[i] - 1) / B[i]; // 올림 계산
      specialUses += requiredUses;
    }
    // 필요한 능력 사용 횟수가 x일을 초과하면 불가능
    if (specialUses > x) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  A.resize(N);
  B.resize(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) cin >> B[i];

  long long left = 1, right = 1e9; // 이분 탐색 범위
  long long result = right;

  // 이분 탐색 시작
  while (left <= right) {
    long long mid = (left + right) / 2;
    if (canFallInDays(mid)) {
      result = mid; // mid일 동안 가능하다면 더 작은 값을 탐색
      right = mid - 1;
    }
    else {
      left = mid + 1; // mid일 동안 불가능하다면 더 큰 값을 탐색
    }
  }

  cout << result << "\n";
  return 0;
}
