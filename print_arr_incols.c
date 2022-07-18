/* a little snippet from k&r for printing an int array in collums */
#include <stdio.h>
#define n 55
int main (void) {
    
    int arr[100];
    for (int i=1; i <=100; i++)
        arr[i-1] = i;
    for (int i = 0; i < n; i++)
        printf("%6d%c", arr[i], (i % 10 == 9 || i == n - 1) ? '\n' : ' ');

    return 0;
}
