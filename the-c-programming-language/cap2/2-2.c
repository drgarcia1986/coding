#include <stdio.h>
#define MAXLINE 1000

int main() {
    /*
        for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
            s[i] = c;
    */
    int i, c, lim=MAXLINE;
    char s[MAXLINE];

    for (i=0; i < lim-1; ++i) {
        if ((c = getchar()) != '\n') {
            if (c != EOF)
                s[i] = c;
            else
                break;
        } else {
            break;
        }
    }
    s[++i] = '\0';
    printf("%s\n", s);

    return 0;
}
