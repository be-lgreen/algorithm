/*
 * 2020-09-14, 배달
 * 다익스트라
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    const int INF = 1000000000;
    vector<int> dis(N, 0);
    vector<bool> visit(N, false);
    vector<vector<int>> road_arr(N, vector<int>(N, INF));

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

    int a, b, c;
    for(int i=0; i<road.size(); i++){
        a = road[i][0] -1;
        b = road[i][1] -1;
        c = road[i][2];

        if(road_arr[a][b] == INF) {
            road_arr[a][b] = c;
            road_arr[b][a] = c;
        }else{
            if(c < road_arr[a][b]){
                road_arr[a][b] = c;
                road_arr[b][a] = c;
            }
        }

    }


    for(int i=0; i<N; i++){
        dis[i] = road_arr[0][i];
        if(dis[i] != INF){
            pq.push({dis[i], i});
        }
    }

    visit[0] = true;

    int index, value;
    while(!pq.empty()){
        value = pq.top().first;
        index = pq.top().second;
        pq.pop();
        visit[index] = true;

        if(value < dis[index])
            continue;
        for(int i=0; i<N; i++){
            if(visit[i])
                continue;
            if(value + road_arr[index][i] < dis[i]){
                dis[i] = value + road_arr[index][i];
                pq.push({dis[i], i});
            }
        }
    }

    for(int i=1; i<N; i++) {
        if (dis[i] <= K)
            answer++;
    }

    return answer + 1;
}

int main(){
    int answer = solution(5,{{1,2,1},{2,3,3},{5,2,2},{1,4,2},{5,3,1},{5,4,2}},3);
    cout << answer << endl;

    return 0;
}