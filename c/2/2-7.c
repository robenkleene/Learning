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
    int x = 0b11111111111111111111;
    int n = 5;
    int p = 9;
    unsigned result = invert(x, p, n);
    printf("result\n");
    qpb(result);
}
