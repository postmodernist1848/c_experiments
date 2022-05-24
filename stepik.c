#include <stdio.h>
#include <string.h>
int main (void) {
    char str1[] = "hello",
    str2[] = "helLo";

    printf("%d\n", strcmp(str1, str2));

    return 0;
}