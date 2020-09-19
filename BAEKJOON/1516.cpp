/* 위상정렬
 * 노드에 들어가는 간선이 0이 될때, 노드까지 간선의 길이가 최대가 이닐 수 있기 때문에 항상 최대값을 갱신하며 저장하고 있어야
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    string gs;
    string s;
    int n, a;
    scanf("%d", &n);

    vector<vector<int>> inp(n+1, vector<int>());
    vector<int> inDegree(n+1, 0);
    vector<int> time(n+1, 0);
    vector<int> max_time(n+1, 0);
    for(int i=1; i<=n; i++){
        int index =0;
        while(1){
            scanf("%d", &a);
            if(a == -1)
                break;

            if(index == 0){
                time[i] = a;
            }else {
                inp[a].push_back(i);
                inDegree[i] += 1;
            }
            index ++;
        }
    }

    queue<pair<int,int>> q;  // index, accumulate sum
    vector<int> answer(n+1, 0);
    for(int i=1; i<=n; i++){
        if(inDegree[i] == 0){
            q.push(make_pair(i,time[i]));
            answer[i] = time[i];
        }
    }

    int v;
    int t;
    for(int i=1; i<=n; i++){
        v = q.front().first;
        t = q.front().second;
        q.pop();

        int dest;
        int temp_max;
        for(int j=0; j<inp[v].size(); j++){
            dest = inp[v][j];
            inDegree[dest] -= 1;
            if(t > max_time[dest]) {
                max_time[dest] = t;
            }
            if(inDegree[dest] == 0) {
                q.push(make_pair(dest, max_time[dest] + time[dest]));
                answer[dest] = max_time[dest] + time[dest];
            }
        }
    }

    for(int i=1; i<=n; i++){
        cout << answer[i] << endl;
    }

}


/*
 *
5
10 -1
10 1 4 5 -1
4 1 -1
4 3 1 -1
3 3 -1
 */


/*4
1 4 3 2 -1
2 4 -1
1 4 -1
1 -1
4
3
2
1

 */