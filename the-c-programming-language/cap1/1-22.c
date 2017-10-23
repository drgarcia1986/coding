#include <stdio.h>

#define MAXLINE 1000
#define MAXCOL 80

int _getline(char s[], int lim);
void fold(char in[], char out[], int len, int col);

int main() {
    int len;
    char line[MAXLINE], out[MAXLINE];

    while ((len = _getline(line, MAXLINE)) > 0) {
        fold(line, out, len, MAXCOL);
        printf("%s", out);
    }

    return 0;
}

void fold(char in[], char out[], int len, int col) {
    int i, lastspace, linepos;

    lastspace = -1;
    linepos = 0;
    for (i = 0; i < len && in[i] != '\n'; ++i) {
        out[i] = in[i];
        if (in[i] == ' ')
            lastspace = i;

        if (linepos == col) {
            out[lastspace] = '\n';
            linepos = 0;
        } else {
            ++linepos;
        }
    }
    out[i] = '\n';
    out[++i] = '\0';
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
