#include <stdio.h>
#define MAXLINE 1000
#define TABSTOP 4

void entab(char in[], char out[], int len, int tabstop);
int _getline(char s[], int lim);

int main() {
    int len;
    char line[MAXLINE], out[MAXLINE];

    while ((len = _getline(line, MAXLINE)) > 0) {
        entab(line, out, len, TABSTOP);
        printf("%s", out);
    }

    return 0;
}

void entab(char in[], char out[], int len, int tabstop) {
    int i, j, k, cspaces;

    cspaces = 0;
    j = 0;
    for (i = 0; i < len; ++i) {
        if (in[i] == ' ') {
            ++cspaces;
            if (cspaces == tabstop) {
                cspaces = 0;
                out[j] = '\t';
                ++j;
            }
        } else {
            for (k = 0; k < cspaces; ++k) {
                out[j] = ' ';
                ++j;
            }
            cspaces = 0;
            out[j] = in[i];
            ++j;
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
