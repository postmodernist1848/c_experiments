#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long htoi(char * hex) {
    int i;
    long res = 0;
    if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X'))
        i = 2;
    else
        i = 0;

    while (hex[i] != '\0') {
        int digit_value;
        if ('0' <= hex[i] && hex[i] <= '9')
            digit_value = hex[i] - '0';
        else
        if ('A' <= hex[i] && hex[i] <= 'F')
            digit_value = hex[i] - 'A' + 10;
        else
        if ('a' <= hex[i] && hex[i] <= 'f')
            digit_value = hex[i] - 'a' + 10;
        else {
            fprintf(stderr, "Error: wrong symbol \'%c\'", hex[i]);
            exit(1);
        }   
        res = res * 16 + digit_value;
        ++i;
        }
    return res;
    }

int main(void) {
    
    char hex_string1488[] = "0x5d0";
    char hex_string1311768462882491887[] = "1234567789ABCDEF";
    char hex_string418762[] = "0X663ca";

    printf("This is supposed to be 1488: %ld\n", htoi(hex_string1488));
    printf("This is supposed to be 1311768462882491887: %ld\n", htoi(hex_string1311768462882491887));
    printf("This is supposed to be 418762: %ld\n", htoi(hex_string418762));

    return 0;

}
