#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *arr, int begin, int end, int x) {
    if (begin > end)
        return 0;
    int base = begin + (end - begin) / 2;
    if (arr[base] == x)
        return 1;
    if (arr[base] > x)
        return binarySearch(arr, begin, base-1, x);
    return binarySearch(arr, base+1, end, x);
}

int main() {
    int x; int n; int *arr;
    scanf("%d", &x);
    scanf("%d", &n);

    arr = (int*) malloc((n + 1) * sizeof(int));
    for (int i = 0; i < n; i++) {
        int temp = 0;
        scanf("%d", &temp);
        arr[i] = temp;
    }

    int found = binarySearch(arr, 0, n-1, x);
    if (found) {
        printf("%d found in array", x);
    } else {
        printf("%d not found in array", x);
    }

    return 0;
}
