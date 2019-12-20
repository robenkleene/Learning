#include <stdio.h>

void printbits(size_t const size, void const * const ptr) {
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i=size-1;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}

void qpb(int x) {
    printbits(sizeof(x), &x);
}

unsigned getbits(unsigned x, int p, int n) {
    /* int offset = p + 1 - n; */
    /* printf("offset = p + 1 - n = %i\n", offset); */
    /* int shifted = x >> offset; */
    /* printf("shifted = x >> offset = %i\n", offset); */
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

int main() {
    int x = 10;
    qpb(x);
    unsigned result = getbits(x, 4, 3);
    printf("%i\n", result);
    qpb(result);
}
