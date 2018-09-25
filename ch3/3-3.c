#include <stdio.h>
#include <stdbool.h>

bool islegalchar(int c) {
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9') {
        return true;
    }
    return false;
}

void expand(char s1[], char s2[]) {
    int i, j, last, llast;

    for (i = j = 0; s1[i] != '\0'; ++i) {
        if (last == '-' && islegalchar(llast) && islegalchar(s1[i])) {
            int t = llast + 1, k = j - 1;
            while (t < s1[i]) {
                if (t == 'z' || t == 'Z' || t == '9') {
                    break;
                }
                s2[k] = t;
                ++t;
                ++k;
            }
            if (k - j >= 0)
                j += k - j;
        }
        s2[j++] = s1[i];
        llast = last;
        last = s1[i];
    }
    s2[j] = '\0';
}

int main() {
    char s1[] = "-b-ahaha0-9a-z,A-Z";
    char s2[100];

    expand(s1, s2);
    printf("%s\n%s\n", s1, s2);

    return 0;
}