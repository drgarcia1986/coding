#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    int type, lastvar;
    double op2, val, var, var_a = 0, var_b = 0, var_c = 0, lastitem = 0;
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
        case '^':
            op2 = pop();
            push(pow(pop(), op2));
            break;
        case 's':
            push(sin(pop()));
            break;
        case 'e':
            push(exp(pop()));
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
        case '_':
            push(lastitem);
            break;
        case '=':
            var = pop();
            val = pop();
            if (lastvar == 'a')
                var_a = val;
            else if (lastvar == 'b')
                var_b = val;
            else if (lastvar == 'c')
                var_c = val;
            else
                printf("error: unknown variable %g, use a, b or c\n", var);
            push(val);
            break;
        case 'a':
            lastvar = 'a';
            push(var_a);
            break;
        case 'b':
            lastvar = 'b';
            push(var_b);
            break;
        case 'c':
            lastvar = 'c';
            push(var_c);
            break;
        case '\n':
            lastitem = pop();
            printf("\t%.8g\n", lastitem);
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
    if (!isdigit(c) && c != '.')
        return c;

    i = 0;
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch()))
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
