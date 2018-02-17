#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAXLINE 1000

int main() {
    double sum, atof(char []);
    char line[MAXLINE];
    int _getline(char line[], int max);

    sum = 0;
    while (_getline(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atof(line));
    return 0;
}

double atof(char s[]) {
    double val, power, exp;
    int i, sign, esign;

    for (i=0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    if (tolower(s[i]) == 'e')
        i++;
    esign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (exp = 0; isdigit(s[i]); i++)
        exp = 10.0 * exp + (s[i] - '0');

    if (esign == 1)
        return (sign * (val / power)) * pow(10, exp);
    return (sign * (val / power)) / pow(10, exp);
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
