#include <stdio.h>

int foo(void * a, void * b){
    return *(int*) a + *(int *) b;
}

int main(void) {
    int a=10, b = 5;
    int *p_a = &a;
    int *p_b = &b;
    printf("%d\n", foo(p_a, p_b));
    return 0;
}
//an attempt at so-called type punning