#include <iostream>
#include <vector>
using namespace std;

int LIS2(vector<int> &v){
    vector<int> answer;
    answer.push_back(v[0]);

    for(int i=1; i<v.size(); i++){
        if(v[i] > answer.back()){
            answer.push_back(v[i]);
        }else{
            vector<int>::iterator iter = lower_bound(answer.begin(), answer.end(), v[i]);
            *iter = v[i];
        }
    }

    return answer.size();
}


int LIS1(vector<int> &v){
    vector<int> answer;
    answer.push_back(v[0]);

    for(int i=1; i<v.size(); i++){
        if(v[i] > answer.back()){
            answer.push_back(v[i]);
        }else{
            //find lower bound using binary search
            int left = 0;
            int right = answer.size() - 1;
            int mid;
            while(right - left > 0){
                mid = left + (right - left) / 2;
                if(answer[mid] >= v[i]){
                    right = mid;
                }else{
                    left = mid + 1;
                }
            }
            answer[left] = v[i];
        }
    }

    return answer.size();
}

int main(){
    vector<int> v1 = {1, 2, 3, 2, 3, 4, 9, 4, 5}; // answer : 5
    vector<int> v2 = {10, 20, 40, 25, 20, 50, 30, 70, 80}; // answer : 6

    cout << LIS1(v1) << endl;
    cout << LIS2(v1) << endl;

    cout << LIS1(v2) << endl;
    cout << LIS2(v2) << endl;
}