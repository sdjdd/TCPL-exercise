#include <stdio.h>

int main() {
    int c, i, freq[128];
    
    for (i = 0; i < 128; ++i)
        freq[i] = 0;
    
    while ((c = getchar()) != EOF)
        ++freq[c];
    
    for (i = 0; i < 128; ++i) {
        if (freq[i] > 0) {
            if (i == '\a')
                printf("'\\a:' ");
            else if (i == '\b')
                printf("'\\b': ");
            else if (i == '\t')
                printf("'\\t': ");
            else if (i == '\n')
                printf("'\\n': ");
            else if (i == '\v')
                printf("'\\v': ");
            else if (i == '\f')
                printf("'\\f': ");
            else if (i == '\r')
                printf("'\\r': ");
            else
                printf(" '%c': ", i);
            while (freq[i] > 0) {
                putchar('=');
                --freq[i];
            }
            putchar('\n');
        }
    }

    return 0;
}