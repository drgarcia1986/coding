#include <stdio.h>

int main()  {
    char ch;
    char s[100], sen[100];

    scanf("%c", &ch);
    scanf("%s\n", s);
    scanf("%[^\n]", sen);

    printf("%c\n", ch);
    printf("%s\n", s);
    printf("%s", sen);

    return 0;
}
