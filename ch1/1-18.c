#include <stdio.h>

#define BUFFERSIZE 1000

int main() {
    int c, i, haslt;
    char buf[BUFFERSIZE];
    
    i = haslt = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t') {
            if (i < BUFFERSIZE - 1) {
                buf[i] = c;
                ++i;
            }
        } else if (c == '\n') {
            if (haslt)
                putchar('\n');
            i = haslt = 0;
        } else {
            if (i > 0) {
                buf[i] = '\0';
                printf("%s", buf);
                i = 0;
            }
            if (haslt == 0)
                haslt = 1;
            putchar(c);
        }
    }
    
    return 0;
}