#include <stdio.h>

#define SPACEWIDTH 8

int main() {
    int c, i;
    while ((c = getchar()) != EOF) {
        if (c == '\t')
            for (i = SPACEWIDTH; i > 0; --i)
                putchar(' ');
        else
            putchar(c);
    }

    return 0;
}