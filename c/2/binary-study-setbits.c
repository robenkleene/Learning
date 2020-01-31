#include <stdio.h>

void printbits(size_t const size, void const *const ptr) {
    unsigned char *b = (unsigned char *)ptr;
    unsigned char byte;
    int i, j;

    for (i = size - 1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}

void qpb(int x) {
    printbits(sizeof(x), &x);
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    int position_count = p + 1;
    int offset = p + 1 - n;
    int invert_position = ~0 << position_count;
    printf("Invert position\n");
    qpb(invert_position);
    int n_field = ~(~0 << offset);
    printf("n_field\n");
    qpb(n_field);
    int field = (invert_position | n_field);
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
    int n = 5;
    int p = 10;

    printf("n = %i, p = %i\n", n, p);
    printf("X\n");
    qpb(x);
    printf("Y\n");
    qpb(y);
    unsigned result = setbits(x, p, n, y);
    printf("result\n");
    qpb(result);
}
