// 신한은행 기출연습

#include <iostream>
#include <vector>
using namespace std;

void call_combination();
void combination(const vector<int> &v2, const int idx, vector<int> &result, int &cnt);

void call_combination(){
    /*
     * [중복 조합]
     * 공식 유도 : 칸막이를 치자
     * nHr = (n+r-1)Cr
     * 3H4 = (3+4-1)C4 = 6C4 =
     *
     * */

    int cnt = 0;
    vector<int> result;
    vector<int> v2;
    for(int i=0; i<3; i++){
        v2.push_back(i);
    }
    combination(v2, 0, result, cnt);
}

void combination(const vector<int> &v2, const int idx, vector<int> &result, int &cnt){
    if(result.size() == 4){
        cnt ++;
        cout << "cnt: " << cnt << endl;
        for(int i=0; i< result.size(); i++){
            cout << result[i] << " ";
        }
        cout << endl;
        return;
    }

    for(int i = idx; i<v2.size(); i++){
        result.push_back(v2[i]);
        combination(v2, i, result, cnt);
        result.pop_back();
    }
}


int main(){
    call_combination();
}