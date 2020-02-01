#include <stdio.h>
#include "printbits.h"

unsigned invert(unsigned x, int p, int n) {
    int position_count = p + 1;
    int offset = p + 1 - n;
    int invert_position = (~0 << position_count);
    printf("invert_position\n");
    qpb(invert_position);
    int x_with_offset = (x & invert_position);
    printf("x_with_offset\n");
    qpb(x_with_offset);
    int n_field = ~(~0 << offset);
    printf("n_field\n");
    qpb(n_field);
    return x_with_offset | n_field;
}

int main() {
    int x = 0b10101010101010101010101010101010;
    int n = 5;
    int p = 9;
    printf("n = %i, p = %i\n", n, p);
    printf("X\n");
    qpb(x);
    unsigned result = invert(x, p, n);
    printf("result\n");
    qpb(result);
}
