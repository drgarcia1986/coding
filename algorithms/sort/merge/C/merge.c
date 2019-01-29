#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge(int *arr, int begin, int middle, int end) {
    int i=begin; int j=middle+1; int k=0;
    int length = end-begin+1;
    int *temp;

    temp = (int*) malloc(length * sizeof(int));

    if (temp != NULL) {
        while (i <= middle && j <= end) {
            if (arr[i] < arr[j])
                temp[k++] = arr[i++];
            else
                temp[k++] = arr[j++];
        }

        while (i <= middle)
            temp[k++] = arr[i++];
        while (j <= end)
            temp[k++] = arr[j++];

        for (i=0, j=begin; i < length; i++, j++)
            arr[j] = temp[i];

        free(temp);
    }
}

void mergeSort(int *arr, int begin, int end) {
    if (begin < end) {
        int middle = floor((begin + end) / 2);
        mergeSort(arr, begin, middle);
        mergeSort(arr, middle+1, end);
        merge(arr, begin, middle, end);
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

    mergeSort(arr, 0, n-1);

    for (int i=0; i<n; i++)
        printf("%d ", arr[i]);

    return 0;
}
