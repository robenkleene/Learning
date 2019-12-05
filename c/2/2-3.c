#include <stdio.h>
#include <stdlib.h>

int main() {
    char s[] = "0X1F";
    int v = 0X1F;
    printf("%i\n", v);
    printf("%s\n", s);
    int result = atoi(s);
    printf("%i\n", result);
}

int htoi(char s[]) {
    return 0;
}
