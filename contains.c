/* test if string s contains character c */
int contains(char s[], char c) {
    int i = 0;
    while (s[i] != '\0') {
        if (s[i++] == c) return 1;
    }
    return 0;
}

