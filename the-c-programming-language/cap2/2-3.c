#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int htoi(char s[]);

int main() {
    printf("%d\n", htoi("19A"));
}

int htoi(char s[]) {
    int i, j=0, val=0;

    for (i=strlen(s)-1; i >= 0; --i) {
        if (isdigit(s[i]))
            val += (s[i] - '0') * pow(16, j);
        else if ((s[i] >= 'a' && s[i] <= 'f') || (s[i] >= 'A' && s[i] <= 'F'))
            val += (tolower(s[i]) - 'a' + 10) * pow(16, j);
        else
            return -1;
        ++j;
    }

    return val;
}
