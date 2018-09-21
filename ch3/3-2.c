#include <stdio.h>

void escape(char *s, char *t);
void epacse(char *s, char *t);

int main() {
    char a[] = "gt\tmd\nc3p";
    char b[100];
    char c[100];
    escape(b, a);
    epacse(c, b);
    printf("%s\n", a);
    printf("%s\n", b);
    printf("%s\n", c);
    return 0;
}

void escape(char *s, char *t) {
    int p = 0;
    for (int i = 0; t[i] != '\0'; ++i) {
        switch (t[i]) {
        case '\t':
            s[p++] = '\\';
            s[p++] = 't';
            break;
        case '\n':
            s[p++] = '\\';
            s[p++] = 'n';
            break;
        default:
            s[p++] = t[i];
            break;
        }
    }
    s[p] = '\0';
}

void epacse(char *s, char *t) {
    int p = 0;

    for (int i = 0; t[i] != '\0'; ++i) {
        if (t[i] == '\\' && t[i+1] != '\0') {
            switch (t[i+1]) {
            case 't':
                s[p++] = '\t';
                break;
            case 'n':
                s[p++] = '\n';
                break;
            default:
                s[p++] = '\\';
                s[p++] = t[i];
                break;
            }
            ++t;
        } else {
            s[p++] = t[i];
        }
    }
    s[p] = '\0';
}