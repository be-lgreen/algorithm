#include <iostream>
#include <vector>
#include <stdio.h>
#include <utility>
using namespace std;

int main()
{
    int dirx[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
    int diry[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
    int copyx[4] = {-1, -1, 1, 1};
    int copyy[4] = {-1, 1, -1, 1};
    int n, m;
    int arr[52][52] = {0};

    scanf("%d %d", &n, &m);

    vector<pair<int, int> > cloud;
    cloud.push_back(make_pair(n, 1));
    cloud.push_back(make_pair(n, 2));
    cloud.push_back(make_pair(n - 1, 1));
    cloud.push_back(make_pair(n - 1, 2));

    int num;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d ", &arr[i][j]);
        }
    }

    int d, s;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d", &d, &s);
        //1. 2.
        while (s > n)
        {
            s = (s - n);
        }
        int x, y;
        int newx, newy;
        for (int i = 0; i < cloud.size(); i++)
        {
            x = cloud[i].first;
            y = cloud[i].second;
            newx = x + (dirx[d] * s);
            newy = y + (diry[d] * s);
            if (newx > n)
            {
                newx = newx - n;
            }
            else if (newx < 1)
            {
                newx = newx + n;
            }

            if (newy > n)
            {
                newy = newy - n;
            }
            else if (newy < 1)
            {
                newy = newy + n;
            }

            arr[newx][newy] += 1;
            cloud[i].first = newx;
            cloud[i].second = newy;
        }

        int cross_cnt;
        int check[52][52] = {0};
        for (int i = 0; i < cloud.size(); i++)
        {
            x = cloud[i].first;
            y = cloud[i].second;
            cross_cnt = 0;

            for (int j = 0; j < 4; j++)
            {
                newx = x + copyx[j];
                newy = y + copyy[j];
                if (newx > n | newx<1 | newy> n | newy < 1)
                    continue;

                if (arr[newx][newy] > 0)
                    cross_cnt += 1;
            }
            arr[x][y] += cross_cnt;
            check[x][y] = 1;
        }

        cloud.clear();
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (arr[i][j] >= 2 && check[i][j] == 0)
                {
                    arr[i][j] -= 2;
                    cloud.push_back(make_pair(i, j));
                }
            }
        }

        // debug

        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= n; j++)
        //     {
        //         printf("%d ", arr[i][j]);
        //     }
        //     printf("\n");
        // }

    } // for end

    int total_cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            total_cnt += arr[i][j];
        }
    }

    printf("%d\n", total_cnt);
}
