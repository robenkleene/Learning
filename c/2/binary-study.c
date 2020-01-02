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
    // Bitwise & masking
    printf("Masking test n = n & 0177, sets to zero all but the low-order 7 bits of n\n");
    int n = 5;
    printf("n = %i\n", n);
    qpb(n);
    int constant = 0177;
    printf("0177 = %i\n", 0177);
    qpb(constant);
    int result = n & 0177;
    printf("result = %i & 0177\n", n);
    qpb(result);
}

unsigned operations(unsigned x, int p, int n) {
    printf("\nPerforming a series of bitwise operations\n");
    qpb(x);
    int offset = p + 1 - n;
    printf("p + 1 - n = %i\n", offset);
    int shifted = x >> offset;
    printf("x >> %i\n", offset);
    qpb(shifted);
    printf("~(~0 << %i)\n", n);
    qpb(~(~0 << n));
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

int main() {
    test();

    int x = 10;
    /* qpb(x); */
    unsigned result = operations(x, 4, 3);
    /* printf("%i\n", result); */
    qpb(result);
}
