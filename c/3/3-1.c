#include <stdio.h>
#include <time.h> 

int binsearch2(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    int index = low - 1;
    return x == v[index] ? index : -1;
}

int binsearch(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else /* found match */
            return mid;
    }
    return -1; /* no match */
}

/* #define LENGTH 14 */

int main() {
    int v[] = {11, 12, 203, 260, 600, 601, 700, 800, 900, 910, 1000, 1010, 1000};
    size_t n = sizeof(v) / sizeof(int);
    int x = 260;
    printf("x = %i\n", x);
    for (int i = 0; i < n; i++) {
        printf("%i ", v[i]);
    }

    clock_t t;

    printf("\n\nbinsearch2");
    t = clock();
    int result = binsearch2(x, v, n);
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("\n%f seconds", time_taken);
    printf("\nresult = %i\n", result);

    printf("\n\nbinsearch");
    t = clock();
    result = binsearch(x, v, n);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("\n%f seconds", time_taken);
    printf("\nresult = %i\n", result);
}
