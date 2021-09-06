#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

void myprint(vector<pair<int, int> > v)
{
    for (int i = 0; i < v.size(); i++)
    {
        printf("(%d, %d) ", v[i].first, v[i].second);
    }
    printf("\n\n");
}

bool compare(pair<int, int> a, pair<int, int> b)
{ //첫번째요소는 오름차순 두번째 요소는 내림차순
    if (a.first < b.first)
    { //왼쪽의 것이 더 작을 수 있도록
        return true;
    }
    else if (a.first == b.first)
    {
        if (a.second > b.second) //왼쪽의 것이 더 클 수 있도록
            return true;
        else
            return false;
    }
    else
    {
        return false;
    }
}
int main()
{
    vector<pair<int, int> > v;
    v.push_back(make_pair(4, 1));
    // v.push_back({1,4});
    v.push_back(make_pair(1, 4));
    v.push_back(make_pair(2, 4));
    v.push_back(make_pair(1, 2));
    v.push_back(make_pair(2, 4));
    printf("initial\n");
    myprint(v);

    // 2자리 삭제
    v.erase(v.begin() + 2);
    printf("erase\n");
    printf("v1.size(): %d\n", v.size());
    myprint(v);

    // 2자리에 10삽입
    v.insert(v.begin() + 2, make_pair(0, 1));
    printf("insert\n");
    printf("v1.size(): %d\n", v.size());
    myprint(v);

    //sort
    sort(v.begin(), v.end());
    printf("오름차순");
    myprint(v);

    sort(v.begin(), v.end(), greater<pair<int, int> >());
    printf("내림차순");
    myprint(v);

    //첫번째요소는 오름차순 두번째 요소는 내림차순
    sort(v.begin(), v.end(), compare);
    printf("첫번째요소는 오름차순 두번째 요소는 내림차순");
    myprint(v);
}
