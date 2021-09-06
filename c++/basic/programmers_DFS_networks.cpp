#include <string>
#include <vector>
#include <queue>

using namespace std;


int solution(int n, vector<vector<int>> computers) {
    vector<int> check(210,0);
    int answer = 0;


    for(int i=0; i<n; i++){
        if(check[i] == 0){
            answer += 1;
            queue<int> q;

            check[i] = 1;
            q.push(i);
            int start;
            while(!q.empty()){
                start = q.front();
                q.pop();

                for(int j=0; j<n; j++){
                    if(computers[start][j] == 1 && check[j] == 0) {
                        q.push(j);
                        check[j] = 1;
                    }
                }
            }
        }
    }

    return answer;
}