#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n, b;
    scanf("%d %d", &n, &b);

    int rest;
    string result = "";
    while (n > 0)
    {
        rest = n % b;
        n = n / b;

        if (rest < 10)
        {
            result = to_string(rest) + result;
        }
        else
        {
            result = (char)('A' + rest - 10) + result;
        }
    }

    cout << result << endl;
}