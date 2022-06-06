/* My C iimplementation of a recursive merge sort function */

#include <stdio.h>
#include <stdlib.h>

#define COUNT 100

void print_arr (int buff[], int len){
    for (int i=0; i<len; i++)
    printf("%d ", buff[i]);
}

void merge_sort(int *arr, int len) {    
    if (len > 1) {
        int mid = len / 2;
        merge_sort(arr, mid);
        merge_sort(arr + mid, mid + len % 2);
        int i=0, j=0, k=0;
        int L[mid], R[mid + len % 2];

        for (int k = 0; k < mid; k++)
        L[k] = arr[k];
        
        for (int k = 0; k < mid + len % 2; k++)
        R[k] = arr[mid + k];

        while (i < mid && j < mid + len % 2) {
            if (L[i] < R[j]) {
                arr[k] = L[i];
                i++;
            } else {arr[k] = R[j];
                    j++;}
            k++;     
        }
        while (i < mid) {arr[k] = L[i]; k++; i++;}
        while (j < mid + len % 2) {arr[k] = R[j]; k++; j++;}
        
    }
}

int main (void) {
    int numbers[COUNT];
    srand(rand());
    //generate random array
    for (int i=1; i <= COUNT; i++){
        numbers[i] = i;
    }
    for (int i=0; i < COUNT; i++)
        {
            size_t j = i + rand() / (RAND_MAX / (COUNT - i) + 1);
            int t = numbers[j];
            numbers[j] = numbers[i];
            numbers[i] = t;
        }



    printf("Unsorted array:\n");
    print_arr(numbers, COUNT); printf("\n");
    merge_sort(numbers, COUNT); printf("\n");
    printf("Sorted array:\n");
    print_arr(numbers, COUNT); printf("\n");
    return 0;
}