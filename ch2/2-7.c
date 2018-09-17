#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main() {
    printf("%d\n", invert(8, 2, 3));
    return 0;
}

unsigned invert(unsigned x, int p, int n) {
    return x & ~(~(~0 << n) << (p+1-n)) | (~x & ~(~0 << n)) << (p+1-n);
}