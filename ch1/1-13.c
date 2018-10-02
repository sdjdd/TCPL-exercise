#include <stdio.h>

int main() {
    int c, i, lword[50];
    
    for (i = 0; i < 50; ++i)
        lword[i] = 0;
    
    i = 0;
    while ((c = getchar()) != EOF) {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
            ++i;
        else if (i > 0) {
            ++lword[i];
            i = 0;
        }
    }

    //drawing
    for (i = 0; i < 50; ++i) {
        if (lword[i] > 0) {
            printf("%2d: ", i);
            while (lword[i] > 0) {
                putchar('=');
                --lword[i];
            }
            putchar('\n');
        }
    }

    return 0;
}