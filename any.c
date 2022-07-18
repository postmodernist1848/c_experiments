/* find the first occurence of a character in a string */
#include <stdio.h>

/* test if string s contains character c */
int contains(char s[], char c) {
    int i = 0;
    while (s[i] != '\0') {
        if (s[i++] == c) return 1;
    }
    return 0;
}

/* returns the location of the first occurence of any character from s2 in s1. 
 * or -1 if there is none
 */
int any(char s1[], char s2[]) {

    for (int i=0; s1[i] != '\0'; i++) 
        if (contains(s2, s1[i])) return i;
    return -1;

}

int main(void) {

    char s1[] = "Hello, World!";
    char s2[] = "WH";

    printf("%d", any(s1, s2));


    return 0;

}
