#include <stdio.h>

#define MAXLINE 20

int _getline(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
    int c, i, len, max = 0;
    char line[MAXLINE], longest[MAXLINE], overflow[MAXLINE];
    while ((len = _getline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
            if (len == MAXLINE - 1 && line[len - 1] != '\n') {
                //keep reading
                for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
                    if (i < MAXLINE)
                        overflow[i] = c;
                }
                if (i < MAXLINE - 1) {
                    if (c == '\n') {
                        overflow[i] = c;
                        ++i;
                    }
                    overflow[i] = '\0';
                } else {
                    overflow[MAXLINE - 1] = '\0';
                    ++i;
                }
                max = max + i;
            }
        }
    if (max > 0) {
        printf(" length: %d\n", max);
        printf("content: %s", longest);
        if (max >= MAXLINE) {
            printf("%s", overflow);
        }
    }
    return 0;
}

int _getline(char line[], int maxline) {
    int c, i;
    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}