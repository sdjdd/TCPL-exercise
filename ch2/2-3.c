#include <stdio.h>
#include <string.h>
#include <ctype.h>

int htoi(char[]);

int main() {
    char s[] = "0xABCDEF";
    printf("%s = %d\n", s, htoi(s));

    return 0;
}

int htoi(char s[]) {
    int n, p, t;
    n = p = 0;

    if (strlen(s) > 2 && s[1] == 'x' || s[1] == 'X')
        p = 2;
    while (s[p] != '\0') {
        if (isdigit(s[p]))
            t = s[p] - '0';
        else
            t = tolower(s[p]) - 'a' + 10;
        n = n * 16 + t;
        ++p;
    }
    return n;
}