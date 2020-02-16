#include <stdio.h>
#include "printbits.h"

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
