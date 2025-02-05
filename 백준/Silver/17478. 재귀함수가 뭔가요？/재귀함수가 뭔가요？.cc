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

int N;
void f(int depth) {
  string s = "";
    for (int i = 0; i < N - depth; i++) {
      s += "____";
    }
    if (depth == 0) {
      cout << s + "\"재귀함수가 뭔가요?\"" << endl;
      cout << s + "\"재귀함수는 자기 자신을 호출하는 함수라네\"" << endl;
      cout << s + "라고 답변하였지." << endl;
      return;
  }
  cout <<s+"\"재귀함수가 뭔가요?\"" << endl;
  cout <<s+"\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어."<<endl;
  cout <<s+ "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지."<<endl;
  cout <<s+"그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"" << endl;
  f(depth - 1);
  cout << s + "라고 답변하였지." << endl;
  return;
}
int main() {
  cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
cin >> N;
cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << endl;
f(N);

return 0;
}