// 위상정렬

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n, m;
    int a, b;
    int top;
    queue<int> q;
    vector<int> answer;

    scanf("%d %d", &n, &m);
    vector<int> arr[n+1];
    vector<int> inDegree(n+1, 0);

    for(int i=1; i<=m; i++){
        scanf("%d %d", &a, &b);
        arr[a].push_back(b);
        inDegree[b] +=1;
    }


    for(int i=1; i<=n; i++){
        if(inDegree[i] == 0)
            q.push(i);
    }
    for(int i=1; i<=n; i++){
        if(q.empty()){
            cout << -1 << endl;
        }

        top = q.front();
        q.pop();
        answer.push_back(top);

        int index;
    for(int i=0; i<arr[top].size(); i++){
        index = arr[top][i];
        inDegree[index] -= 1;
        if(inDegree[index] == 0)
            q.push(index);
    }
}


    for(int i=0; i<answer.size(); i++){
        cout << answer[i] << " ";
    }
}