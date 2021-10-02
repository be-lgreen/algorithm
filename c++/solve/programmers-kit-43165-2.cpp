// 프로그래머스 고득점 kit
// https://programmers.co.kr/learn/courses/30/lessons/43165

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<int> numbers, int target)
{
    int answer = 0;

    int n = numbers.size();
    int sum = 0;
    for (int i = 0; i < pow(2, n); i++)
    {
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                sum += numbers[j];
            }
            else
            {
                sum -= numbers[j];
            }
        }
        if (sum == target)
            answer++;
    }

    return answer;
}