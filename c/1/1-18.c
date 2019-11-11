#include <stdio.h>
#define MAXWS 1000

int main()
{
    int c, i;
    char ws[MAXWS];
    while ((c = getchar()) != EOF) {
        switch (c) {
            case '\n':
                i = 0;
            case ' ':
            case '\t':
                if (i < MAXWS) {
                    ws[i] = c;
                    ++i;
                }
                break;
            default:
                ws[i] = '\0';
                printf("%s", ws);
                putchar(c);
                i = 0;
                break;
        }
    }
    return 0;
}
