#include <stdio.h>
#include "printbits.h"

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    int position_count = p + 1;
    int offset = p + 1 - n;
    int left_field = ~0 << position_count;
    printf("Left field\n");
    qpb(left_field);
    int right_field = ~(~0 << offset);
    printf("right_field\n");
    qpb(right_field);
    int field = left_field | right_field;
    printf("field\n");
    qpb(field);
    int x_with_offset = x & field;
    printf("x_with_offset\n");
    qpb(x_with_offset);
    int y_zeroed = y & ~(~0 << n);
    printf("y_zeroed\n");
    qpb(y_zeroed);
    int y_zeroed_shifted = y_zeroed << (p + 1 - n);
    printf("y_zeroed_shifted\n");
    qpb(y_zeroed_shifted);
    printf("x_with_offset | y_zeroed_shifted\n");

    return x_with_offset | y_zeroed_shifted;
}

int main() {
    // Complex
    int x = 0b01010101010101010101010101010101;
    int y = 0b10101010101010101010101010101010;
    int result;
    printf("X\n");
    qpb(x);
    printf("Y\n");
    qpb(y);

    x = 1;
    y = 4;
    result = 1 & 4;
    printf("X\n");
    qpb(x);
    printf("Y\n");
    qpb(y);
    printf("Result\n");
    qpb(result);
}
