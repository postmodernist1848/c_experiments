#include <stdio.h>
#include <math.h>

void problem1(void) {
    for (int i = 100; i <= 150; i++)
        printf("%d\n", i);
}

void problem2(void) {
    for (int i = 10; i <= 25; i++)
        printf("%d\n", i);
}

void problem3(void) {
    for (int i = 0;; i += 2)
        printf("%d\n", i);
}

void problem4(void) {
    for (int i = 100; i >= -100; i--)
        printf("%d\n", i);
}

void problem5(void) {
    for (int i = 1;; i += 3)
        printf("%d\n", i);
}

void problem6_1(void) {
    for (int i = 0, sqrt = 1; i < 1000; i = sqrt * sqrt, sqrt++)
        printf("%d\n", i);
}

void problem6_2(void) {
    for (int i = 0; i < 1000; i = ((sqrt(i)) + 1) * (sqrt(i) + 1))
        printf("%d\n", i);
}

void problem6_3(void) {
    for (int i = 0, square = 1; i < 1000; i = (pow(square++, 2)))
        printf("%d\n", i);
}

void problem7_1(void) {
    for (int i = 0, j = 1, temp = 0; i < 1000; temp = i, i = j, j = temp + i)
        printf("%d\n", i);
}


void problem7_2(void) {
    for (int i = 0, j = 1; i < 1000; j = (i ^= j) ^ j + j)
        printf("%d\n", i);
}

int main (void) {
    problem7_1();

    return 0;
}
