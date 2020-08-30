#include <stdio.h>

struct point {
    int x;
    int y;
} myPoint;

// Define a struct
void print_point(struct point pt) {
    printf("%d, %d\n", pt.x, pt.y);
}

int main() {
    myPoint.x = 5;
    myPoint.y = 10;
    print_point(myPoint);
}
