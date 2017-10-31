#include <stdio.h>
#include <ctype.h>

void expand(char s1[], char s2[]);

int main() {
    char s[1000];

    expand("Numbers --> 0-9", s);
    printf("%s\n", s);

    expand("Letters --> a-z", s);
    printf("%s\n", s);

    expand("LETTERS --> A-Z", s);
    printf("%s\n", s);
}

void expand(char s1[], char s2[]) {
    int i, j = 0, k;

    for (i=0; s1[i] != '\0'; i++) {
        if ((isalpha(s1[i]) || isdigit(s1[i])) && s1[i+1] == '-') {
            for (k = s1[i]-'0'; k <= s1[i+2]-'0';k++)
                s2[j++] = k + '0';
            i += 2;
        } else
            s2[j++] = s1[i];
    }
    s2[j] = '\0';
}
