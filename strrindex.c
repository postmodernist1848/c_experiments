/* find the rightmost occurence of a string in another string */
#include <stdio.h>
#include <string.h>

/* returns an index of the rightmost occurence of t in s */
int strrindex(char s[], char t[]) {

    int i, j, k;
    for (i=strlen(s) - strlen(t); i >= 0; i--) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
        return -1;
}

int main (void) {

    char s[] = "strhuhinghuh";
    char t[] = "huh";
    printf("%d\n", strrindex(s, t));

    return 0;
}
