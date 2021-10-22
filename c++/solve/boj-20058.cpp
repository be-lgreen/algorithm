#include <stdio.h>
#include <vector>
#include <cmath>
#include <utility>
#include <queue>
using namespace std;

int board[65][65] = {0};
int N, Q, M;
int dirx[4] = {0, 1, 0, -1};
int diry[4] = {1, 0, -1, 0};
/*
00 01 02 03
10 11 12 13
20 21 22 23
30 31 32 33

30 20 10 00
31 21 11 01
32 22 12 02
33 23 13 03
*/
void rotate(int x, int y, int slice)
{
    vector<vector<int> > c_board(slice, vector<int>(slice, 0));
    for (int i = 0; i < slice; i++)
    {
        for (int j = 0; j < slice; j++)
        {
            c_board[j][slice - 1 - i] = board[i + x][j + y];
        }
    }

    for (int i = 0; i < slice; i++)
    {
        for (int j = 0; j < slice; j++)
        {
            board[i + x][j + y] = c_board[i][j];
        }
    }
}

void firestorm(int slice)
{
    for (int i = 0; i < M; i += slice)
    {
        for (int j = 0; j < M; j += slice)
        {
            rotate(i, j, slice);
        }
    }
}

void reduce_ice()
{
    vector<pair<int, int> > v;

    int newx, newy;
    int ice_cnt;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] <= 0)
                continue;

            ice_cnt = 0;
            for (int k = 0; k < 4; k++)
            {
                newx = i + dirx[k];
                newy = j + diry[k];

                if (newx < 0 || newy < 0 || newx > M - 1 || newy > M - 1)
                    continue;

                if (board[newx][newy] > 0)
                {
                    ice_cnt += 1;
                }
            }

            if (ice_cnt < 3)
            {
                v.push_back(make_pair(i, j));
            }
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        board[v[i].first][v[i].second] -= 1;
    }
}

int main()
{
    scanf("%d %d", &N, &Q);

    M = pow(2, N);
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }

    int L;
    for (int i = 0; i < Q; i++)
    {
        scanf("%d", &L);
        firestorm(pow(2, L));
        reduce_ice();
    }

    int total_ice = 0;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] < 0)
            {
                printf("debug\n");
            }

            total_ice += board[i][j];
        }
    }
    printf("%d\n", total_ice);

    bool check[65][65] = {false};
    queue<pair<int, int> > q;
    int max_ice_group = 0;
    int ice_cnt = 0;
    int x, y, newx, newy;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 0)
                continue;

            if (check[i][j])
                continue;

            q.push(make_pair(i, j));
            check[i][j] = true;
            ice_cnt = 1;
            while (!q.empty())
            {
                x = q.front().first;
                y = q.front().second;
                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    newx = x + dirx[k];
                    newy = y + diry[k];

                    if (newx < 0 || newy < 0 || newx > M - 1 || newy > M - 1)
                        continue;

                    if (board[newx][newy] == 0)
                        continue;

                    if (board[newx][newy] > 0 && check[newx][newy] == false) // check_point1) ||로 해둬서 틀렸다. 실수.
                    {
                        q.push(make_pair(newx, newy));
                        check[newx][newy] = true;
                        ice_cnt += 1;
                    }
                }
            }

            if (ice_cnt > max_ice_group)
                max_ice_group = ice_cnt;
        }
    }

    printf("%d", max_ice_group);
}