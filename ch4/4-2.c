#include <ctype.h>
#include <stdio.h>

double atof(char s[]) {
    double val, power;
    int i, sign, psign, e;

    for (i = 0; isspace(s[i]); ++i)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        ++i;
    for (val = 0.0; isdigit(s[i]); ++i)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        ++i;
    for (power = 1.0; isdigit(s[i]); ++i) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    if (s[i] == 'e' || s[i] == 'E')
        ++i;
    psign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        ++i;
    for (e = 0; isdigit(s[i]); ++i) {
        e = e * 10 + s[i] - '0';
    }
    while (e > 0) {
        if (psign > 0)
            power /= 10;
        else
            power *= 10;
        --e;
    }
    return sign * val / power;
}

int main() {
    printf("%f\n", atof("3.33"));
    printf("%f\n", atof("3e-3"));
    printf("%f\n", atof("0.0000000001e11"));

    return 0;
}