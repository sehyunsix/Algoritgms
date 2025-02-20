#include <string>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

map<string , int> costTable;
map<string , string> inTime;
map<string , string> outTime;

int calCost(vector<int>& fees, int times ){
    if(times <= fees[0]) return fees[1];
    return fees[1] + ((times -fees[0]-1)/fees[2] +1)*fees[3];
}

int stringToMiniute(string times){
    int hour =stoi(times.substr(0,2));
    int miniute=stoi(times.substr(3,2));
    return hour*60 +miniute;
}

int findInTime(string number){
    if(inTime.find(number) != inTime.end()) 
        return stringToMiniute(inTime[number]);
    return 0;
}

int findOutTime(string number){
    if(outTime.find(number) != outTime.end()) 
        return stringToMiniute(outTime[number]);
    return 1439;
}



vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    for(auto record : records){
        string type= record.substr(11);
        string number = record.substr(6,4);
        string time = record.substr(0,5);
        if(type=="IN") {inTime[number] = time;}
        if(type=="OUT") {
            outTime[number] =time;
            costTable[number] +=findOutTime(number)-findInTime(number);
            inTime.erase(number);
        }         
    }
        
    for(auto p: inTime){
        string number = p.first;
        costTable[number] +=  1439 - findInTime(number);
    }
    
    vector<pair<string,int>> vec(costTable.begin(), costTable.end());
    sort(vec.begin(), vec.end());
    
    for(auto info : costTable){
        answer.push_back(calCost(fees,info.second));
    }
    
    return answer;
}