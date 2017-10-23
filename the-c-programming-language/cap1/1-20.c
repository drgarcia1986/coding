#include <stdio.h>
#define MAXLINE 1000
#define TABSTOP 4

void detab(char in[], char out[], int len, int tabstop);
int _getline(char s[], int lim);

int main() {
    int len;
    char line[MAXLINE], out[MAXLINE];

    while ((len = _getline(line, MAXLINE)) > 0) {
        detab(line, out, len, TABSTOP);
        printf("%s", out);
    }

    return 0;
}

void detab(char in[], char out[], int len, int tabstop) {
    int i, j, k;

    j = 0;
    for (i = 0; i < len; ++i) {
        if (in[i] != '\t') {
            out[j] = in[i];
            ++j;
        } else {
            for (k = j; k < j+tabstop; ++k)
                out[k] = ' ';
            j = j + tabstop;
        }
    }
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
