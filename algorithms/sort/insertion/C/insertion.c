#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *arr, int n) {
    int j, actual;
    for (int i = 1; i < n; i++) {
        actual = arr[i];
        for (j = i; (j > 0) && (actual < arr[j-1]); j--)
            arr[j] = arr[j-1];
        arr[j] = actual;
    }
}

int main() {
    int n; int *arr;
    scanf("%d", &n);

    arr = (int*) malloc((n + 1) * sizeof(int));
    for (int i = 0; i < n; i++) {
        int temp = 0;
        scanf("%d", &temp);
        arr[i] = temp;
    }

    insertionSort(arr, n);

    for (int i=0; i<n; i++)
        printf("%d ", arr[i]);

    return 0;
}
