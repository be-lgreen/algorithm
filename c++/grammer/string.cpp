#include <iostream>
#include <string>

using namespace std;

// string정리) - https://aonee.tistory.com/73
// 참고) C++11에 string을 int로 변환하기 위한 std::stoi()가 추가

void string_to_int()
{
    string int_val = "123";
    string double_val = "12.3456";

    int i = stoi(int_val);
    double d = stod(double_val);

    cout << i << endl;
    cout << d << endl;
}

void int_to_string()
{
    int i = 1234;
    string s = to_string(i);

    cout << s << endl;
}

void int_to_char()
{
    int i = 3;
    char c = (char)(i + '0');

    cout << c << endl;
}

void char_to_int()
{
    char c = '3';
    int i = c - '0';

    cout << i << endl;
}

void string_to_char()
{
    string s = "hhihi";
    printf("%s", s.c_str()); // string to const char *
}

int main()
{
    string_to_int();
    int_to_string();

    char_to_int();
    int_to_char();

    string_to_char();
}