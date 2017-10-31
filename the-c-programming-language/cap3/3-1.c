#include <stdio.h>

int binsearch(int x, int v[], int n);

int main() {
    int n = 5, i;
    int v[n];

    for (i = 0; i < n; i++)
        v[i] = i * 10;
    v[++i] = '\0';

    printf("%d\n", binsearch(30, v, n));
    return 0;
}

int binsearch(int x, int v[], int n) {
    int low = 0, high = n - 1, mid;

    mid = (low+high) / 2;
    while ((low <= high) && (x != v[mid])) {
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        mid = (low+high) / 2;
    }
    return (x == v[mid]) ? mid : -1;
}
