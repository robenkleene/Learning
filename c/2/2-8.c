#include <stdio.h>
#include "printbits.h"

int rightrot(x, n) {
    int bits = sizeof(x) * 8;
    printf("bits = %i\n", bits);
    int field = ~(~0 << n);
    printf("field\n");
    qpb(field);
    int right_bits = x & field;
    printf("right_bits\n");
    qpb(right_bits);
    unsigned int ux = x;
    int shifted = ux >> n;
    printf("shifted\n");
    qpb(shifted);
    return shifted;
}

int main() {
    int x = 0b01010100000010000010000100010010;
    int n = 5;
    printf("n = %i\n", n);
    printf("X\n");
    qpb(x);
    unsigned result = rightrot(x, n);
    printf("result\n");
    qpb(result);
}
