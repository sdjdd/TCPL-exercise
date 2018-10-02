#include <stdio.h>

#define NORMAL     0
#define SINGLELINE 1
#define MULTILINE  2

int main() {
    int c, last, lastlast, mode, inStr;
    
    inStr = 0;
    while ((c = getchar()) != EOF) {
        if (c == '"')
            inStr = !inStr;
        if (!inStr) {
            if (mode == SINGLELINE) {
                if (c == '\n') {
                    mode = NORMAL;
                    putchar(c);
                }
            } else if (mode == MULTILINE) {
                if (c == '/' && last == '*')
                    mode = NORMAL;
            } else if (last == '/') {
                if (c == '/')
                    mode = SINGLELINE;
                else if (c == '*')
                    mode = MULTILINE;
                else if (lastlast != '*') {
                    putchar(last);
                    putchar(c);
                }
            } else if (c != '/')
                putchar(c);
        } else 
            putchar(c);
        lastlast = last;
        last = c;
    }

    return 0;
}