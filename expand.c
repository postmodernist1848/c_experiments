#include <stdio.h>
// expands shorthand notations like a-z or 0-3 from s1 into s2
void expand(char s1[], char s2[]) {
    int i, j;
    for (j=0, i=0; s1[i] != '\0'; i++) {
        if (i > 0 && s1[i] == '-' && 
                //lowercase
            ((('a' <= s1[i-1] && s1[i-1] <= 'z') && (s1[i-1] < s1[i+1] && s1[i+1] <= 'z')) ||
                //uppercase
            (('A' <= s1[i-1] && s1[i-1] <= 'Z') && (s1[i-1] < s1[i+1] && s1[i+1] <= 'Z')) ||
                //digits
            (('0' <= s1[i-1] && s1[i-1] <= '9') && (s1[i-1] < s1[i+1] && s1[i+1] <= '9')))) { 
            for (char c = s1[i - 1] + 1; c <= s1[i + 1]; c++)
                s2[j++] = c;
            i++;
        }
        else
            s2[j++] = s1[i];
    }
    s2[j] = '\0';
}

int main (void) {

    char s1[128] = "characters:a-xend check2: a-b-c", s2[128];
    expand(s1, s2);
    printf("`%s` gives:\n%s\n\n", s1, s2);

    char s3[] = "characters:A-Xend check2: A-B-C";
    expand(s3, s2);
    printf("`%s` gives:\n%s\n\n", s3, s2);

    char s4[] = "a-z0-9";
    expand(s4, s2);
    printf("`%s` gives:\n%s\n\n", s4, s2);

    char s5[] = "-a-z-0-2-";
    expand(s5, s2);
    printf("`%s` gives:\n%s\n\n", s5, s2);
    return 0;
}
