#include <stdio.h>

#define MAXLINE 1000

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main() {
    char s[MAXLINE], t[MAXLINE];
    int i = 0, c;

    while ((c = getchar()) != EOF)
        t[i++] = c;
    t[i] = '\0';

    escape(s, t);
    printf("%s\n\n", s);
    unescape(s, t);
    printf("%s\n", s);
}

void escape(char s[], char t[]) {
    int i, j = 0;

    for (i = 0; t[i] != '\0'; i++) {
        switch (t[i]) {
        case '\t':
            s[j] = '\\';
            s[++j] = 't';
            break;
        case '\n':
            s[j] = '\\';
            s[++j] = 'n';
            break;
        default:
            s[j] = t[i];
        }
        j++;
    }
    s[j] = '\0';
}

void unescape(char s[], char t[]) {
    int i, j = 0;

    for (i = 0; t[i] != '\0'; i++) {
        switch (t[i]) {
        case 't':
            if (i >= 0 && t[i-1] == '\\')
                s[j] = '\t';
            else
                s[j] = 't';
            break;
        case 'n':
            if (i >= 0 && t[i-1] == '\\')
                s[j] = '\n';
            else
                s[j] = 'n';
            break;
        case '\\':
            break;
        default:
            s[j] = t[i];
        }
        j++;
    }
    s[j] = '\0';
}
