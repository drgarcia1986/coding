#include <stdio.h>

#define MAXLEN 10

int main() {
    int c, i, j;
    int wcount[MAXLEN+1];

    for (i = 0; i < MAXLEN; ++i)
        wcount[i] = 0;

    i = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (i > MAXLEN)
                i = MAXLEN;
            ++wcount[i];
            i = 0;
        } else {
            ++i;
        }
    }

    for (i = 1; i <= MAXLEN; ++i) {
        printf("%2d | ", i);
        for (j = 0; j < wcount[i]; ++j)
            putchar('*');
        putchar('\n');
    }
}
