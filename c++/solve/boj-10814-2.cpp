#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int age;
    string name;
    vector<string> v[201];
    for (int i = 0; i < n; i++)
    {
        cin >> age >> name;
        v[age].push_back(name);
    }

    for (int i = 1; i <= 200; i++)
    {
        if (v[i].size() == 0)
            continue;

        for (int j = 0; j < v[i].size(); j++)
        {
            cout << i << " " << v[i][j] << "\n";
        }
    }
}