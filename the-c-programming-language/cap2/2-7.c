#include <stdio.h>

unsigned invert (unsigned x, int p, int n);
unsigned getbits(unsigned x, int p, int n);
void asbits(unsigned x);

int main() {
    asbits(invert((unsigned) 255, 4, 3));
    return 0;
}

unsigned invert (unsigned x, int p, int n) {
    /*
     * x = number to invert bits = 255 -> 1111 1111
     * p = position = 4
     * n = number of bits = 3
     *
     * mask -> 0000 0111
     * digits -> 2
     *
     * mask << digits -> 0001 1100
     * 1111 1111 ^ 0001 1100 -> 1110 0011
     */
    unsigned mask = ~(~0 << n); /* n bits 1 e.g. ~(~0 << 3) == 0111 */
    unsigned digits = (p + 1 - n); /* number of digits to get */

    return x ^ (mask << digits);
}

unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p+1-n)) & ~(~0 << n);
}

void asbits(unsigned x) {
	int i;
    size_t s = sizeof(x);

	for(i = s*8-1; i>=0; i--) {
		 if (getbits(x, i, 1))
             putchar('1');
         else
             putchar('0');

		 if (!(i % 4))
             putchar(' ');
	}
    putchar('\n');
}

