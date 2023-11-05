#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_user_input(char *prompt) {
    static char input_buf[48000];
    printf(prompt);
    char *fp = fgets(input_buf, sizeof(input_buf), stdin);
    if (fp == NULL) {
        return NULL;
    }

    input_buf[strlen(input_buf) - 1] = '\0';
    return input_buf;
}
