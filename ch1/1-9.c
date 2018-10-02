#include <stdio.h>

int main() {
    int c, last;
    
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            if (last != ' ')
                putchar(c);
        if (c != ' ')
            putchar(c);
        last = c;
    }

    return 0;
}