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

void itob(int n, char s[], int b) {
    if (b > 35) return;
    int i = 0, sign = 1, t;
    if (n < 0)
        sign = -1;
    do {
        t = (n % b) * sign;
        if (t < 10)
            t += '0';
        else
            t += 'A' - 10;
        s[i++] = t;
    } while((n /= b) != 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main() {
    char s[100];
    itob(1440, s, 16);
    printf("%s\n", s);

    return 0;
}