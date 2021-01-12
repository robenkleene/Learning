#include <stdio.h>
#include "printbits.h"

int main() {
    int x = 0b01010101010101010101010101010101;
    int y = 0b10101010101010101010101010101010;
    int result;
    printf("X\n");
    qpb(x);
    printf("Y\n");
    qpb(y);

    x = 1;
    y = 5;
    result = x & y;
    printf("X\n");
    qpb(x);
    printf("Y\n");
    qpb(y);
    printf("Result\n");
    qpb(result);
}
