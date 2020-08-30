#include <stdio.h>

// Define a struct
struct point {
    int x;
    int y;
};

void print_point(struct point pt) {
    printf("%d, %d\n", pt.x, pt.y);
}

int main() {
    // Declare a struct variablle
    struct point pt;
    // Set its member values
    pt.x = 5;
    pt.y = 10;
    print_point(pt);

    // Declare and initialize
    struct point maxpt = { 320, 200 };
    print_point(maxpt);
}
