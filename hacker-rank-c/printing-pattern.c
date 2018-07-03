#include <stdio.h>

int min(int a, int b) {
    if (a < b)
        return a;
    return b;
}

int main() {
    int n, m, len;

    scanf("%d", &n);
    len = (n*2) - 1;
    for (int i=0; i < len; i++) {
        for (int j=0; j < len; j++) {
            // check for the min distance from the four sides
            m = min(i, j);
            m = min(m, len - i - 1);
            m = min(m, len - j - 1);
            printf("%d ", n - m);
        }
        printf("\n");
    }
    return 0;
}
