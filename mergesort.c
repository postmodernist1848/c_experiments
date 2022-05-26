#include <stdio.h>
#include <stdlib.h>

#define COUNT 6

void print_arr (int buff[], int len){
    for (int i=0; i<len; i++)
    printf("%d ", buff[i]);
}

void merge_sort(int *arr, int len) {    
    if (len > 1) {
        int mid = len / 2;
        print_arr(arr, mid);
        merge_sort(arr, mid);
        print_arr(arr + mid, mid + len % 2);
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
        while (j < mid + len % 2) {arr[k] = R[j];}
        
    }
}

int main (void) {
    int numbers[COUNT];
    //generate random array
    for (int i=0; i < COUNT; i++){
        numbers[i] = rand() % 6;
    }
    print_arr(numbers, COUNT); printf("\n");
    merge_sort(numbers, COUNT);
    print_arr(numbers, COUNT); printf("\n");
    return 0;
}