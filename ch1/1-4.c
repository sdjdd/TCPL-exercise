#include <stdio.h>

int main() {
    float celsius, fahr;
    float lower, upper, step;

    lower = 0;
    upper = 150;
    step  = 10;

    celsius = lower;
    printf("%7s %3s\n%7s %3s\n", "celsius", "fahr", "-------", "----");
    while (celsius <= upper) {
        fahr = celsius * 9.0 / 5.0 + 32.0;
        printf("%7.0f %3.0f\n", celsius, fahr);
        celsius = celsius + step;
    }

    return 0;
}