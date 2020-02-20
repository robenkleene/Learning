#include <stdio.h>

#define LENGTH 5

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

int main() {
    int v[LENGTH] = {11, 12, 203, 260, 600};
    int x = 260;
    int result = binsearch2(x, v, LENGTH);
    printf("result = %i\n", result);
}
