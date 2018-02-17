#include <stdio.h>
#include <string.h>

int strindex(char s[], char t[]);

int main() {
    printf("%d\n", strindex("hey could you help me?", "ou"));
    return 0;
}

int strindex(char s[], char t[]) {
    int i, j, k, tlen = strlen(t);

    for (i=strlen(s)-1; i >= 0; i--) {
        for (j=i, k=tlen-1; k >= 0 && s[j]==t[k]; j--, k--)
            ;
        if (k == -1)
            return i;
    }

    return -1;
}
