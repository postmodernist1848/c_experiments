/* print sizes of different types in C */
#include <stdio.h>
#include <stddef.h>

int func(void) {
    return 1;
}

int main (void) {
    puts("Sizes of types (in bytes):");
    printf("char: %zu\n", sizeof(char));
    printf("short: %zu\n", sizeof(short));
    printf("int: %zu\n", sizeof(int));
    printf("long: %zu\n", sizeof(long));
    printf("long long: %zu\n", sizeof(long long));
    printf("size_t: %zu\n", sizeof(size_t));
    printf("ptrdiff_t: %zu\n", sizeof(ptrdiff_t));
    void * UwU;
    printf("pointer: %zu\n", sizeof UwU);
    printf("pointer to a function (meaningless): %zu\n", sizeof func);

    return 0;
}
