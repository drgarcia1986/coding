#include <stdio.h>


void calculate_the_maximum(int n, int k) {
    int max_and = 0, max_or = 0, max_xor = 0;
    int val_and, val_or, val_xor;

    for(int i = 1; i <= n; i++) {
        for(int j=i+1; j <= n; j++) {
            if ((val_and = (i & j)) < k) {
                if (val_and > max_and)
                    max_and = val_and;
            }
            if ((val_or = (i | j)) < k) {
                if (val_or > max_or)
                    max_or = val_or;
            }
            if ((val_xor = (i ^ j)) < k) {
                if (val_xor > max_xor)
                    max_xor = val_xor;
            }
        }
    }
    printf("%d\n%d\n%d", max_and, max_or, max_xor);
}

int main() {
    int n, k;

    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);

    return 0;
}
