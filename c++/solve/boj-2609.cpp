#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n;
    cin >> m;

    int answer1, answer2;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            if (m % i == 0)
            {
                answer1 = i;
            }
        }
    }

    answer2 = n * m * answer1;

    cout << answer1 << "\n";
    cout << answer2 << "\n";

    // return 최대공약수 최소공배수
}