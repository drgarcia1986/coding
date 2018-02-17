#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXLINE 1000

int getop(char []);
void push(double);
double pop();
int _getline(char line[], int maxline);

char line[MAXLINE];
int bufline;

int main() {
    int type;
    double op2;
    char s[MAXOP];

    while (_getline(line, MAXLINE) != 0) {
        bufline = 0;
        while ((type = getop(s)) != '\0') {
            switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
            }
        }
    }
    return 0;
}

#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop() {
    if (sp > 0)
        return val[--sp];

    printf("error: stack empty\n");
    return 0.0;
}

int getop(char s[]) {
    int i, c;

    while ((s[0] = c = line[bufline++]) == ' ' || c == '\t')
        ;

    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;

    i = 0;
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = line[bufline++]))
            ;
    }

    if (c == '.') {
        while (isdigit(s[++i] = c = line[bufline++]))
            ;
    }

    s[i] = '\0';
    bufline--;

    return NUMBER;
}

int _getline(char s[], int lim) {
    int c, i;

    for (i=0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; i++)
        s[i] = c;

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';
    return i;
}
