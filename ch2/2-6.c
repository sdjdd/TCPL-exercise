#include <stdio.h>

int setbits(int x, int p, int n, int y); 

int main() {
    printf("%d", setbits(12, 3, 3, 3));

    return 0;
}

int setbits(int x, int p, int n, int y) {
    return x & (y << p+1-n) | (y << p+1-n);
}