#include <stdio.h>

int max_of_four(int a, int b, int c, int d) {
    int current_max = a;

   if (current_max < b)
        current_max = b;
    if (current_max < c)
        current_max = c;
    if (current_max < d)
        current_max = d;

    return current_max;
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);

    return 0;
}
