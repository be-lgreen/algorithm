#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(const vector<int> &v1, const vector<int> &v2)
{
    if (v1[0] < v2[0])
        return true;
    else if (v1[0] > v2[0])
        return false;
    else
    {
        if (v1[1] < v2[1])
            return true;
        else
            return false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int a;
    string b;
    vector<vector<int> > v; // index age
    vector<string> v2;      // name
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        vector<int> vv;
        vv.push_back(a);
        vv.push_back(i);
        v.push_back(vv);

        v2.push_back(b);
    }

    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < v.size(); i++)
    {
        int index = v[i][1];
        cout << v[i][0] << " " << v2[index] << "\n";
    }
}