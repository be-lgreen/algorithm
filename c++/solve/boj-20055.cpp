#include <iostream>
#include <vector>
using namespace std;

/*
4 5
10 1 10 6 2 3 8 2

5 8
100 99 60 80 30 20 10 89 99 100

*/

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int in;
    vector<int> duration;
    vector<int> v;
    for (int i = 0; i < (2 * n); i++)
    {
        scanf("%d", &in);
        duration.push_back(in);
        v.push_back(0);
    }

    int step = 0;
    while (1)
    {
        step += 1;

        // 1.
        int temp = v[v.size() - 1];
        v.erase(v.end() - 1);
        v.insert(v.begin(), temp);
        v[n - 1] = 0; // check point1 )

        temp = duration[duration.size() - 1];
        duration.erase(duration.end() - 1);
        duration.insert(duration.begin(), temp);

        // printf("step1\n");
        // for (int i = 0; i < duration.size(); i++)
        // {
        //     printf("%d ", duration[i]);
        // }
        // printf("\n");
        // for (int i = 0; i < v.size(); i++)
        // {
        //     printf("%d ", v[i]);
        // }
        // printf("\n");
        // printf("\n");

        // 2.
        for (int i = n - 2; i >= 0; i--)
        {
            if (v[i] == 1 && v[i + 1] == 0 && duration[i + 1] >= 1)
            {
                v[i + 1] = 1;
                v[i] = 0;
                duration[i + 1] -= 1;
                if (duration[i + 1] == 0)
                {
                    k--;
                }
            }
        }
        v[n - 1] = 0;

        // 3.
        if (duration[0] > 0)
        {
            v[0] = 1;
            duration[0] -= 1;
            if (duration[0] == 0)
            {
                k--;
            }
        }
        // 4.
        if (k <= 0)
        {
            break;
        }
    }

    printf("%d", step);
}