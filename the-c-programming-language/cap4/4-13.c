#include <stdio.h>
#include <string.h>

void reverse(char s[]);

int main() {
    char s[4] = "foo";

    reverse(s);
    printf("%s\n", s);
}

void reverse_rec(char s[], int left, int right) {
    char tmp;

    if (left >= right)
        return;

   tmp = s[left];
   s[left] = s[right];
   s[right] = tmp;

   reverse_rec(s, ++left, --right);
}

void reverse(char s[]) {
    reverse_rec(s, 0, strlen(s)-1);
}
