#include <stdio.h>
#include <string.h>
int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
int main (void) {
    char str[] = "IamDOINGBigstuFF"; 
    for (size_t i=0; i < strlen(str); i++) {
        putchar(lower(str[i]));
    }

    return 0;
}

