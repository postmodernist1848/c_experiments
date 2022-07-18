/* print range of different types */
#include <stdio.h>
#include <limits.h>

int main(void) {
puts("-----------------------calculated with bitwise ops---------------------");
    printf("Unsigned char max: %d\n", (unsigned char) ~0);
    printf("Signed char max: %d\n", (unsigned char) ~0 >> 1);    

    printf("Unsigned short max: %d\n", (unsigned short) ~0);
    printf("Signed short max: %d\n", (unsigned short) ~0 >> 1);

    printf("Unsigned int max: %u\n",(unsigned int)~0);
    printf("Signed int max: %d\n", (unsigned int) ~0 >> 1);

    printf("Unsigned long max: %lu\n", (unsigned long) ~0);
    printf("Signed long max: %ld\n", (unsigned long) ~0 >> 1);

    printf("Unsigned long long max: %llu\n", (unsigned long long) ~0);
    printf("Signed long long max: %lld\n", (unsigned long long) ~0 >> 1);
puts("-----------------------limits header---------------------");
    printf("Unsigned char max: %d\n", UCHAR_MAX);
    printf("Signed char max: %d\n", CHAR_MAX);    
    printf("Signed char min: %d\n", CHAR_MIN);    

    printf("Unsigned short max: %d\n", USHRT_MAX);
    printf("Signed short max: %d\n", SHRT_MAX);
    printf("Signed short min: %d\n", SHRT_MIN);

    printf("Unsigned int max: %u\n", UINT_MAX);
    printf("Signed int max: %d\n", INT_MAX);
    printf("Signed int min: %d\n", INT_MIN);

    printf("Unsigned long max: %lu\n", ULONG_MAX);
    printf("Signed long max: %ld\n", LONG_MAX);
    printf("Signed long min: %ld\n", LONG_MIN);

    printf("Unsigned long long max: %llu\n", ULLONG_MAX);
    printf("Signed long long max: %lld\n", LLONG_MAX);
    printf("Signed long long max: %lld\n", LLONG_MIN);

    return 0;
}
