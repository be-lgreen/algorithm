#include <vector>
#include <cmath>
#include <iostream>
#include <queue>
#include <utility>
#define INF 2000000000
using namespace std;

int dirx[4] = {-1, 0, 1, 0};
int diry[4] = {0, 1, 0, -1};
pair<int, int> get_next_passenger_index(int a, int b, int n, vector<vector<int> > &mapp)
{
    int min_path = INF;
    int min_path_index = -1;
    int resultx, resulty;

    vector<vector<int> > check_map(n + 1, vector<int>(n + 1, 0));

    queue<vector<int> > qv;
    vector<int> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(0);
    qv.push(v);
    check_map[a][b] = -1;

    int curx, cury, newx, newy;
    int curdist;
    while (!qv.empty())
    {
        // cout << "qv size(): " << qv.size() << "\n";

        curx = qv.front()[0];
        cury = qv.front()[1];
        curdist = qv.front()[2];
        // cout << "curx, cury, curdist: " << curx << " " << cury << " " << curdist << "\n";
        qv.pop();

        // cout << "curx cury: " << curx << " " << cury << "\n";

        if (min_path_index != -1 && min_path < curdist)
        {
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            newx = curx + dirx[i];
            newy = cury + diry[i];

            if (newx < 1 || newy < 1 || newx > n || newy > n)
                continue;

            if (check_map[newx][newy] == -1)
                continue;

            if (mapp[newx][newy] == 0)
            {
                v.clear();
                v.push_back(newx);
                v.push_back(newy);
                v.push_back(curdist + 1);
                qv.push(v);

                check_map[newx][newy] = -1;
            }
            else if (mapp[newx][newy] > 0) // found passenger
            {
                check_map[newx][newy] = -1;

                if (min_path_index == -1)
                {
                    min_path = curdist;
                    min_path_index = mapp[newx][newy];
                    resultx = newx;
                    resulty = newy;
                }
                else
                {
                    if (curdist < min_path)
                    {
                        min_path = curdist;
                        min_path_index = mapp[newx][newy];
                        resultx = newx;
                        resulty = newy;
                    }
                    else if (curdist == min_path)
                    {
                        if (newx < resultx)
                        {
                            min_path = curdist;
                            min_path_index = mapp[newx][newy];
                            resultx = newx;
                            resulty = newy;
                        }
                        else if (newx == resultx)
                        {
                            if (newy < resulty)
                            {
                                min_path = curdist;
                                min_path_index = mapp[newx][newy];
                                resultx = newx;
                                resulty = newy;
                            }
                        }
                    }
                }
            }
            if (qv.size() == 0)
            {
                break;
            }
        }
    }

    if (min_path == -1)
    {
        return make_pair(-1, -1);
    }
    else
    {
        mapp[resultx][resulty] = 0;
        return make_pair(min_path_index, min_path + 1);
    }
}

int go_destination(int startx, int starty, int destx, int desty, int n, const vector<vector<int> > &map)
{
    int min_path = 0;

    vector<vector<int> > check_map(n + 1, vector<int>(n + 1, 0));

    queue<vector<int> > qv;
    vector<int> v;
    v.push_back(startx);
    v.push_back(starty);
    v.push_back(0);
    qv.push(v);
    check_map[startx][starty] = -1;

    int curx, cury, newx, newy;
    int curdist;
    while (!qv.empty())
    {
        curx = qv.front()[0];
        cury = qv.front()[1];
        curdist = qv.front()[2];
        qv.pop();

        if (curx == destx && cury == desty)
        {
            min_path = curdist;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            newx = curx + dirx[i];
            newy = cury + diry[i];

            if (newx < 1 || newy < 1 || newx > n || newy > n)
                continue;

            if (check_map[newx][newy] == -1)
                continue;

            if (map[newx][newy] >= 0)
            {
                v.clear();
                v.push_back(newx);
                v.push_back(newy);
                v.push_back(curdist + 1);
                qv.push(v);

                check_map[newx][newy] = -1;
            }
        }
    }

    return min_path;
}

int main()
{
    int n, m, k, a, b, passenger_index;
    scanf("%d %d %d", &n, &m, &k);

    // map
    vector<vector<int> > map(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 1)
            {
                map[i][j] = -1;
            }
        }
    }

    // texi start position
    scanf("%d %d", &a, &b);

    // passenger start & dest position
    vector<vector<int> > passenger(m + 1, vector<int>(4, 0));
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d %d %d", &passenger[i][0], &passenger[i][1], &passenger[i][2], &passenger[i][3]);
        map[passenger[i][0]][passenger[i][1]] = i;
    }

    bool stop = false;
    for (int i = 1; i <= m; i++)
    {
        int oil_use1 = 0;
        int oil_use2 = 0;
        int next_passenger_index;
        pair<int, int> next_passenger = get_next_passenger_index(a, b, n, map);
        next_passenger_index = next_passenger.first;
        cout << "next_passenger: " << next_passenger_index << "\n";
        oil_use1 = next_passenger.second;

        if (next_passenger_index == -1)
        {
            stop = true;
            break;
        }

        k = k - oil_use1;
        if (k <= 0)
        {
            stop = true;
            break;
        }

        cout << "cehkc2\n";
        oil_use2 = go_destination(passenger[next_passenger_index][0], passenger[next_passenger_index][1],
                                  passenger[next_passenger_index][2], passenger[next_passenger_index][3],
                                  n, map);

        k = k - oil_use2;
        if (k < 0)
        {
            stop = true;
            break;
        }
        else
        {
            k = k + (oil_use2 * 2);
        }

        cout << "oil_use1 " << oil_use1 << "\n";
        cout << "oil_use2 " << oil_use2 << "\n";

        a = passenger[next_passenger_index][2];
        b = passenger[next_passenger_index][3];
    }

    if (stop)
    {
        printf("%d", -1);
    }
    else
    {
        printf("%d", k);
    }
}