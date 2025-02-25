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
#define maxN 51
using namespace std;
int dp[maxN];
vector<string>  words;
vector<string> sortedWords;


vector<string> findWords(string a) {
  vector<string> res;
  sort(a.begin(), a.end());
  for (int i = 0; i < words.size();i++) {
    if (sortedWords[i] == a) {
      res.push_back(words[i]);
    }
  }
  return res;
}

int getCost(string a, string b) {
  // cout << "getCost : "<< a << " "<< b;
  int wrongNumber = 0;
  for (int i = 0; i < (int)a.size(); i++) {
    if (a[i] != b[i]) wrongNumber++;
  }
  return wrongNumber;
}
int main() {
  cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);

// 50 50
// 문장의 모든 단어가 바뀌려면 반드시 다음단어로 넘어가기전에 단어가 바뀌어야한다.
// 현재 문자열의 위치 i 마지막에 찾은 단어까지의 최소 비용의 합 w
// 현재 문자얼의 위치가 i 인데 마지막에 찾은 단어비용이 -1 이라면 해석안됨
// 단어의 종류가 일치한 단어를 찾았을떄, 그 단어로 바꾸는 비용을 최소화하는 방법은?
// dp[i] =min(dp[i- i로 끝나는 단어로 찾은단어의길이]+ 찾은 단어의길이 비용 ,)
// 단어 찾는 방법? 알파벳 개수 비교? 2<<26으로 ㄱ?

for (int j = 0; j < maxN;j++) {
  dp[j] = INT32_MAX;
}


string sentence;
cin >> sentence;
int N;
cin >> N;
for (int j = 0; j < N;j++) {
  string word;
  cin >> word;
  words.push_back(word);
  sort(word.begin(), word.end());
  sortedWords.push_back(word);
}

dp[0] = 0;
for (int i = 1; i < sentence.size()+1;i++) {
  for (int j = 1; j <= i;j++) {
    string tmp = sentence.substr(j-1, i - j + 1);
    vector<string> fw = findWords(tmp);
    // cout << fw.size() << endl;
    if (fw.size() == 0) continue;
    for (string word : fw) {
      if (dp[i - word.size()] == INT32_MAX) continue;
      dp[i] = min(dp[i - word.size()] + getCost(word, tmp), dp[i]);
      }
    }
}

cout << (dp[sentence.size()] == INT32_MAX ? -1 : dp[sentence.size()]) << endl;

return 0;
}