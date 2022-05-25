#include <stdio.h>
long int factorial(int);
int main(void){
    int N;
    scanf("%d", &N);
    printf("%ld\n", factorial(N));
    
    return 0;
}
long int factorial(int k){
 if (k <= 1) return 1;
 else return factorial(k - 1) * k;
}