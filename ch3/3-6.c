#include <stdio.h>

void reverse(char s[]) {
    int c, i, n;
    i = n = 0;
    while (s[n] != '\0')
        ++n;
    n--;
    while (n > i) {
        c = s[i];
        s[i] = s[n];
        s[n] = c;
        ++i;
        --n;
    }
}

void itoa(int n, char s[], int w) {
    int i = 0, sign = 1;
    if (n < 0)
        sign = -1;
    do {
        s[i++] = (n % 10) * sign + '0';
        --w;
    } while((n /= 10) != 0);
    if (sign < 0) {
        s[i++] = '-';
        --w;
    }
    while (w > 0) {
        s[i++] = ' ';
        --w;
    }
    s[i] = '\0';
    reverse(s);
}

int main() {
    char s[100];
    itoa(-100, s, 4);
    printf("%s\n", s);

    return 0;
}