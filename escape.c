/* replace some characters with corresponding escape sequences or replace them with these characters */
#include <stdio.h>

/* replace newlines and tabs with \n and \t while copying from s to t */
void escape(char s[], char t[]) {


    int j;
    for (int i=j=0; s[i] != '\0'; i++)
    {
        switch (s[i]) {
            case '\n': { t[j++] = '\\'; t[j++] = 'n'; break; }
            case '\t': { t[j++] = '\\'; t[j++] = 't'; break; }
            default: { t[j++] = s[i]; break; }
        }
    }
}

/* replace escape sequences \n and \t with newlines and tabs while copying from s to t */
void unescape(char s[], char t[]) {

    int j;
    for (int i=j=0; s[i+1] != '\0'; i++) {
        if (s[i] == '\\' && s[i + 1] == 'n') {
            t[j++] = '\n'; i++;
        }
        else if (s[i] == '\\' && s[i + 1] == 't') {
            t[j++] = '\t'; i++;
        }
        else
            t[j++] = s[i];
    }
}

int main (void) {
    char escaped_str[100] = "";
    char string[] = "sick\nhell\tbruh\n";
    escape(string, escaped_str);
    puts(escaped_str);
    char unescaped_str[100];
    unescape(escaped_str, unescaped_str);
    puts(unescaped_str);
    return 0;

}
