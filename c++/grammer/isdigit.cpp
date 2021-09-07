#include <cctype>
#include <stdio.h>
// isdigit, islower, isupper

int main()
{
    printf("%d\n", isdigit('a')); // return 0 (false)
    printf("%d\n", isdigit('1')); // return 1 (true)

    printf("%d\n", islower('A')); // return 0 (false)
    printf("%d\n", islower('a')); // reutrn 1 (true)

    printf("%d\n", isupper('A')); // return 1 (true)
    printf("%d\n", isupper('a')); // return 0 (false)
}