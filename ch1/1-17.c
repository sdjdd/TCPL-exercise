#include <stdio.h>

#define MAXLINE 10

int main() {
    int c, i = 0;
    char buf[MAXLINE + 1];
    buf[MAXLINE] = '\0';

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            if (i >= MAXLINE)
                putchar('\n');
            i = 0;
        } else {
            if (i < MAXLINE)
                buf[i] = c;
            else if (i == MAXLINE) {
                printf("%s", buf);
                putchar(c);
            } else {
                putchar(c);
            }
            ++i;
        }
    }

    return 0;
}