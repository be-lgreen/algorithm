// 프로그래머스 고득점 kit
// https://programmers.co.kr/learn/courses/30/lessons/43165

#include <string>
#include <vector>

using namespace std;

int result = 0;
void dfs(vector<int> &numbers, int cur_sum, int target, int index)
{
    if (index == numbers.size())
    {
        if (cur_sum == target)
            result += 1;

        return;
    }

    dfs(numbers, cur_sum - numbers[index], target, index + 1);
    dfs(numbers, cur_sum + numbers[index], target, index + 1);
}

int solution(vector<int> numbers, int target)
{
    int answer = 0;

    dfs(numbers, 0, target, 0);

    answer = result;
    return answer;
}