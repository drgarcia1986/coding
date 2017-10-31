#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void itoa(int n, char s[], int m);
void reverse(char s[]);

int main() {
    char s[100];

    itoa(13, s, 5);
    printf("%s\n", s);
    return 0;
}

void itoa(int n, char s[], int m) {
    int i=0, sign;
    if ((sign = n) < 0)
        n = -n;

    do {
        s[i++] = abs(n%10) + '0';
    } while (n /= 10);

    if (sign < 0)
        s[i++] = '-';

    while (i < m)
        s[i++] = ' ';

    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) {
    int i, j;
    char c;

    for (i=0, j=strlen(s)-1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}
