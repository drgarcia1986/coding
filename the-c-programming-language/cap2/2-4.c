#include <stdio.h>
#include <string.h>

#define MAXSIZE 10
#define TRUE 1
#define FALSE 0

void squeeze(char s1[], char s2[]);

int main() {
    char s[MAXSIZE] = "exec";

    squeeze(s, "cx");
    printf("%s", s);
}

void squeeze(char s1[], char s2[]) {
    int i, j, k, found;

    for (i = j = 0; s1[i] != '\0'; i++) {
        found = FALSE;
        for (k = 0; s2[k] != '\0'; k++) {
            if (s1[i] == s2[k]) {
                found = TRUE;
                break;
            }
        }

        if (!found)
            s1[j++] = s1[i];
    }
    s1[j] = '\0';
}
