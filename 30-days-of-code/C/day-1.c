#include <stdio.h>

int main() {
    int i = 4;
    double d = 4.0;
    char s[] = "Hacker Rank ";

    int out_i;
    double out_d;
    char out_s[105];

    scanf("%d\n", &out_i);
    scanf("%lf\n", &out_d);
    scanf("%[^\n]", out_s);

    printf("%d\n", i + out_i);
    printf("%.1f\n", d + out_d);
    printf("%s%s\n", s, out_s);

    return 0;
}
