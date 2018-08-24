#include <stdio.h>

int main() {
    float fahr, celsius;

    printf("%4s %6s\n%3s %6s\n", "fahr", "celsius", "----", "-------");
    for (fahr = 300; fahr >= 0; fahr = fahr - 20) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%4.0f %6.1f\n", fahr, celsius);
    }

    return 0;
}