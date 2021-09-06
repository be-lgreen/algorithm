#include <string>
#include <vector>
#include <map>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(pair<string, int> t1, pair<string, int> t2){
    if(t1.second > t2.second){
        return true;
    }else{
        return false;
    }
}

bool compare2(pair<int, int> t1, pair<int, int> t2){
    if(t1.first > t2.first){
        return true;
    }else if(t1.first == t2.first){
        if(t1.second < t2.second){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<pair<string, int> > aa;


    map<string, vector<pair<int, int> > > m;
    string key;

    for(int i=0; i<genres.size(); i++){
        key = genres[i];
        if(m.count(key) == 0){ // key not exist
            vector<pair<int, int> > v;
            v.push_back(make_pair(plays[i], i));
            m.insert(make_pair(key, v));
        }else{
            vector<pair<int, int> > v = m[key];
            v.push_back(make_pair(plays[i], i));
            sort(v.begin(), v.end(), compare2);
            m.find(key) -> second = v;
        }
    }

    for(auto i=m.begin(); i != m.end(); i++){
        vector<pair<int, int> > tv = i->second;
        int sum = 0;
        for(int j=0; j<tv.size(); j++){
            sum += tv[j].first;
        }
        aa.push_back(make_pair(i->first, sum));
    }
    sort(aa.begin(), aa.end(), compare);

    vector<int> answer;
    for(int i=0; i<aa.size(); i++){
        key = aa[i].first;
        vector<pair<int, int>> v = m[key];
        if(v.size() < 2){
            for(int j=0; j<v.size(); j++){
                answer.push_back(v[j].second);
            }
        }else{
            for(int j=0; j<2; j++){
                answer.push_back(v[j].second);
            }
        }
    }


    return answer;
}