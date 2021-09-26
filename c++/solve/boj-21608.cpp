#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int arr[450][5] = {0};
int seat[22][22] = {0};
int n;

int dirx[4] = {-1, 0, 1, 0}; // 위 오른쪽  아래 왼쪽
int diry[4] = {0, 1, 0, -1};

pair<int, int> score(int a, int b, int c, int d)
{
    int max = 0;
    int result_x = n;
    int result_y = n;

    int score;
    int newx, newy;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (seat[i][j] != 0)
                continue;

            score = 0;
            //1.
            for (int z = 0; z < 4; z++)
            {
                newx = i + dirx[z];
                newy = j + diry[z];

                if (newx < 1 || newy < 1 || newx > n || newy > n)
                    continue;

                if (seat[newx][newy] != 0)
                { //1.
                    if (seat[newx][newy] == a || seat[newx][newy] == b || seat[newx][newy] == c || seat[newx][newy] == d)
                    {
                        score += 100;
                    }
                }
                else
                { //2
                    score += 10;
                }
            }

            //3
            if (score > max)
            {
                max = score;
                result_x = i;
                result_y = j;
            }
            else if (score == max)
            {
                if (i < result_x)
                {
                    result_x = i;
                    result_y = j;
                }
                else if (i == result_x)
                {
                    if (j < result_y)
                    {
                        result_x = i;
                        result_y = j;
                    }
                }
            }
        }
    } // end for

    return make_pair(result_x, result_y);
}

int main()
{
    scanf("%d", &n);

    // 자리 배치
    vector<pair<int, int> > v;
    int student_cnt = n * n;
    for (int i = 0; i < student_cnt; i++)
    {
        // 입출력.. 테스트 해보기
        // for (int j = 0; j < 5; j++)
        // {
        //     scanf("%d ", &arr[i][j]);
        // }
        scanf("%d %d %d %d %d", &arr[i][0], &arr[i][1], &arr[i][2], &arr[i][3], &arr[i][4]);

        if (i == 0)
        {
            seat[2][2] = arr[i][0];
            v.push_back(make_pair(2, 2));
        }
        else
        {
            pair<int, int> p = score(arr[i][1], arr[i][2], arr[i][3], arr[i][4]);
            seat[p.first][p.second] = arr[i][0];
            v.push_back(make_pair(p.first, p.second));
        }
    }

    // 점수 계산
    int x, y, newx, newy;
    int total_value = 0;
    int value = 0;
    for (int i = 0; i < student_cnt; i++)
    {
        x = v[i].first;
        y = v[i].second;
        value = 0;

        for (int z = 0; z < 4; z++)
        {
            newx = x + dirx[z];
            newy = y + diry[z];

            if (newx < 1 || newy < 1 || newx > n || newy > n)
                continue;

            for (int j = 1; j < 5; j++)
            {
                if (arr[i][j] == seat[newx][newy])
                    value += 1;
            }
        }

        if (value == 1)
        {
            total_value += 1;
        }
        else if (value == 2)
        {
            total_value += 10;
        }
        else if (value == 3)
        {
            total_value += 100;
        }
        else if (value == 4)
        {
            total_value += 1000;
        }
    }

    cout << total_value << endl;
}