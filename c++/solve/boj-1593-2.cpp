// https://www.acmicpc.net/problem/1593
// 통과 코드

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int w_cnt, s_cnt;
string w, s;
int result;
bool is_alph_consist_same(unordered_map<char, int> &m1, unordered_map<char, int> &m2)
{
    unordered_map<char, int>::iterator iter;
    int key;
    int value;
    for (iter = m1.begin(); iter != m1.end(); iter++)
    {
        key = iter->first;
        value = iter->second;

        if (m2.find(key) != m2.end())
        { // exist
            if (m2[key] != value)
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1. 입력
    cin >> w_cnt >> s_cnt;
    cin >> w;
    cin >> s;

    // 2. 입력받은 w, s 문자열에 대해 w_cnt만큼 검사하면서 map에 저장
    // w_cnt = 4라면 0~3을 검사하면서 map[알파벳] = 개수 형태로 저장
    unordered_map<char, int> m;
    unordered_map<char, int> m2;

    for (int i = 0; i < w_cnt; i++)
    {
        if (m.find(w[i]) != m.end()) // exist
        {
            m[w[i]]++;
        }
        else
        { // non exist
            m[w[i]] = 1;
        }
    }

    for (int i = 0; i < w_cnt; i++)
    {
        if (m2.find(s[i]) != m2.end()) // exist
        {
            m2[s[i]]++;
        }
        else
        { // non exist
            m2[s[i]] = 1;
        }
    }

    // w, s에 대해 특정 구간안에 포함된 알파벳 구성이 같은지 검사
    if (is_alph_consist_same(m, m2))
        result += 1;

    // 3. 투포인터
    // window를 한칸씩 이동하면서 (0~3 / 1~4 / 2~5) 해당 구간에 포함된 알파벳별 개수를 검사.
    for (int i = w_cnt; i < s.size(); i++)
    {
        if (m2.find(s[i]) != m2.end()) // exist
        {
            m2[s[i]]++;
        }
        else
        { // non exist
            m2[s[i]] = 1;
        }

        m2[s[i - w_cnt]]--;
        //w, s에 대해 특정 구간안에 포함된 알파벳 구성이 같은지 검사
        if (is_alph_consist_same(m, m2))
            result++;
    }

    cout << result;
}