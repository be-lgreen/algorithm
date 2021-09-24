#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    // 1 ~ 100 사이의 모든 소수 찾기
    int max = 100;

    vector<int> v;
    v.push_back(0);
    v.push_back(0);
    for (int i = 2; i <= max; i++)
    {
        v.push_back(i);
    }

    // 소수 찾기
    for (int i = 2; i < sqrt(max); i++)
    {
        if (v[i] == 0)
            continue;

        for (int j = 2 * i; j <= max; j += i)
        {
            v[j] = 0;
        }
    }

    // 찾은 소수를 출력
    for (int i = 1; i <= max; i++)
    {
        if (v[i] != 0)
        {
            cout << v[i] << ", ";
        }
    }
    cout << endl;
}