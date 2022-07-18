/* remove all occurances of characters from one string in another */ 

#include <stdio.h>

/* test if string s contains character c */
int contains(char s[], char c) {
    int i = 0;
    while (s[i] != '\0') {
        if (s[i++] == c) return 1;
    }
    return 0;
}

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
