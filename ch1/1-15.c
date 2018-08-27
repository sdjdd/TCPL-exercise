#include <stdio.h>

float fahr2celsius(float fahr);

int main() {
    float fahr;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step  = 20;

    fahr = lower;
    printf("%4s %6s\n%3s %6s\n", "fahr", "celsius", "----", "-------");
    while (fahr <= upper) {
        printf("%4.0f %6.1f\n", fahr, fahr2celsius(fahr));
        fahr = fahr + step;
    }

    return 0;
}

float fahr2celsius(float fahr) {
    return (5.0 / 9.0) * (fahr - 32.0);
}