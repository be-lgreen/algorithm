#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

void find_parent(int arr[], int n, vector<int> &v)
{
    if (arr[n] == n)
    {
        return;
    }
    else
    {
        v.push_back(arr[n]);
        find_parent(arr, arr[n], v);
    }
}

int main()
{
    int t, n, a, b;
    vector<int> results;
    scanf("%d", &t);

    //test case
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);

        //edge
        int arr[10020] = {0};
        for (int j = 1; j <= n - 1; j++)
        {
            arr[j] = j;
        }
        for (int j = 1; j <= n - 1; j++)
        {
            scanf("%d %d", &a, &b);
            arr[b] = a;
        }
        scanf("%d %d", &a, &b);

        vector<int> v1;
        v1.push_back(a);
        find_parent(arr, a, v1);

        vector<int> v2;
        v2.push_back(b);
        find_parent(arr, b, v2);

        int short_vector_size;
        if (v1.size() < v2.size())
        {
            short_vector_size = v1.size();
        }
        else
        {
            short_vector_size = v2.size();
        }

        int result;
        for (int j = 0; j < short_vector_size; j++)
        {
            if (v1[v1.size() - 1 - j] == v2[v2.size() - 1 - j])
            {
                result = v1[v1.size() - 1 - j];
            }
            else
            {
                break;
            }
        }

        results.push_back(result);
    }

    for (int i = 0; i < results.size(); i++)
    {
        cout << results[i] << endl;
    }
}