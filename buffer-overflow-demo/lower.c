#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void str_to_lowercase(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length; ++i)
        str[i] = tolower(str[i]);
}

void lowercase_print(char *input_str) {
    char unmodified[32];
    strcpy(unmodified, input_str);
    str_to_lowercase(input_str);
    printf("The string '%s' in lowercase is: '%s'\n", unmodified, input_str);
}

void secret_function() {
    printf("\n!!!You have reached the secret code!!!\n");
    system("/bin/sh");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        perror("usage: <program> <input>\n");
        return 1;
    }
    lowercase_print(argv[1]);
}
