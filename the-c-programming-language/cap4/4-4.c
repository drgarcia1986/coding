#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop();
void topstack();
void duplicate_stack_top_item();
void clearstack();

int main() {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
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
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push(fmodf(pop(), op2));
            else
                printf("error: zero divisor\n");
            break;
        case '?':
            topstack();
            break;
        case '#':
            duplicate_stack_top_item();
            break;
        case '!':
            clearstack();
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
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

void topstack() {
    if (sp > 0)
        printf("%g\n", val[sp-1]);
    else
        printf("error: stack empty\n");
}

void duplicate_stack_top_item() {
    if (sp > 0)
        push(val[sp-1]);
    else
        printf("error: stack empty\n");
}

void clearstack() {
    sp = 0;
}

void swap_stack_top_items() {
    double item1 = pop();
    double item2 = pop();

    push(item1);
    push(item2);
}

int getch();
void ungetch(int);

int getop(char s[]) {
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c;

    i = 0;
    if (isdigit(c) || c == '-') {
        while (isdigit(s[++i] = c = getch()) || c == '-')
            ;
    }

    if (c == '.') {
        while (isdigit(s[++i] = c = getch()))
            ;
    }

    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

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
