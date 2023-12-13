#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Recebe a entrada do usu�rio que suporta at� meio milh�o de caracteres
// Boa sorte para estourar o buffer
char *get_user_input(char *prompt) {
    static char input_buf[500000];
    printf(prompt);
    char *fp = fgets(input_buf, sizeof(input_buf), stdin);
    if (fp == NULL) {
        return NULL;
    }

    input_buf[strlen(input_buf) - 1] = '\0';
    return input_buf;
}


void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}