#include <stdio.h>

#define MAXLEN 78

int main() {
    int c, i, j, idx;
    int ccount[MAXLEN];

    for (i = 0; i < MAXLEN; ++i)
        ccount[i] = 0;

    while ((c = getchar()) != EOF) {
        idx = c-'0';
        if (idx < MAXLEN)
            ++ccount[idx];
    }

    for (i = 0; i <= MAXLEN; ++i) {
        printf("%c | ", i+'0');
        for (j = 0; j < ccount[i]; ++j)
            putchar('*');
        putchar('\n');
    }
}
