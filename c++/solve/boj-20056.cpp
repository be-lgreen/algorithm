// https://www.acmicpc.net/problem/20056
// 마법사 상어와 파이어볼

#include <stdio.h>
#include <vector>
#include <cmath>
#include <set>
#include <utility>
#include <iostream>
using namespace std;

int dirx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int diry[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int n, m, k;
// check point 5) 나누기 4를 하고있었는데, 틀린 구현이었다. 0 ~ n-1 구간안으로 x가 들어오도록 더하고 빼주는게 헷갈리지 않는다.
int adjust(int x)
{
    if (x < 0)
    {
        while (x < 0)
        {
            x += n;
        }
    }
    else if (x > 0)
    {
        while (x > n - 1)
        {
            x -= n;
        }
    }

    return x;
}

int main()
{

    scanf("%d %d %d", &n, &m, &k);

    vector<int> arr[51][51]; // 51
    vector<vector<int> > ball(m, vector<int>(5, 0));

    for (int i = 0; i < m; i++)
    {
        // ri, ci, mi, si, di
        scanf("%d %d %d %d %d", &ball[i][0], &ball[i][1], &ball[i][2], &ball[i][3], &ball[i][4]);
        // check point 4) 설계는 0 0 부터로 했는데 문제에서 주어지는 좌표는 1 1부터이다.
        ball[i][0] -= 1;
        ball[i][1] -= 1;
    }

    int dir, speed, massive;
    int x, y, newx, newy;
    for (int i = 0; i < k; i++)
    {
        set<pair<int, int> > sett;
        // check point 3) 마법을 k번  반복하며 ball 벡터길이가 달라질 수 있는데, j < n조건을  사용하고 있었다. 세그먼테이션폴트.
        for (int j = 0; j < ball.size(); j++)
        {
            x = ball[j][0];
            y = ball[j][1];
            speed = ball[j][3];
            dir = ball[j][4];

            newx = x + (dirx[dir] * speed);
            newy = y + (diry[dir] * speed);

            newx = adjust(newx);
            newy = adjust(newy);

            arr[newx][newy].push_back(j);
            sett.insert(make_pair(newx, newy));
        }

        set<pair<int, int> >::iterator iter;
        vector<vector<int> > newball;
        int ball_index;
        bool all_same_dir;
        int cur_dir;

        for (iter = sett.begin(); iter != sett.end(); iter++)
        {

            x = iter->first;
            y = iter->second;

            speed = 0;
            massive = 0;
            cur_dir = -1;
            all_same_dir = true;

            if (arr[x][y].size() == 0)
                continue;

            //check point 6) 문제를 조건 숙지 미숙으로 한칸에 파이어볼이 2개이상일때 1개일때 나눠서 처리해야하는 것을 몰랐다.
            if (arr[x][y].size() == 1)
            {
                ball_index = arr[x][y][0];
                vector<int> temp;
                temp.push_back(x);
                temp.push_back(y);
                temp.push_back(ball[ball_index][2]);
                temp.push_back(ball[ball_index][3]);
                temp.push_back(ball[ball_index][4]);

                newball.push_back(temp);
                arr[x][y].clear();
                continue;
            }

            for (int j = 0; j < arr[x][y].size(); j++)
            {
                ball_index = arr[x][y][j];
                massive += ball[ball_index][2];
                speed += ball[ball_index][3];
                // check point 2) 나머지가 같은지 다른지 비교해야하는데 숫자 자체를 비교하고 있어서 항상 false가 나오고 있었다.
                if (cur_dir == -1)
                {
                    if (ball[ball_index][4] % 2 == 0)
                    {
                        cur_dir = 0;
                    }
                    else
                    {
                        cur_dir = 1;
                    }
                }
                else
                {
                    if (cur_dir != (ball[ball_index][4] % 2))
                        all_same_dir = false;
                }
                // check point 2) end
            }
            massive = massive / 5;
            speed = speed / arr[x][y].size();

            if (massive != 0)
            {
                for (int p = 0; p < 8; p += 2)
                {
                    vector<int> temp;
                    temp.push_back(x);
                    temp.push_back(y);
                    temp.push_back(massive);
                    temp.push_back(speed);
                    if (!all_same_dir)
                    {
                        temp.push_back(p + 1);
                    }
                    else
                    {
                        temp.push_back(p);
                    }

                    newball.push_back(temp);
                }
            }

            arr[x][y].clear();
        }

        // check point 1) 2차원 벡터 copy
        for (int p = 0; p < ball.size(); p++)
        {
            ball[p].clear();
        }
        ball.clear();

        ball.assign(newball.size(), vector<int>(5));

        copy(newball.begin(), newball.end(), ball.begin());
    }

    int result = 0;
    for (int i = 0; i < ball.size(); i++)
    {
        result += ball[i][2];
    }

    printf("%d", result);
}