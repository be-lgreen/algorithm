#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topologySort(vector<vector<int>> &graph){
    vector<int> answer;
    vector<int> in_degree(graph.size(), 0);

    int node;
    for(int i=1; i<graph.size(); i++){
        for(int j=0; j<graph[i].size(); j++) {
            node = graph[i][j];
            in_degree[node] += 1;
        }
    }

    queue<int> q;
    for(int i=1; i<graph.size(); i++){
        if(in_degree[i] == 0){
            q.push(i);
        }
    }

    int cur_node;
    for(int i=1; i<graph.size(); i++){
        cur_node = q.front();
        q.pop();
        answer.push_back(cur_node);

        for(int j=0; j<graph[cur_node].size(); j++){
            node = graph[cur_node][j];
            in_degree[node] -= 1;
            if(in_degree[node] == 0){
                q.push(node);
            }
        }
    }

    return answer;
}

void printSolution(vector<int> &v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){
    // adj list (1 ~ 7)
    vector<vector<int> > graph1{
            {},
            {2, 5},
            {3},
            {4},
            {6},
            {6},
            {7},
            {},
    };

    vector<vector<int> > graph2{
            {},
            {2,3,4},
            {5},
            {5,6},
            {},
            {7},
            {2},
            {},
    };



    vector<int> answer = topologySort(graph1);
    printSolution(answer);

    answer = topologySort(graph2);
    printSolution(answer);

    return 0;
}