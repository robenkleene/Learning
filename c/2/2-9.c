#include <stdio.h>
#include "printbits.h"

// `x &= (x−1)` deletes the rightmost 1-bit of `x`  by first decrementing it,
// which switches the rightmost 1-bit to a `0`, but also leaves 1-bits to the left of
// it. The 1-bits to the left are then removed by the `&` operation with the
// original `x`.

int bitcount(unsigned x) {
    int b;
    for (b = 0; x != 0; x &= (x-1))
        b++;
    return b;
}

int main() {
    int x = 0b01010100010010000010000100010000;
    printf("x\n");
    qpb(x);
    int result = bitcount(x);
    printf("result = %i\n", result);
}
