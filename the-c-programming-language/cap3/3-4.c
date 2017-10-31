#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void itoa(int n, char s[]);
void reverse(char s[]);

int main() {
    char s[1000];

    itoa(-2147483648, s);
    printf("%s\n", s);

    itoa(2147483647, s);
    printf("%s\n", s);
}

void itoa(int n, char s[]) {
    int i=0, sign;
    if ((sign = n) < 0)
        n = -n;

    do {
        s[i++] = abs(n%10) + '0';  /* avoind negative numbers getting the absolute value */
    } while (n /= 10);  /* maybe get a negative value, so just check for non zero values */

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) {
    int i, j;
    char c;

    for (i=0, j=strlen(s)-1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}
