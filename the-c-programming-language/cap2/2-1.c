#include <stdio.h>
#include <limits.h>

int main() {
    printf("Max value of char: %d\n", CHAR_MAX);
    printf("Min value of char: %d\n", CHAR_MIN);
    printf("Max value of signed char: %d\n", SCHAR_MAX);
    printf("Min value of signed char: %d\n", SCHAR_MIN);
    printf("Max value of unsigned char: %u\n\n", UCHAR_MAX);

    printf("Max value of short: %d\n", SHRT_MAX);
    printf("Min value of short: %d\n", SHRT_MIN);
    printf("Max value of unsigned short: %u\n\n", USHRT_MAX);

    printf("Max value of int: %d\n", INT_MAX);
    printf("Min value of int: %d\n", INT_MIN);
    printf("Max value of unsigned int: %u\n\n", UINT_MAX);

    printf("Max value of long: %ld\n", LONG_MAX);
    printf("Min value of long: %ld\n", LONG_MIN);
    printf("Max value of unsigned long: %lu\n\n", ULONG_MAX);

    return 0;
}
