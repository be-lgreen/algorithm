// https://www.acmicpc.net/problem/1593
// 시간 초과 코드

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int w_cnt, s_cnt;
string w, s;
int result;

// substr(시작위치, 갯수);

bool string_include(string word)
{
    int n = word.size();
    bool check = true;
    for (int i = 0; i < s.size() - n; i++)
    {
        check = true;
        for (int j = 0; j < n; j++)
        {
            if (s[i + j] != word[j])
            {
                check = false;
                break;
            }
        }

        if (check)
            return true;
        // if (s.substr(i, n) == word)
        // {
        //     return true;
        // }
    }

    return false;
}

void get_permutaion(string &origin_s, string &new_s, int dest_len, int cur_len)
{
    if (cur_len == dest_len)
    {
        if (string_include(new_s))
        {
            result += 1;
        }
        return;
    }

    char cur_letter;
    for (int i = 0; i < origin_s.size(); i++)
    {
        if (origin_s[i] == '1')
            continue;

        //현재 단어를 선택
        cur_letter = origin_s[i];
        origin_s[i] = '1';
        new_s.push_back(cur_letter);
        get_permutaion(origin_s, new_s, dest_len, cur_len + 1);
        origin_s[i] = cur_letter;
        new_s.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> w_cnt >> s_cnt;
    cin >> w;
    cin >> s;

    string new_w = "";
    get_permutaion(w, new_w, w_cnt, 0);

    cout << result;
}