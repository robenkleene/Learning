#include <stdio.h>

typedef struct {
    int x;
    int y;
} point_t;

// Define a struct
void print_point(point_t pt) {
    printf("%d, %d\n", pt.x, pt.y);
}

int main() {
    point_t maxpt = { 320, 200 };
    print_point(maxpt);
}
