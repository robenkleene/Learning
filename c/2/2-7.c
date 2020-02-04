#include <stdio.h>
#include "printbits.h"

unsigned invert(unsigned x, int p, int n) {
    int position_count = p + 1;
    int offset = p + 1 - n;

    int left_field = ~0 << position_count;
    int right_field = ~(~0 << offset);
    int middle_field = ~(left_field | right_field);
    int left = x & left_field;
    int right = right_field & x;
    int middle = (~(x & middle_field)) & middle_field;

    return left | middle | right;
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
