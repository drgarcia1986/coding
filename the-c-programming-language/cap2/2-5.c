#include <stdio.h>
#include <string.h>

int any(char s1[], char s2[]);

int main() {
    printf("%d", any("exec", "abc"));
}

int any(char s1[], char s2[]) {
    int i, j;

    for (i = 0; s1[i] != '\0'; i++) {
        for (j = 0; j < strlen(s2); j++)
            if (s1[i] == s2[j])
                return i;
    }
    return -1;
}
