#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    int i=0;
    int j=0;
    int answer = n - lost.size();

    while(i < lost.size() && j < reserve.size()){
        if(abs(lost[i]-reserve[j]) <= 1){
            answer += 1;
            i++;
            j++;
        }else{
            if(lost[i] < reserve[j]){
                i++;
            }else{
                j++;
            }
        }
    }

    return answer;
}

int main(){
    vector<int> v1;
    vector<int> v2;
    vector<int> result;
    for(int i=1; i<=3; i++){
        v1.push_back(i);
        v2.push_back(i+1);
    }

    result.resize(v1.size() + v2.size());
    auto itr = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), result.begin());
    result.erase(itr, result.end());
    for(int i=0; i<result.size(); i++){
        cout << result[i] << endl;
    }

 //set_difference
 //set_union
 //set_intersection
}