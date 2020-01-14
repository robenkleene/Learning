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
    // First thing I have to do is set n bits from postion p to `1`
    int field = ~(~0 << n) << (p + 1 - n);
    printf("field\n");
    qpb(field);
    printf("x\n");
    qpb(x);
    printf("y\n");
    qpb(y);
    return x;
}

int main() {
    int x = 555;
    int y = 777;
    unsigned result = setbits(x, 4, 3, y);
    printf("result\n");
    qpb(result);
}
