#include <stdio.h>

int main() {
    int c, bc;

    bc = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (bc < 1)
                putchar(c);
            ++bc;
        } else {
            putchar(c);
            bc = 0;
        }
    }
}
