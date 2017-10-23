#include <stdio.h>

#define MAXLINE 1000
#define TRUE 1
#define FALSE 0
#define OPEN_CLOSE 0
#define ON_OFF 1

int _getline(char s[], int lim);
int check_unmatched_symbols(char in[], int len, char sopen, char sclose);
int check_on_off_symbols(char in[], int len, char sym);
int check_line(char in[], int len, char sopen, char sclose, int type, int lnro);

int main() {
    int len, lnro, col, ok;
    char line[MAXLINE];

    ok = TRUE;
    lnro = 0;
    while ((len = _getline(line, MAXLINE)) > 0)  {
        ++lnro;
        if (!check_line(line, len, '(', ')', OPEN_CLOSE, lnro))
            ok = FALSE;
        if (!check_line(line, len, '[', ']', OPEN_CLOSE, lnro))
            ok = FALSE;
        if (!check_line(line, len, '"', '"', ON_OFF, lnro))
            ok = FALSE;
    }
    if (!ok)
        return 1;
    return 0;
}

int check_line(char in[], int len, char sopen, char sclose, int type, int lnro) {
    int col;

    if (type == OPEN_CLOSE)
        col = check_unmatched_symbols(in, len, sopen, sclose);
    else
        col = check_on_off_symbols(in, len, sopen);

    if (col > 0) {
        printf("%d-%d: unmatched %c %c\n", lnro, col, sopen, sclose);
        return FALSE;
    }
    return TRUE;
}

int check_on_off_symbols(char in[], int len, char sym) {
    int i, col, state;

    col = 0;
    state = 1;
    for (i = 0; i < len; ++i) {
        if (in[i] == sym) {
            col = i;
            state *= -1;
        }
    }
    if (state < 1)
        return ++col;
    return 0;
}

int check_unmatched_symbols(char in[], int len, char sopen, char sclose) {
    int i, col, scount;

    col = scount = 0;
    for (i = 0; i < len; ++i) {
        if (in[i] == sopen) {
            if (scount == 0)
                col = i;
            ++scount;
        } else if (in[i] == sclose) {
            --scount;
            if (scount < 0) {
                col = i;
                break;
            }
        }
    }
    if (scount != 0)
        return ++col;
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
