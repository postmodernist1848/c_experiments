/* print a HISTOGRAM of word lengths from the stdandard input*/
#include <stdio.h>
#include <string.h>
#define MAX_WORD_LEN 20
#define HISTOGRAM_HEIGHT 45
#define BAR_WIDTH 3
int main(void){ 
    int lens_count[MAX_WORD_LEN] = {0};
    int c, word_len=0;
    while ((c = getchar()) != EOF) {
        if (c != '\n' && c != ' ' && c != '\t') word_len++;
        else if (1 <= word_len && word_len <= MAX_WORD_LEN) {++lens_count[word_len - 1]; word_len = 0;}
        else if (word_len > MAX_WORD_LEN) {++lens_count[MAX_WORD_LEN - 1]; word_len = 0;}
    }
    char TITLE[] = "WORD LENGTH HISTOGRAM\n";
    printf("%*s", (MAX_WORD_LEN * BAR_WIDTH + (int) strlen(TITLE)) / 2, TITLE);
    for (int i = HISTOGRAM_HEIGHT; i > 0; i--) {
        for (int j = 0; j < MAX_WORD_LEN; j++)
            for (int _ = 0; _ < BAR_WIDTH; ++_)
                if (lens_count[j] >= i) putchar('#');
                else putchar(' '); 
        putchar('\n');
            }
    for (int i = 1; i <= MAX_WORD_LEN; ++i)
        printf("%*d", BAR_WIDTH, i);
    printf(" letters/word\n");
    return 0; 
    }
