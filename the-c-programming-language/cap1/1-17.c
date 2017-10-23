#include <stdio.h>

#define MAXLINE 1000
#define TARGET_LEN 80

int _getline(char line[], int maxline);

int main() {
    int len;
    char line[MAXLINE];

    while ((len = _getline(line, MAXLINE)) > 0)
        if (len > TARGET_LEN)
            printf("%2d: %s", len, line);
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
