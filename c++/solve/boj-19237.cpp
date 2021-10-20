#include <stdio.h>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

// 1, 2, 3, 4는 각각 위, 아래, 왼쪽, 오른쪽을 의미한다.
int dirx[5] = {0, -1, 1, 0, 0};
int diry[5] = {0, 0, 0, -1, 1};
int timee;
int n, m, k;
int die_shark;

vector<int> move_shark(int shark_num, int sharkx, int sharky, vector<int> &cur_dir_arr, const vector<vector<vector<int> > > &dir_arr, vector<vector<pair<int, int> > > &check, vector<vector<int> > &sharks)
{
    int resultx = -1, resulty = -1, resultdir = -1;

    // dir_arr i: 상어번호, j: 현재 바라보는 방향, k: 현재 바라보고 있는 방향에서의 우선순위
    int new_dir;
    int cur_dir = cur_dir_arr[shark_num];
    int newx, newy;

    for (int i = 0; i < 4; i++)
    {
        new_dir = dir_arr[shark_num][cur_dir][i];

        newx = sharkx + dirx[new_dir];
        newy = sharky + diry[new_dir];

        if (newx < 0 || newy < 0 || newx > n - 1 || newy > n - 1)
        {
            continue;
        }

        if (check[newx][newy].first != 0)
        {
            if (abs(check[newx][newy].second - check[sharkx][sharky].second) >= k)
            {
                check[newx][newy].first = 0;
                check[newx][newy].second = 0;
            }
        }

        if (check[newx][newy].first == 0)
        {
            resultx = newx;
            resulty = newy;
            resultdir = new_dir;

            break;
        }
    }

    if (resultx == -1)
    {
        for (int i = 0; i < 4; i++)
        {
            new_dir = dir_arr[shark_num][cur_dir][i];

            newx = sharkx + dirx[new_dir];
            newy = sharky + diry[new_dir];

            if (newx < 0 || newy < 0 || newx > n - 1 || newy > n - 1)
                continue;

            if (check[newx][newy].first == shark_num)
            {
                resultx = newx;
                resulty = newy;
                resultdir = new_dir;

                break;
            }
        }
    }

    vector<int> result;
    result.push_back(shark_num);
    result.push_back(resultx);
    result.push_back(resulty);
    result.push_back(resultdir);

    return result;
}

bool compare(vector<int> v1, vector<int> v2)
{
    if (v1[0] < v2[0])
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);

    int temp;
    vector<vector<int> > sharks;
    vector<int> v;
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);
    sharks.push_back(v);
    v.clear();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &temp);
            if (temp != 0)
            {
                v.push_back(temp);
                v.push_back(i);
                v.push_back(j);

                sharks.push_back(v);
                v.clear();
            }
        }
    }

    sort(sharks.begin(), sharks.end(), compare);

    vector<int> cur_dir(m + 1, 0);
    for (int i = 1; i < m + 1; i++)
    {
        scanf("%d", &cur_dir[i]);
    }

    vector<vector<vector<int> > > dir_arr(m + 1, vector<vector<int> >(5, vector<int>(4, 0)));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j < 5; j++)
        {
            scanf("%d %d %d %d", &dir_arr[i][j][0], &dir_arr[i][j][1], &dir_arr[i][j][2], &dir_arr[i][j][3]);
        }
    }

    /* ----------------------- */
    timee = 0;
    vector<vector<pair<int, int> > > check(n, vector<pair<int, int> >(n, make_pair(0, 0)));
    for (int i = 1; i < sharks.size(); i++)
    {
        check[sharks[i][1]][sharks[i][2]].first = i;      // i번호 상어의 냄새를
        check[sharks[i][1]][sharks[i][2]].second = timee; // 0분에 뿌림
    }

    int shark_numm;
    int resultx;
    int resulty;
    int resultdir;
    while (1)
    {
        timee++;

        vector<vector<int> > results;

        for (int i = 1; i < sharks.size(); i++)
        {
            if (sharks[i][1] == -1 && sharks[i][2] == -1)
                continue;

            vector<int> result = move_shark(i, sharks[i][1], sharks[i][2], cur_dir, dir_arr, check, sharks);
            results.push_back(result);
        }

        for (int i = 0; i < results.size(); i++)
        {
            shark_numm = results[i][0];
            resultx = results[i][1];
            resulty = results[i][2];
            resultdir = results[i][3];

            if (resultx == -1)
                continue;

            if (check[resultx][resulty].first == 0 || check[resultx][resulty].first == shark_numm) // check point1) 뒤에 조건문 안써서 틀림.ㅠ
            {
                check[resultx][resulty].first = shark_numm;
                check[resultx][resulty].second = timee;

                sharks[shark_numm][1] = resultx;
                sharks[shark_numm][2] = resulty;
                cur_dir[shark_numm] = resultdir;
            }
            else if (check[resultx][resulty].first != 0)
            {
                sharks[shark_numm][1] = -1;
                sharks[shark_numm][2] = -1;
                die_shark += 1;
            }
        }

        if (abs(m - die_shark) == 1)
        {
            break;
        }

        if (timee == 1001)
        {
            break;
        }
    }

    if (timee == 1001)
    {
        printf("%d", -1);
    }
    else
    {
        printf("%d", timee);
    }
}