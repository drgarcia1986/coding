#include <stdio.h>

int bitcount(unsigned x);

int main() {
    printf("%d\n", bitcount(10));
}

int bitcount(unsigned x) {
    /* x-1 always inverts the last bit.
     * `x & (x-1)` set the last bit to 0
     * the for iterations runs only for bits 1
     * (e.g. for number 10 (1010) the for runs 2 two times)
     *
     * 10 & (10-1) = 8
     * 8 & (8-1) = 0
     */
    int b;

    for (b = 0; x != 0; x &= x-1)
        b++;
    return b;
}
