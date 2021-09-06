#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > floydWarshall(vector<vector<int> > &v) {
    int n = v.size();
    vector<vector<int> > d(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            d[i][j] = v[i][j];
        }
    }

    // k = 거쳐 가는 노드
    for (int k = 0; k < n; k++) {
        // i = 출발 노드
        for (int i = 0; i < n; i++) {
            // j = 도착 노드
            for (int j = 0; j < n; j++) {
                if (d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];
            }
        }
    }

    return d;
}

void printSolution(vector<vector<int> > &v){
    int n = v.size();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


int main() {
    const int INF = 1000000000;
    vector<vector<int> > v1{
        {0,   2,   5, 1,   INF, INF},
        {2,   0,   3, 2,   INF, INF},
        {5,   3,   0, 3,   1,   5},
        {1,   2,   3, 0,   1,   INF},
        {INF, INF, 1, 1,   0,   2},
        {INF, INF, 5, INF, 2,   0}
    };

    vector<vector<int> > v2{
        {0,   5,  INF, 10},
        {INF,  0,  3,  INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };

    vector<vector<int> > answer = floydWarshall(v1);
    printSolution(answer);

    answer = floydWarshall(v2);
    printSolution(answer);

    return 0;
}