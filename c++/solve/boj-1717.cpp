#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int arr[1000001];

int find(int n)
{
    if (arr[n] == n)
    {
        return n;
    }
    else
    {
        return arr[n] = find(arr[n]);
    }
}

void unionn(int a, int b)
{
    int p1 = find(a);
    int p2 = find(b);

    if (p1 != p2)
    {
        arr[p1] = p2;
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        arr[i] = i;
    }

    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 0)
        {
            unionn(b, c);
        }
        else if (a == 1)
        {
            if (find(b) == find(c))
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
}