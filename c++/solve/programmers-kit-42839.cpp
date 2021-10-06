// 프로그래머스 고득점 kit
// 코딩테스트 연습 > 완전탐색 > 소수 찾기

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <set>
using namespace std;

int prime[9999999];
int answer = 0;
set<string> s;

bool is_prime(string numbers)
{
    int number = stoi(numbers);

    if (prime[number] == 0)
        return false;
    else
        return true;
}

void dfs(string numbers, string new_numbers)
{
    if (numbers.size() == new_numbers.size())
    {
        return;
    }

    char temp;
    for (int i = 0; i < numbers.size(); i++)
    {
        temp = numbers[i];
        if (new_numbers.size() == 0 && temp == '0')
            continue;

        if (temp == 'A')
            continue;

        numbers[i] = 'A';
        if (s.find(new_numbers + temp) == s.end())
        {
            s.insert(new_numbers + temp);
            if (is_prime(new_numbers + temp))
                answer += 1;
        }
        cout << new_numbers + temp << " ";
        dfs(numbers, new_numbers + temp);
        numbers[i] = temp;
    }
}

int solution(string numbers)
{
    string max_number_str = "";
    int max_number;

    vector<int> v(numbers.begin(), numbers.end());
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < v.size(); i++)
    {
        max_number_str += to_string(v[i] - '0');
    }
    max_number = stoi(max_number_str);

    //소수 만들기
    prime[0] = 0;
    prime[1] = 0;
    for (int i = 2; i <= max_number; i++)
    {
        prime[i] = i;
    }

    for (int i = 2; i <= sqrt(max_number); i++)
    {
        if (prime[i] == 0)
            continue;

        for (int j = i * 2; j <= max_number; j += i)
        {
            prime[j] = 0;
        }
    }

    //순열
    if (numbers.size() <= 1)
    {
        if (is_prime(numbers))
            answer += 1;
    }
    else
    {
        dfs(numbers, "");
    }

    return answer;
}