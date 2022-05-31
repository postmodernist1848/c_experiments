#include <stdio.h>

int main(void){ 
  printf("Size of char: %zu\n", sizeof(char));
  printf("Size of short: %zu\n", sizeof(short));
  printf("Size of int: %zu\n", sizeof(int));
  printf("Size of long: %zu\n", sizeof(long));
  char c_c = EOF;
  int c_i = EOF;
  printf("EOF = %d\n", EOF);
  printf("char c_c == EOF is %d\n", c_c == EOF);
  printf("char c_i == EOF is %d\n", c_i == EOF);

  char c;
  while ((c = getchar()) != EOF)
    printf("scanned character\n");
  return 0; 
  }