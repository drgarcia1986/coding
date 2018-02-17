#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

int getch();
void ungetch(int);
void ungets(char s[]);

int main() {
    int c;

    ungets("this is a test!\n");
    while ((c = getch()) != '\n')
        putchar(c);
    return 0;
}

char buf[BUFSIZE];
int bufp = 0;

int getch() {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void ungets(char s[]) {
    int i;

    for (i = strlen(s); i >= 0; i--)
        ungetch(s[i]);
}
