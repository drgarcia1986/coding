#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    scanf("%d\n", &n);
    int *arr = (int*)malloc(n + sizeof(int));

    for (int i; i < n; i++) {
        int temp = 0;
        scanf("%d", &temp);
        *(arr + i) = temp;
    }

    int total = 0;
    for (int i; i < n; i++)
        total += arr[i];

    printf("%d\n", total);
    return 0;
}
