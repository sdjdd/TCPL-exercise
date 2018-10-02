#include <stdio.h>

#define NEWLINE 10

int main() {
    char buf[NEWLINE];
    int c, i, j, p, nl;
    
    i = 0;
    nl = NEWLINE - 1;
    while ((c = getchar()) != EOF) {
        if (i == nl) {
            for (j = 0; j < i; ++j) {
                if (buf[j] != ' ' && buf[j] != '\t')
                    p = j;
            }
            for (j = 0; j < i; ++j) {
                putchar(buf[j]);
                if (j == p)
                    putchar('\n');
            }
            nl = NEWLINE - (i - p - 1) - 1;
            i = 0;
        }
        if (c == '\n') {
            buf[i] = '\0';
            printf("%s\n", buf);
            i = 0;
        } else {
            buf[i] = c;
            ++i;
        }
    }

    return 0;
}