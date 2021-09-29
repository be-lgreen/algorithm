#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

void my_print(int arr[][22], int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%02d ", arr[i][j]);
        }
        printf("\n");
    }
}

void initialize(int arr[][22], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }
}

void garvity(int arr[][22], int n)
{
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == -1)
                continue;
            for (int k = i + 1; k < n; k++)
            {
                if (arr[k][j] == -2)
                {
                    arr[k][j] = arr[k - 1][j];
                    arr[k - 1][j] = -2;
                }
                else
                {
                    break;
                }
            }
        }
    }
}

void rotate(int arr[][22], int n)
{
    int temp[22][22] = {0};
    copy(&arr[0][0], &arr[0][0] + 22 * 22, &temp[0][0]);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = temp[j][n - 1 - i];
        }
    }
}

int main()
{
    int score = 0;
    int n, m;
    int arr[22][22] = {0};
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    while (1)
    {
        // 가장  큰  블록 그룹 찾기
        int visit_check[22][22] = {0};
        int largest_block[22][22] = {0};
        int largest_block_rainbow_cnt = 0;
        int max_block_size = 0;

        queue<pair<int, int> > q;
        pair<int, int> front;
        int dirx[4] = {0, -1, 0, 1}; // 왼쪽  위  오른쪽 아래
        int diry[4] = {-1, 0, 1, 0};
        int newx, newy;
        int current_color;
        int current_block_size = 0;
        int current_block_rainbow_cnt = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visit_check[i][j] == -1 || arr[i][j] == 0 || arr[i][j] == -1 || arr[i][j] == -2)
                    continue;

                visit_check[i][j] = -1;

                // bfs
                q.push(make_pair(i, j));
                current_color = arr[i][j];
                current_block_size = 1;
                current_block_rainbow_cnt = 0;
                int dfs_visit_check[22][22] = {0};
                dfs_visit_check[i][j] = -1;

                while (!q.empty())
                {
                    front = q.front();
                    q.pop();

                    for (int k = 0; k < 4; k++)
                    {
                        newx = front.first + dirx[k];
                        newy = front.second + diry[k];

                        if (newx < 0 || newy < 0 || newx >= n || newy >= n)
                            continue;

                        if (dfs_visit_check[newx][newy] != 0) //check point 3)
                            continue;

                        if (arr[newx][newy] == current_color || arr[newx][newy] == 0)
                        {
                            dfs_visit_check[newx][newy] = -1;
                            if (arr[newx][newy] == current_color)
                            {
                                visit_check[newx][newy] = -1;
                            }
                            if (arr[newx][newy] == 0)
                            {
                                current_block_rainbow_cnt += 1;
                            }
                            q.push(make_pair(newx, newy));
                            current_block_size += 1;
                        }
                    }
                }

                // 가장 큰 블록인지 판별 후, 갱신
                if (current_block_size > max_block_size)
                {
                    //initialize(largest_block, n);
                    copy(&dfs_visit_check[0][0], &dfs_visit_check[0][0] + 22 * 22, &largest_block[0][0]);
                    max_block_size = current_block_size;
                    largest_block_rainbow_cnt = current_block_rainbow_cnt; //check point 1
                }
                else if (current_block_size == max_block_size)
                {
                    if (current_block_rainbow_cnt >= largest_block_rainbow_cnt) // check point 1 (처음에 >로 함.)
                    {
                        //initialize(largest_block, n);
                        copy(&dfs_visit_check[0][0], &dfs_visit_check[0][0] + 22 * 22, &largest_block[0][0]);
                        max_block_size = current_block_size;
                        largest_block_rainbow_cnt = current_block_rainbow_cnt; //check point 1
                    }
                }

            } // inner for end
        }     // outer for end

        //my_print(largest_block, n);

        if (max_block_size >= 2)
        {
            // 블록 제거
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (largest_block[i][j] == -1)
                    {
                        arr[i][j] = -2; // 제거
                    }
                }
            }

            score += (max_block_size * max_block_size);

            //중력 적용
            garvity(arr, n);

            // 90 회전
            rotate(arr, n);

            //중력 적용
            garvity(arr, n);
        }
        else
        {
            break;
        }
    }

    printf("%d", score);
}