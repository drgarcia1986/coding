#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
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

    selectionSort(arr, n);

    for (int i=0; i<n; i++)
        printf("%d ", arr[i]);

    return 0;
}
