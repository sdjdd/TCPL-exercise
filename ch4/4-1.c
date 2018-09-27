#include <stdio.h>
#include <string.h>

int strindex(char s[], char t[]) {
    int i, j, k, lt;
    lt = strlen(t);
    for (i = strlen(s) - 1; i >= 0; --i) {
        for (j = i, k = lt - 1; k >= 0 && s[j] == t[k]; --j, --k)
            ;
        if (k == -1)
            return i - lt + 1;
    }
    return -1;
}

int main() {
    char s1[] = "gtmdc3p!";
    char s2[] = "c3p";

    printf("%d\n", strindex(s1, s2));

    return 0;
}
