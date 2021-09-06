#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
    vector<int> v(10, 3);
    for (int i = 0; i < v.size(); i++)
    {
        printf("%d ", v[i]);
    }

    return 0;
}