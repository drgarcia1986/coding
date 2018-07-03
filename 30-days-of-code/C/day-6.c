#include <stdio.h>
#include <string.h>

void process(char s[100]) {
    char odd[5000], even[5000];
    int o_idx=0, e_idx=0;

    for (int i=0; i < strlen(s); i++) {
        if ((i % 2) == 0)
            even[e_idx++] = s[i];
        else
            odd[o_idx++] = s[i];
    }
    even[e_idx] = '\0';
    odd[o_idx] = '\0';

    printf("%s %s\n", even, odd);
}

int main() {
    int n;
    char s[10000];

    scanf("%d\n", &n);

    for(int i=0; i < n; i++) {
        scanf("%[^\n]\n", s);
        process(s);
    }

    return 0;
}
