#include <stdio.h>

int getch();
void ungetch(int);

int main() {
    int c;

    ungetch('f');
    ungetch('o');

    while ((c = getch()) != '\n')
        putchar(c);
    return 0;
}

int buf = EOF;

int getch() {
    int c;

    if (buf == EOF)
        return getchar();

    c = buf;
    buf = EOF;
    return c;
}

void ungetch(int c) {
    if (buf != EOF)
        printf("ungetch: too many characters\n");
    else
        buf = c;
}
