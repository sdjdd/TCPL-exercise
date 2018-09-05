#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y); 

int main() {
    printf("%d", setbits(12, 3, 3, 3));

    return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    return x & ~(~(~0 << n) << (p+1-n)) | (y & ~(~0 << n)) << (p+1-n);
}