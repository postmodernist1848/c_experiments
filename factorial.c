#include <stdio.h>
int factorial(int);
int main(void){
    int N;
    scanf("%d", &N);
    printf("%d\n", factorial(N));
    
    return 0;
}
int factorial(int k){
 if (k <= 1) return 1;
 else return factorial(k - 1) * k;
}