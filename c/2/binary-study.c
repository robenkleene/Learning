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

void test() {
    // Octal
    // Preceding an integer with 0 makes it octal, e.g., 0112
    printf("\noctal test, 0112 equals 74\n");
    int octal = 0112; // 0112 is 74 in octal
    printf("0112 = octal = %i\n", octal);
    // Binary
    // Preceding an integer with `0b` makes it binary.
    int binary = 0b100; // 0112 is 74 in octal
    printf("0b100 = binary = %i\n", binary);
    // Shift
    int result = binary << 2;
    printf("result = %i << 2\n", binary);
    qpb(result);
    result = binary >> 2;
    printf("result = %i >> 2\n", binary);
    qpb(result);
    // Bitwise & masking
    printf("Masking test n = n & 0177, sets to zero all but the low-order 7 bits of n\n");
    int n = 5;
    printf("n = %i\n", n);
    qpb(n);
    int constant = 0177;
    printf("0177 = %i\n", 0177);
    qpb(constant);
    printf("~0177\n");
    qpb(~constant);
    result = n & 0177;
    printf("result = %i & 0177\n", n);
    qpb(result);
}

unsigned operations(unsigned x, int p, int n) {
    printf("\nPerforming a series of bitwise operations\n");
    printf("x = %i, p = %i, n = %i\n", x, p, n);
    printf("Get right most n bits of x starting from position p\n");
    qpb(x);
    printf("(x >> (p + 1 - n)) & ~(~0 << n)\n");
    printf("(%i >> (%i + 1 - %i)) & ~(~0 << %i)\n", x, p, n, n);
    int offset = p + 1 - n;
    printf("p + 1 - n = %i\n", offset);
    int shifted = x >> offset;
    printf("Shift the bits by %i to the right\n", offset);
    printf("x >> %i\n", offset);
    qpb(shifted);
    printf("~(~0 << %i)\n", n);
    qpb(~(~0 << n));
    printf("(%i >> (%i + 1 - %i)) & ~(~0 << %i)\n", x, p, n, n);
    int result = (x >> (p + 1 - n)) & ~(~0 << n);
    qpb(result);
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

int main() {
    test();
    int x = 10;
    operations(x, 4, 3);
}
