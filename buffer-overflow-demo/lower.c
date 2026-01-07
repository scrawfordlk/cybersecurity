#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void str_to_lowercase(char *str);
void vulnerable_code(char *input_str);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    perror("usage: <program> <input>\n");
    return 1;
  }

  vulnerable_code(argv[1]);
}

void vulnerable_code(char *input_str) {
  char small_buffer[32];
  strcpy(small_buffer, input_str);
  str_to_lowercase(input_str);
  printf("The string '%s' in lowercase is: '%s'\n", small_buffer, input_str);
}

void str_to_lowercase(char *str) {
  int length = strlen(str);
  for (int i = 0; i < length; ++i) {
    str[i] = tolower(str[i]);
  }
}

void secret_function() {
  printf("\n!!!You have reached the secret code!!!\n");
  system("/bin/sh");
}
