#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *arr, int n) {
    int stop = 0; int length = n;
    while (!stop) {
        stop = 1;
        for (int i = 0; i < length -1; i++) {
            if (arr[i] > arr[i+1]) {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                stop = 0;
            }
        }
        length--;
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

    bubbleSort(arr, n);

    for (int i=0; i<n; i++)
        printf("%d ", arr[i]);

    return 0;
}
