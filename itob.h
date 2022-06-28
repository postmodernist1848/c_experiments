#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char s[])
{
    char temp;
    for (int i=0, j=strlen(s) - 1; i < j; i++, j--)
        temp = s[i], s[i] = s[j], s[j] = temp;
}

/* itob: convert integer n to a string representation of n in base b */
void itob(int n, char s[], int b)
{
    //2 <= b <= 36 (10 digits and 26 letters of the English alphabet)
    if (!(2 <= b && b <= 36)) {
        fprintf(stderr, "Error: `b` is supposed to be a base between 2 and 36");
        exit(1);
    }

    int i=0, sign=n, digit;
    do {
        digit = n % b;
        s[i++] = (digit < 10) ? digit + '0': digit + - 10 + 'A';
    } while ((n /= b) != 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
/* itoa_field: convert int to string adding padding to fit minimum width field */
void itoa_field(int n, char s[], int field)
{
    int i=0, sign=n;
    do {
        s[i++] = n % 10 + '0';
        field--;
    } while ((n /= 10) > 0);
    if (sign < 0) {
        s[i++] = '-';
        field--;
    }
    //add padding if field > 0
    for (int k=0; k < field; k++)
        s[i++] = ' ';
    s[i] = '\0';
    reverse(s);
}

