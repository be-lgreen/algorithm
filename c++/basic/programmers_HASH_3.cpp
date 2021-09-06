#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {

    map<string, int> m;
    string type;
    for(int i=0; i<clothes.size(); i++){
        type = clothes[i][1];
        if(m.count(type) == 0){
            m[type] = 1;
        }else{
            m[type] += 1;
        }
    }

    vector<int> mm;
    for(auto i=m.begin(); i!=m.end(); i++){
        mm.push_back((*i).second);
    }

    int n = m.size();
    int answer = 0;
    for(int i=1; i< (1 << n); i++){
        int sum = 1;
        for(int j=0; j<n; j++){
            if(i & (1 << j)){
                sum *= mm[j];
            }
        }
        answer += sum;
    }
    return answer;
}