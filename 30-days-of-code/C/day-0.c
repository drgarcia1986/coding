#include <stdio.h>

int main() {
    char in[105];

    scanf("%[^\n]", in);
    printf("Hello, World.\n");
    printf("%s\n", in);

    return 0;
}
