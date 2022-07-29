/* calloc inplementation based on malloc */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *mycalloc(size_t n, size_t size) {
    void * ptr = malloc(n * size);
    if (ptr != NULL)
        memset(ptr, 0, n * size);
    return ptr;
}

int main (void) {


    size_t n = 1000;
    size_t size = sizeof(int);
    char *ptr = mycalloc(n, size);
    if (ptr != NULL)
        for (size_t i=0; i < n; i++)
            printf("%d, ", ptr[0]);

    return 0;
}
