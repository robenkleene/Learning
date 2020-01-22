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

unsigned setbits(unsigned x, int p, int n, int y) {
    printf("x\n");
    qpb(x);
    printf("y\n");
    qpb(y);
    int offset = (p + 1 - n);
    int field = ~(~0 << n) << offset;
    printf("field\n");
    qpb(field);
    int shifted = y << offset;
    printf("Shifted\n");
    qpb(shifted);
    /* int prepared = x & shifted; */
    /* printf("Prepared\n"); */
    /* qpb(prepared); */
    return x;
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
