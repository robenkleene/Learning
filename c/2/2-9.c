#include <stdio.h>
#include "printbits.h"

// `x &= (x−1)` deletes the rightmost 1-bit of `x` because if the left most bit
// is a `1`, it becomes a `0`, whereas if it's a `0`, it will shift the
// rightmost 1-bit left.

int bitcount(unsigned x) {
    printf("x - 1\n");
    qpb(x - 1);
    x &= (x - 1);
    printf("x\n");
    qpb(x);

    int b;

    for (b = 0; x != 0; x >>= 1)
        if (x & 01)
            b++;
    return b;
}

int main() {
    int x = 10;
    printf("x\n");
    qpb(x);
    int result = bitcount(x);
    printf("Result\n");
    qpb(result);
}
