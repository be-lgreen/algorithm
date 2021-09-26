#include <iostream>
#include <vector>
#include <stdio.h>
#include <utility>
#include <stack>
using namespace std;

int arr[51][51] = {0};
int n, m;

vector<int> v;
int arr2[51][51] = {0};

int removed_circle[] = {0, 0, 0, 0}; // 폭발한 1번구슬, 2번구슬, 3번구슬 개수

int pre()
{
    int rotatex[] = {0, 1, 0, -1};
    int rotatey[] = {-1, 0, 1, 0};
    int arr2_cnt = 0;
    int x, y;

    x = (n + 1) / 2;
    y = (n + 1) / 2;
    v.push_back(arr[x][y]);
    arr2[x][y] = arr2_cnt++;

    int dir_cnt = 1;
    int dir_index = 0;
    while (true)
    {
        for (int z = 0; z < dir_cnt; z++)
        {
            x = x + rotatex[dir_index];
            y = y + rotatey[dir_index];
            if (x < 1 || y < 1)
            {
                return 0;
            }
            arr2[x][y] = arr2_cnt++;
            if (arr[x][y] != 0)
                v.push_back(arr[x][y]);
        }

        dir_index++;
        if (dir_index == 4)
            dir_index = 0;

        for (int z = 0; z < dir_cnt; z++)
        {
            x = x + rotatex[dir_index];
            y = y + rotatey[dir_index];
            if (x < 1 || y < 1)
            {
                return 0;
            }
            arr2[x][y] = arr2_cnt++;
            if (arr[x][y] != 0)
                v.push_back(arr[x][y]);
        }

        dir_index++;
        if (dir_index == 4)
            dir_index = 0;

        dir_cnt++;
    }
}

vector<int> explosion()
{

    vector<int> v2;
    v2.push_back(0);

    // check point 2)
    if (v.size() == 1)
        return v2;

    int cur_circle_number = v[1];
    int cur_circle_cnt = 1;
    for (int i = 2; i < v.size(); i++)
    {
        if (v[i] == cur_circle_number)
        {
            cur_circle_cnt++;
        }
        else
        {
            if (cur_circle_cnt < 4)
            {
                for (int j = 0; j < cur_circle_cnt; j++)
                {
                    v2.push_back(cur_circle_number);
                }
            }
            else
            {
                removed_circle[cur_circle_number] += cur_circle_cnt;
            }
            cur_circle_number = v[i];
            cur_circle_cnt = 1;
        }
    }

    if (cur_circle_cnt < 4)
    {
        for (int j = 0; j < cur_circle_cnt; j++)
        {
            v2.push_back(cur_circle_number);
        }
    }
    else
    {
        removed_circle[cur_circle_number] += cur_circle_cnt;
    }

    return v2;
}

int main()
{
    int dirx[] = {0, -1, 1, 0, 0}; // 위 아래 왼쪽 오른쪽 , 1 2 3 4
    int diry[] = {0, 0, 0, -1, 1};

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d ", &arr[i][j]);
        }
    }

    pre();

    int d, s;
    int centerx = (n + 1) / 2;
    int centery = (n + 1) / 2;
    int newx, newy;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &d, &s);

        // 구슬파괴 및 이동
        newx = centerx;
        newy = centery;
        stack<int> v_index;
        for (int j = 0; j < s; j++)
        {
            newx += dirx[d];
            newy += diry[d];
            v_index.push(arr2[newx][newy]);
        }

        while (!v_index.empty())
        {
            if (v.size() > v_index.top())
            {
                v.erase(v.begin() + v_index.top());
            }
            v_index.pop();
        }

        // 4개 이상 연속하는 구슬 제거
        while (1)
        {
            vector<int> new_v = explosion();
            if (new_v.size() == v.size())
            {
                break;
            }
            v.clear();
            v.assign(new_v.begin(), new_v.end());
        }

        // grouping  갯수 / 구슬 번호 순서로
        vector<int> v2;
        v2.push_back(0);

        if (v.size() > 1) // check point 2)
        {
            int cur_circle_number = v[1];
            int cur_circle_cnt = 1;
            for (int j = 2; j < v.size(); j++)
            {
                if (v[j] == cur_circle_number)
                {
                    cur_circle_cnt++;
                }
                else
                {
                    v2.push_back(cur_circle_cnt);
                    v2.push_back(cur_circle_number);
                    cur_circle_number = v[j];
                    cur_circle_cnt = 1;
                }
            }
            v2.push_back(cur_circle_cnt);
            v2.push_back(cur_circle_number);

            if (v2.size() > n * n)
            {
                v2.erase(v2.begin() + (n * n), v2.end());
            }
        }

        v.clear();
        v.assign(v2.begin(), v2.end());

    } // for end m

    //result
    printf("%d", removed_circle[1] + removed_circle[2] * 2 + removed_circle[3] * 3);
}
