#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n;
    cin >> k;

    int cnt = 0;
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        if (cnt == k)
            break;
        if (n % i == 0)
        {
            cnt += 1;
            answer = i;
        }
    }

    if (cnt == k)
        cout << answer;
    else if (cnt < k)
        cout << "0";
}