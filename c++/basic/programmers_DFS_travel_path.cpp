#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(string str1, string str2){
    if(str1.compare(str2) < 0){
        return true;
    }else
        return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    //tickets = 10000 -1 ?
    map<string, int> m;
    vector<vector<string>> v(10000, vector<string>());
    int itr = 0;
    for(int i=0; i<tickets.size(); i++){
        if(m.count(tickets[i][0]) == 0){
            m[tickets[i][0]] = itr;
            v[itr].push_back(tickets[i][1]);
            sort(v[itr].begin(), v[itr].end(), compare);
            itr += 1;
        }else{
            int idx = m[tickets[i][0]];
            v[idx].push_back(tickets[i][1]);
            sort(v[idx].begin(), v[idx].end(), compare);
        }
    }

    vector<string> answer;
    string key = "ICN";
    answer.push_back(key);
    int l=0;
    while(l <= tickets.size()){
        if(v[m[key]].size() >= 1){
            string new_key = v[m[key]][0];
            answer.push_back(new_key);
            v[m[key]].erase(v[m[key]].begin());
            key = new_key;
        }

        l++;

    }

    return answer;
}