#include <cstdio>
#include <queue>
using namespace std;

struct st
{
    int x, y;
};

struct custom_cmp
{
    bool operator()(st a, st b)
    { //x는 오름차순 y는 내림차순 -> 반대..? 읭//
        if (a.x < b.x)
        {
            return true;
        }
        else if (a.x == b.x)
        {
            if (a.y > b.y)
                return true;
            else
                return false;
        }
        else
        {
            return false;
        }
    }
};

void myprint(priority_queue<int> q)
{
    while (!q.empty())
    {
        printf("%d ", q.top());
        q.pop();
    }
    printf("\n");
}

void myprint2(priority_queue<int, vector<int>, greater<int> > q)
{
    while (!q.empty())
    {
        printf("%d ", q.top());
        q.pop();
    }
    printf("\n");
}

void myprint3(priority_queue<st, vector<st>, custom_cmp> q)
{
    while (!q.empty())
    {
        printf("(%d, %d) ", q.top().x, q.top().y);
        q.pop();
    }
    printf("\n");
}

// void myprint4(priority_queue<st, vector<st>, greater<st> > q)
// {
//     while (!q.empty())
//     {
//         printf("(%d, %d) ", q.top().x, q.top().y);
//         q.pop();
//     }
//     printf("\n");
// }

int main()
{
    // max heap
    priority_queue<int> q; // int, vector<int>, less<int>
    q.push(0);
    q.push(3);
    q.push(5);
    q.push(2);
    q.push(1);
    myprint(q);

    // min heap
    // priority_queue<자료형, 구현체, 비교 연산자>
    // 구현체는 보통 vector<자료형> 형태
    priority_queue<int, vector<int>, greater<int> > q2;
    q2.push(0);
    q2.push(3);
    q2.push(5);
    q2.push(2);
    q2.push(1);
    myprint2(q2);

    priority_queue<st, vector<st>, custom_cmp> q3;
    q3.push({4, 1});
    q3.push({1, 4});
    q3.push({2, 4});
    q3.push({1, 2});
    q3.push({4, 2});
    myprint3(q3);

    //    priority_queue<st, vector<st>, greater<st>> q4;
    //    q4.push({4,1});
    //    q4.push({1,4});
    //    q4.push({2,4});
    //    q4.push({1,2});
    //    q4.push({4,2});
    //    myprint4(q4);
}
