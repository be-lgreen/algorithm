#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

set<int> s;
void dfs(vector<int> &v, string str, int max_count, int cur_count)
{

    if (cur_count == max_count)
    {
        s.insert(stoi(str));
        return;
    }

    int temp;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == -1)
            continue;

        temp = v[i];

        v[i] = -1;
        dfs(v, str + to_string(temp), max_count, cur_count + 1);
        v[i] = temp;
    }
}

int main()
{
    int n, k, temp;
    vector<int> v;

    cin >> n;
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }

    dfs(v, "", k, 0);
    cout << s.size() << "\n";
}