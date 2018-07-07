#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    int *arr = malloc(10 + sizeof(int));
    char s[1000];
    scanf("%[^\n]", s);

    for (int i=0; i < 10; i++)
        arr[i] = 0;

    for (int i=0; i < strlen(s); i++) {
        if (isdigit(s[i]))
            arr[s[i] - '0']++;
    }

    for (int i=0; i < 10; i++)
        printf("%d ", arr[i]);

    return 0;
}
