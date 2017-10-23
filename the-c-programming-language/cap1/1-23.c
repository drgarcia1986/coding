#include <stdio.h>

#define MAXLINE 1000
#define OUT 0
#define IN 1

int _getline(char s[], int lim);
void rcomments(char in[], char out[], int len);

int main() {
    int len;
    char line[MAXLINE], out[MAXLINE];

    while ((len = _getline(line, MAXLINE)) > 0)  {
        rcomments(line, out, len);
        printf("%s", out);
    }

    return 0;
}

void rcomments(char in[], char out[], int len) {
    int i, j, state, qstate;

    j = 0;
    state = OUT;
    qstate = OUT;
    for (i = 0; i <= len; ++i) {
        if (in[i] == '"' && state == OUT) {
            if (qstate == IN)
                qstate = OUT;
            else
                qstate = IN;

            out[j] = in[i];
            ++j;
        } else if (qstate == OUT) {
            if (in[i] == '/' && in[i+1] == '*')
                state = IN;
            else if (state == IN && in[i] == '/' && in[i-1] == '*')
                state = OUT;
            else if (state == OUT) {
                out[j] = in[i];
                ++j;
            }
        } else {
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
