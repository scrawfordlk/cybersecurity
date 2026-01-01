#include <math.h>
#include <stdio.h>
#include <string.h>

void secret_function() {
  printf("\nYou have reached the secret code!\n");
}

void print_pi(){
  printf("%.4f\n",M_PI);
}

int vulnerable_code(){
  char small_buffer[32];
  char input_buffer[256];
  printf("Enter operation to execute(e.g. pi): ");
  fgets(input_buffer, 256, stdin);
  input_buffer[strcspn(input_buffer, "\n")] = '\0';
  strcpy(small_buffer, input_buffer);
  return strcmp(small_buffer, "pi");
}

int main(int argc, char *argv[]) {
  if (vulnerable_code() == 0) {
    print_pi();
  } else {
    printf("Invalid operation!\n");
  }
  return 0;
}

