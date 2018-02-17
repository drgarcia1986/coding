#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void itoa(int n, char s[]);

int main() {
    char s[1000];

    itoa(23, s);
    printf("%s\n", s);

    itoa(-358, s);
    printf("%s\n", s);
}

void reverse(char s[]) {
    int i, j;
    char c;

    for (i=0, j=strlen(s)-1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}

void itoa_rec(int n, char s[], int idx) {
    if (n / 10)
        itoa_rec(n / 10, s, idx+1);
    s[idx] = n % 10 + '0';
}

void itoa(int n, char s[]) {
    int sign, len;

    if ((sign = n) < 0)
        n = -n;

    itoa_rec(n, s, 0);

    len = strlen(s);
    if (sign < 0)
        s[len++] = '-';
    s[len] = '\0';

    reverse(s);
}
