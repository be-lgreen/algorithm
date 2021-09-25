#include <iostream>
#include <string>
using namespace std;

// n을 k진법으로 변환
string convert(int n, int k)
{
    string arr[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "F", "G", "H"};

    int rest;
    string result = "";

    while (n / k != 0)
    {
        rest = n % k;
        result = arr[rest] + result;
        n = n / k;
    }

    result = arr[n] + result;
    return result;
}

int main()
{
    cout << convert(16, 15) << endl; // 11
    cout << convert(15, 2) << endl;  // 1111
    cout << convert(16, 2) << endl;  // 10000
    cout << convert(32, 15) << endl; // 22

    cout << convert(65, 11) << endl; // 5A
    cout << convert(65, 2) << endl;  // 1000001
    cout << convert(65, 4) << endl;  // 1001
    cout << convert(65, 8) << endl;  // 101
}
