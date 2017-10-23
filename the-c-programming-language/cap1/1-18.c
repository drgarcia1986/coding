#include <stdio.h>

#define MAXLINE 1000

int _getline(char line[], int maxline);

int main() {
    int len, i, j;
    char line[MAXLINE];

    while ((len = _getline(line, MAXLINE)) > 0) {
        if (len > 1) {
            for (i = len-1; i >= 0; --i) {
                if (line[i] != ' ' && line[i] != '\n')
                    break;
            }
            for (j = 0; j <= i; ++j) {
                if (line[j] != '\t')
                    putchar(line[j]);
            }
            putchar('\n');
        }
    }
    return 0;
}

int _getline(char s[], int lim) {
    int c, i;

    for (i=0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}
