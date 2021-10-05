#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> m;
    cin >> n;

    vector<int> prime;
    prime.push_back(0);
    prime.push_back(0);
    for (int i = 2; i <= n; i++)
    {
        prime.push_back(i);
    }

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (prime[i] == 0)
            continue;

        for (int j = i * 2; j <= n; j += i)
        {
            prime[j] = 0;
        }
    }

    int i = m;
    int answer1 = 0, answer2 = 0;
    for (int i = m; i <= n; i++)
    {
        if (prime[i] != 0)
        {
            if (answer1 == 0)
            {
                answer1 = prime[i];
            }

            answer2 += prime[i];
        }
    }

    if (answer1 == 0)
    {
        cout << -1;
    }
    else
    {
        cout << answer2 << "\n";
        cout << answer1 << "\n";
    }
}