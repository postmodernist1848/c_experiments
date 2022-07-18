/* A binary search implementaion for arrays of ints */
#include <stdio.h>


int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (low <= high && x != v[mid]) {
        if (x < v[mid])
            high = mid - 1;
        else 
            low = mid + 1;
        mid = (low + high) / 2;
    }   
    return (v[mid] == x) ? mid : -1;

}

int main (void) {

    int arr[100];
    for (int i=0; i < 100; i++)
        arr[i] = i;
    printf("pos: %d\n", binsearch(55, arr, 100));
    
    return 0;

}
