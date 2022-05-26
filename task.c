#include <stdio.h>
#include <stdint.h>

int main(void) {
    uint8_t N=138;
    uint8_t new_N=~N;
    printf("%d\n", new_N - N);    

    return 0;
}