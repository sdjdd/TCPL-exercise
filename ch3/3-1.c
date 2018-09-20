#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 1000
#define ROUND 1000000

int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[], int n);

int main() {
    srand((unsigned) time(NULL));
    int *a;

    a = (int*)malloc(sizeof(int) * LENGTH);
    a[0] = rand() % 101;
    for (int i = 1; i < LENGTH; ++i) {
        a[i] = a[i - 1] + rand() % 11;
    }

    int key = a[rand() % 1001];
    clock_t begin, end;

    begin = clock();
    for (int i = 0; i < ROUND; ++i) {
        binsearch(key, a, LENGTH);
    }
    end = clock();
    printf("binsearch:  %f μs\n", (double) (end - begin) / CLOCKS_PER_SEC / ROUND * 1000000);

    begin = clock();
    for (int i = 0; i < ROUND; ++i) {
        binsearch2(key, a, LENGTH);
    }
    end = clock();
    printf("binsearch2: %f μs\n", (double) (end - begin) / CLOCKS_PER_SEC / ROUND * 1000000);

    return 0;
}

int binsearch(int x, int v[], int n) {
    int low = 0;
    int high = n - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int binsearch2(int x, int v[], int n) {
    int low = 0;
    int high = n - 1;
    int mid;
    int t = -1;

    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else {
            t = mid;
            low = mid + 1;
        }
    }
    if (t > 0 && v[t] == x)
        return t;
    return -1;
}