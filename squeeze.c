#include <stdio.h>
#include "contains.h"

/* remove all occurances of characters from s2 in s1 */ 
void squeeze(char s1[], char s2[]) {

    int i, j;
    for (i = j = 0; s1[i] != '\0'; i++)
        if (!contains(s2, s1[i]))
            s1[j++] = s1[i];
    s1[j] = '\0';

}

int main(void) {
    char str1[] = "I like how they do it.";
    char str2[] = " like";
    squeeze(str1, str2);
    puts(str1);

    return 0;
}
