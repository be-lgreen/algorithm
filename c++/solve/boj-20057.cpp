#include <stdio.h>
#include <vector>
#include <utility>

using namespace std;
vector<vector<int> > index_order;
int n;

/*
00 01 02 03 04
10 11 12 13 14
20 21 22 23 24
30 31 32 33 34
40 41 42 43 44

*/

int percentage_index[10] = {1, 1, 2, 2, 7, 7, 10, 10, 5, 0};
int move_percentage[4][10][2] = {
    {{-1, 1}, {1, 1}, {-2, 0}, {2, 0}, {-1, 0}, {1, 0}, {-1, -1}, {1, -1}, {0, -2}, {0, -1}}, // 왼쪽
    {{-1, -1}, {-1, 1}, {0, -2}, {0, 2}, {0, -1}, {0, 1}, {1, -1}, {1, 1}, {2, 0}, {1, 0}},   // 아래
    {{-1, -1}, {1, -1}, {-2, 0}, {2, 0}, {-1, 0}, {1, 0}, {-1, 1}, {1, 1}, {0, 2}, {0, 1}},   // 오른쪽
    {{1, -1}, {1, 1}, {0, -2}, {0, 2}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {-2, 0}, {-1, 0}}  // 위쪽
};
// direction, percentage_index, pair

void make_index_order(int x, int y)
{
    int move_cnt = 0;
    int move_amount = 1;
    int to_plus_move_amount = 0;
    int dir = 0;

    int dirx[4] = {0, 1, 0, -1}; // 왼쪽 아래 오른쪽 위쪽
    int diry[4] = {-1, 0, 1, 0};

    int newx = x;
    int newy = y;

    while (1)
    {
        newx = newx + dirx[dir];
        newy = newy + diry[dir];
        move_cnt++;

        vector<int> temp;
        temp.push_back(newx);
        temp.push_back(newy);
        temp.push_back(dir);
        index_order.push_back(temp);

        if (move_cnt == move_amount)
        {
            to_plus_move_amount++;
            move_cnt = 0;
            dir = (dir + 1) % 4;
        }

        if (to_plus_move_amount == 2)
        {
            to_plus_move_amount = 0;
            move_amount++;
        }

        if (newy < 0)
        {
            break;
        }
    }
}

int main()
{
    int outbound_sand_amount = 0;

    scanf("%d", &n);

    vector<vector<int> > arr(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    make_index_order((n - 1) / 2, (n - 1) / 2);

    int x, y, dir;
    int newx, newy;
    int spread_amount_total, spread_amount;
    for (int i = 0; i < index_order.size(); i++)
    {
        spread_amount_total = 0;
        x = index_order[i][0];
        y = index_order[i][1];
        dir = index_order[i][2];

        for (int j = 0; j < 9; j++)
        {
            newx = x + move_percentage[dir][j][0];
            newy = y + move_percentage[dir][j][1];
            spread_amount = (arr[x][y] * percentage_index[j] / 100);
            if (newx < 0 || newy < 0 || newx > n - 1 || newy > n - 1)
            {
                outbound_sand_amount += spread_amount;
            }
            else
            {
                arr[newx][newy] += spread_amount;
            }
            spread_amount_total += spread_amount;
        }

        newx = x + move_percentage[dir][9][0];
        newy = y + move_percentage[dir][9][1];
        if (newx < 0 || newy < 0 || newx > n - 1 || newy > n - 1)
        {
            outbound_sand_amount += (arr[x][y] - spread_amount_total);
        }
        else
        {
            arr[newx][newy] += (arr[x][y] - spread_amount_total);
        }
        arr[x][y] = 0;
    }

    printf("%d", outbound_sand_amount);
}