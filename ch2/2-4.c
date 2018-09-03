#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main() {
    char s1[] = "gtmdc3p!";
    char s2[] = "gmcp";

    squeeze(s1, s2);
    printf("%s\n", s1);

    return 0;
}

void squeeze(char s1[], char s2[]) {
    int i, j, p;
    for (i = p = 0; s1[i] != '\0'; ++i) {
        for (j = 0; s2[j] != '\0'; ++j)
            if (s1[i] == s2[j])
                break;
        if (s2[j] == '\0')
            s1[p++] = s1[i];
    }
    s1[p] ='\0';
}