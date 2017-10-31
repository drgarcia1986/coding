#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

int main() {
    char s[10];

    printf("NUM\tBASE\tOUT\n");

    itob(7562, s, 16);
    printf("%d\t%d\t%s\n", 7562, 16, s);

    itob(20, s, 8);
    printf("%d\t%d\t%s\n", 20, 8, s);

    itob(10, s, 2);
    printf("%d\t%d\t%s\n", 10, 2, s);

    return 0;
}

void itob(int n, char s[], int b) {
    int i=0, r;

    do {
        if ((r = n % b) < 10)
            s[i++] = r + '0';
        else
            s[i++] = (r - 10) + 'A';
    } while ((n /= b) >= 1);

    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) {
    int i, j;
    char c;

    for (i=0, j=strlen(s)-1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}
