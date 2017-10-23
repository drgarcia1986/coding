#include <stdio.h>

int main() {
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 148.9;
    step = 20;

    printf("CELS\tFAHR\n");
    fahr = lower;
    while (celsius <= upper) {
        fahr = celsius * (9.0/5.0) + 32.0;
        printf("%6.1f\t%3.0f\n", celsius, fahr);
        celsius = celsius + step;
    }
}
