#include <stdio.h>
#include <string.h>
#include <ctype.h>

void secret_function() {
  printf("\nYou have reached the secret code!\n");
}

void str_to_lowercase(char* buf){
  int length = strlen(buf);
  for (int i = 0; i < length; ++i) {
    buf[i] = tolower(buf[i]);
  }
}

void vulnerable_code(){
  char small_buffer[32];
  char input_buffer[256];
  printf("Enter String to convert to lowercase: ");
  fgets(input_buffer, 256, stdin);
  input_buffer[strcspn(input_buffer, "\n")] = '\0';
  strcpy(small_buffer, input_buffer);
  str_to_lowercase(small_buffer);
  printf("The string '%s' in lowercase is: '%s'\n",input_buffer,small_buffer);
}

int main(int argc, char *argv[]) {
  vulnerable_code();
  return 0;
}

