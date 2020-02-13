#include <stdio.h>
#include "printbits.h"

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
