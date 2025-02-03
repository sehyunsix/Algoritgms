#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;
  vector<int> v(N);

  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());  // 정렬

  unordered_set<int> sumSet;

  // 가능한 모든 두 수의 합을 저장
  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {  // 자기 자신도 포함 가능
      sumSet.insert(v[i] + v[j]);
    }
  }

  // d = v[k]를 큰 값부터 탐색
  for (int k = N - 1; k >= 0; k--) {
    for (int z = 0; z < k; z++) {
      int target = v[k] - v[z];  // d - v[z]가 두 수의 합인지 확인
      if (sumSet.find(target) != sumSet.end()) {
        cout << v[k] << "\n";
        return 0;
      }
    }
  }

  return 0;
}
