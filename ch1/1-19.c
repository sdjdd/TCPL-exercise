#include <stdio.h>

#define BUFFERSIZE 1000

void reverse(char arr[], int len);

int main() {
    int c, i = 0;
    char buf[BUFFERSIZE];
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            buf[i] = '\0';
            reverse(buf, i);
            printf("%s\n", buf);
            i = 0;
        } else if (i < BUFFERSIZE - 1) {
            buf[i] = c;
            ++i;
        }
    }
    
    return 0;
}

void reverse(char arr[], int len) {
    int t;
    for (int i = 0; i < len / 2; ++i) {
        t = arr[i];
        arr[i] = arr[len - i - 1];
        arr[len - i - 1] = t;
    }
}