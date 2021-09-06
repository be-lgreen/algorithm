#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int main(void)
{

    priority_queue<pair<int, int>, vector<pair<int, int> >, less<pair<int, int> > > pq;
    pq.push(make_pair(2, 4));
    pq.push(make_pair(1, 2));
    pq.push(make_pair(100, 0));
    pq.push(make_pair(100, 100));

    while (!pq.empty())
    {
        cout << pq.top().first << ":" << pq.top().second << endl;
        pq.pop();
    }
    return 0;
}