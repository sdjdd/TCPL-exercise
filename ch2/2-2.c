#include <stdio.h>

int main() {
    char c, s[100];
    int i, lim = 100;

    for (i = 0; i < lim - 1; ++i) {
        if ((c = getchar()) != '\n')
            if (c != EOF)
                s[i] =c;
    }
    
    return 0;
}