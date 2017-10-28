#include <stdio.h>

unsigned rightrot(unsigned x, int n);
unsigned getbits(unsigned x, int p, int n);
void asbits(unsigned x);

int main() {
    asbits(rightrot((unsigned) 255, 8));
}

unsigned rightrot(unsigned x, int n) {
    /*
     * x = number to right rotate bits = 255 -> 0000 0000 0000 0000 0000 0000 1111 1111
     * n = positions to rotate = 8
     * r-shift unsigned = ~(~0U >> 1) -> 1000 0000 0000 0000 0000 0000 0000 0000
     *
     * using unsigned because the left most bit is for signal on signed ints
     */
    for (n = n; n > 0; --n) {
        if(x & 1) /* bit is 1 */
            x = (x >> 1) | ~(~0U >> 1);
        else /* bit is 0 */
            x = x >> 1;
    }
    return x;
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

