#include <stdio.h>

#define MAXLINE 1000

int _getline(char line[], int maxline);
int reverse(char s[], char out[], int len);

int main() {
    int len;
    char line[MAXLINE], out[MAXLINE];

    while ((len = _getline(line, MAXLINE)) > 0) {
        reverse(line, out, len);
        printf("%s", out);
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

int reverse(char in[], char out[], int len) {
    int i, j;
    j = 0;
    for (i = len-1; i >= 0; --i) {
        if (in[i] != '\n') {
            out[j] = in[i];
            ++j;
        }
    }
    out[j] = '\n';
    out[++j] = '\0';
    return len;
}
