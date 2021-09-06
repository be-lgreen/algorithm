#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void myprint(string title, vector<int> v)
{
    cout << "[" << title << "]" << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ' ';
    }
    cout << endl;
    cout << endl;
}

void crud()
{
    vector<int> v1;
    for (int i = 0; i < 5; i++)
    {
        v1.push_back(i);
    }

    // 2자리 삭제 (vector.erase)
    v1.erase(v1.begin() + 2);
    cout << "v1.size() " << v1.size() << endl;
    myprint("erase", v1);

    // 2자리에 10삽입 (vector.insert)
    v1.insert(v1.begin() + 2, 10);
    cout << "v1.size() " << v1.size() << endl;
    myprint("insert", v1);

    // 반복문에서 erase()사용
    for (int i = 0; i < v1.size();)
    { //
        if (v1[i] == 10 || v1[i] == 0)
        {
            v1.erase(v1.begin() + i);
        }
        else
        {
            i++;
        }
    }
    myprint("advanced_erase", v1);

    sort(v1.begin(), v1.end());
    myprint("sort", v1);

    sort(v1.begin(), v1.end(), greater<int>());
    myprint("sort2", v1);
}

void three_vector()
{
    vector<int> arr[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            arr[i][j].push_back(1);
            arr[i][j].push_back(2);
            arr[i][j].push_back(3);
            arr[i][j].push_back(4);
        }
    }

    sort(arr[0][0].begin(), arr[0][0].end(), greater<int>());
    for (int i = 0; i < arr[0][0].size(); i++)
    {
        cout << arr[0][0][i] << " ";
    }
}

void iter()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    vector<int>::iterator iter = v.begin();
    cout << *iter << endl;
    iter += 2;
    cout << *iter << endl;
    *iter = 100;
    cout << *iter << endl;
}

int main()
{
    //crud();
    three_vector();

    //iter();
}
