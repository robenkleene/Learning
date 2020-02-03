#include <stdio.h>
#include "printbits.h"

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    int position_count = p + 1;
    int offset = p + 1 - n;
    int left_field = ~0 << position_count;
    int right_field = ~(~0 << offset);
    int field = left_field | right_field;
    int x_with_offset = (x & field);
    int y_zeroed = y & ~(~0 << n);
    int y_zeroed_shifted = y_zeroed << (p + 1 - n);
    return x_with_offset | y_zeroed_shifted;
}

int main() {
    int x = 0b01010101010101010101010101010101;
    int y = 0b10101010101010101010101010101010;
    int n = 5;
    int p = 10;
    unsigned result = setbits(x, p, n, y);
    printf("result\n");
    qpb(result);
}
