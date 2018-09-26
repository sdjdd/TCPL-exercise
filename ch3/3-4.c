/*
 * 若整型使用16位二进制, 负数使用2的补码表示, 其范围: [-2147483648, 2147483647]
 * 直接取负会溢出
 */
#include <stdio.h>
#include <limits.h>

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

void itoa(int n, char s[]) {
    int i = 0, sign = 1;
    if (n < 0)
        sign = -1;
    do {
        s[i++] = (n % 10) * sign + '0';
    } while((n /= 10) != 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main() {
    char s[100];
    itoa(INT_MIN, s);
    printf("%s\n", s);

    return 0;
}