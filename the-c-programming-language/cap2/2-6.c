#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
void asbits(unsigned x);

int main() {
    asbits(setbits((unsigned) 255, 4, 2, (unsigned) 2));
    return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    /*
     * x = number to set bits = 255 -> 1111 1111
     * p = position = 4
     * n = number of bits = 2
     * y = bits to set = 2 -> 0000 0010
     *
     * mask -> 0000 0011
     * digits -> 3
     *
     * (x & ~(mask << digits) -> mark expected digits as 0 -> 1110 0111
     * (y & mask) << digits -> mark expected digits of y as 1 and rest as zero -> 0001 0000
     *
     * 1110 0111 | 0001 0000 -> 1111 0111
     */

    unsigned mask = ~(~0 << n); /* n bits 1 e.g. ~(~0 << 3) == 0111 */
    unsigned digits = (p + 1 - n); /* number of digits to get */

    return (x & ~(mask << digits)) | (y & mask) << digits;
}

unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p+1-n)) & ~(~0 << n);
}

/* Prints a binary representation of an int */
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
