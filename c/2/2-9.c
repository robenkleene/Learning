#include <stdio.h>
#include "printbits.h"

// `x &= (x−1)` deletes the rightmost 1-bit of `x`  by first decrementing it,
// which switches the rightmost 1-bit to a `0`, but also leaves 1-bits to the left of
// it. The 1-bits to the left are then removed by the `&` operation with the
// original `x`.

int bitcount(unsigned x) {
    int decremented = x - 1;
    printf("decremeneted\n");
    qpb(decremented);
    int shifted = x;
    shifted &= decremented;
    printf("shifted\n");
    qpb(shifted);

    int b;

    for (b = 0; x != 0; x >>= 1)
        if (x & 01)
            b++;
    return b;
}

int main() {
    int x = 0b01010100000010000010000100010000;
    printf("x\n");
    qpb(x);
    int result = bitcount(x);
    printf("result = %i\n", result);
}
