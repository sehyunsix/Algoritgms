#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

map<char, int> m={
        {'B',1},
        {'S',2},
        {'G',3},
        {'P',4},
        {'D',5}

    };
bool compare(string a, string b){
    string e_a, e_b;
    // cout << a[0] << ' ' << m[a[0]] << ' ' << b[0] << ' '<< m[b[0]] << endl;
    // cout << a << ' ' << b << ' ';
    if((m[a[0]]<m[b[0]])){
      // cout << "true" << endl;
      return true;
    }
    else if(m[a[0]]>m[b[0]]){
      // cout << "false" << endl;
      return false;
    }
    else{
      // cout << a[0] << ' ' << b[0] << endl;
      e_a =a.erase(0,1);
      e_b= b.erase(0,1);
      // cout << e_a << ' ' << e_b << endl;
      // cout << a << ' ' << b << endl;
      if(stoi(e_a)>stoi(e_b)){
        // cout << "true" << endl;
        return true;
      }
      else if(stoi(e_a)<stoi(e_b)){
        // cout << "false" << endl;
        return false;
      }
      else{
        // cout << "true" << endl;
        return true;
      }
    }
}


int main(){
    int n;
    vector<string> v;
    vector<string> old;
    vector<string> err;
    cin >> n;
    v.resize(n);
    for (int i=0; i<n; i++){
        cin >> v[i];
    }


    old = v;
    sort(v.begin(),v.end(),compare);



    for (size_t i = 0; i < n; i++)
    {
      if(old[i] != v[i]){
        err.push_back(old[i]);
      }

    }
    if(err.size()==0){
      cout << "OK" << endl;
    }
    else{
      sort(err.begin() ,err.end(),compare);
      cout << "KO" << endl;

      cout << err[0] << ' ' << err[1] << endl;

        }


    return 0;

}