#include <stdio.h>

int main() {
    int n, max=0, count=0;

    scanf("%d", &n);
    while(n > 0) {
        if(n % 2) {
            count++;
        } else {
            if(count > max)
                max = count;
            count = 0;
        }
        n /= 2;
    }
    if(max >= count)
        printf("%d", max);
    else
        printf("%d", count);

    return 0;
}
