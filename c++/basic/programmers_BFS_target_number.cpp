// &numbers로 넘겨야지 훨씬빠르다. numbers로 넘기면 배열을 그때마다 복사하기때문에 시간이 꽤 차이나는듯
// 함수안에서 numbers배열을 변경하지 않을꺼면 const를 붙여서 수정못하게 막는것이 정석
// target같은 일반변수는 그냥 call by value로 넘기면 될듯 & 불필요

#include <vector>
#include <iostream>
using namespace std;

int answer = 0;

void bfs(const vector<int> &numbers, int idx, int cal, const int &target){
    if(idx == numbers.size()){
        if(cal == target)
            answer +=1;
        return;
    }

    bfs(numbers,idx+1, cal+numbers[idx],target);
    bfs(numbers, idx+1, cal-numbers[idx], target);

}

int solution(vector<int> numbers, int target) {
    bfs(numbers, 1, numbers[0], target);
    bfs(numbers, 1, -numbers[0], target);

    return answer;
}

int main(){
    cout << solution({1,1,1,1,1},3);
}