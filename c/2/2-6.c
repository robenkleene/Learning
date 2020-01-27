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
    int invert_position = (~0 << position_count);
    int x_with_offset = (x & invert_position);
    int n_field = ~(~0 << offset);
    int y_zeroed = y & ~(~0 << n);
    int y_zeroed_shifted = y_zeroed << (p + 1 - n);
    return x_with_offset | n_field | y_zeroed_shifted;
}

int main() {
    int x = 127;
    int y = 0;
    int n = 3;
    int p = 2;
    unsigned result = setbits(x, p, n, y);
    printf("result\n");
    qpb(result);
}
