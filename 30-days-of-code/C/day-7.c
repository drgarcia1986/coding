#include <stdio.h>
#include <stdlib.h>

int main() {
    int n; int *arr;
    scanf("%d", &n);

    arr = (int*) malloc((n + 1) * sizeof(int));

    for (int i = 0; i < n; i++) {
        int temp = 0;
        scanf("%d", &temp);
        *(arr + i) = temp;
    }

    for (int i = n-1; i >= 0; i--) {
        printf("%d ", *(arr + i));
    }

    return 0;
}
