#include <stdio.h>

void print_hello(void) {
    puts("Hello!");
}

typedef struct object Object;

struct object {
    void (*method) (void);
};

int main (void) {
    void (*hello_p) (void) = print_hello;
    void (*hello_p2) (void) = ********************************************************************************************************************************************hello_p;
    hello_p2();

    Object obj = {print_hello};
    obj.method();

    return 0;
}

