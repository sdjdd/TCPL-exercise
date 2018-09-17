#include <stdio.h>

unsigned rightrot(unsigned x, int n);

int main() {
    printf("%u", rightrot(15, 1));
    return 0;
}

unsigned rightrot(unsigned x, int n) {
    int i = 0;
    unsigned t = 1;
    while (t > 0) {
        t <<= 1;
        ++i;
    }
    n %= x;
    return x >> n | x << i - n;
}