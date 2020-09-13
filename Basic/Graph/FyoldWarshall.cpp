#include <iostream>
#include <vector>

using namespace std;

const int INF = 1000000000;
const vector <vector<int>> arr{
        {0,   2,   5, 1,   INF, INF},
        {2,   0,   3, 2,   INF, INF},
        {5,   3,   0, 3,   1,   5},
        {1,   2,   3, 0,   1,   INF},
        {INF, INF, 1, 1,   0,   2},
        {INF, INF, 5, INF, 2,   0}};

/*
 * 목적: 모든 정점에서 모든 정점까지의 최단거리
 * 특징: 음수 간선이 있어도 ok?
 * 시간복잡도:
 */
void FylodWarshall() {
    // 초기화
    vector <vector<int>> d(6, vector<int>(6, 0));
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            d[i][j] = arr[i][j];
        }
    }

    // k = 거쳐 가는 노드
    for (int k = 0; k < 6; k++) {
        // i = 출발 노드
        for (int i = 0; i < 6; i++) {
            // j = 도착 노드
            for (int j = 0; j < 6; j++) {
                if (d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];
            }
        }
    }

    // 출력
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++) {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


int main() {
    FylodWarshall();
    return 0;
}