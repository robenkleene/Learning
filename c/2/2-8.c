#include <stdio.h>
#include "printbits.h"

int rightrot(x, n) {
    // Right Bits
    int right_field = ~(~0 << n);
    printf("right_field\n");
    qpb(right_field);
    int right_bits = x & right_field;
    printf("right_bits\n");
    qpb(right_bits);
    int bits = sizeof(x) * 8;
    printf("bits = %i\n", bits);
    int right_bits_shifted = right_bits << (bits - n);
    printf("right_bits_shifted\n");
    qpb(right_bits_shifted);

    // Rotate
    unsigned int ux = x;
    int shifted = ux >> n;
    printf("shifted\n");
    qpb(shifted);

    return shifted | right_bits_shifted;
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
