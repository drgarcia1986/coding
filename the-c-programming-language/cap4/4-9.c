#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

int getch();
void ungetch(int);

int main() {
    int c;

    ungetch(EOF);
    while ((c = getch()) != EOF)
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
    else if (c != EOF)
        buf[bufp++] = c;
}
