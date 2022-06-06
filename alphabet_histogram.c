/*
This program prints a histogram of letter frequencies in a text.
Quick start: 
./build.sh alphabet_histogram.c
./alphabet_histogram < text.txt
*/


#include <stdio.h>
#include <string.h>
#define CHARACTERS_COUNT 26
#define HISTOGRAM_HEIGHT 45
#define BAR_WIDTH 3

int max_value(int *arr, int len) {
    int max_value = arr[0];
    for (int i = 1; i < len; i++) {
        if (arr[i] > max_value) max_value = arr[i];
    } 
    return max_value;
}

int main(void){ 
    //input
    int chars_count[CHARACTERS_COUNT] = {0};
    int c;
    while ((c = getchar()) != EOF) {
        if ('a' <= c && c <= 'z') chars_count[c - 'a']++;
        else if ('A' <= c && c <= 'Z') chars_count[c - 'A']++;
    }

    //calculations
    float coef = (float) HISTOGRAM_HEIGHT / max_value(chars_count, CHARACTERS_COUNT);
    for (int i = 0; i < CHARACTERS_COUNT; i++) chars_count[i] *= coef;

    //output    
    char TITLE[] = "CHARACTER FREQUENCY HISTOGRAM\n";
    printf("%*s", (CHARACTERS_COUNT * BAR_WIDTH + (int) strlen(TITLE)) / 2, TITLE);
    for (int i = HISTOGRAM_HEIGHT; i > 0; i--) {
        for (int j = 0; j < CHARACTERS_COUNT; j++)
            for (int _ = 0; _ < BAR_WIDTH; ++_)
                if (chars_count[j] >= i) putchar('#');
                else putchar(' '); 
        putchar('\n');
            }
    for (int c = 'A'; c <= 'Z'; ++c)
        printf("%*s%c%*s", (BAR_WIDTH - 1) / 2, "", c, (BAR_WIDTH - 1) / 2, "");
    putchar('\n');
    
    return 0; 
    }
    