#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a ,int b){
    string s_a = to_string(a);
    string s_b = to_string(b);
    // if(s_a.size() == s_b.size())
    //  {
    //     s_a > s_b;
    //   }
    
    return (s_a+s_b) >(s_b +s_a);
}

string solution(vector<int> numbers) {
    vector<string> s_list;
    
    sort(numbers.begin(), numbers.end() ,cmp);
    string answer ="";
    int idx =0;
   
    for(auto s : numbers){
        answer += to_string(s);
    }
     while(idx != answer.size()-1 && answer[idx] =='0' ){
         idx++;
     }
    string ans =answer.substr(idx);
    return ans;
}