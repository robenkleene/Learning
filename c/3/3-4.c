/* itoa:  convert n to characters in s */
void itoa(int n, char s[]) {
    int i, sign;
    if ((sign = n) < 0)
        /* record sign */
        /* make n positive */
        n = -n;
    i = 0;
    do {
        /* generate digits in reverse order */
        /* get next digit */
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
