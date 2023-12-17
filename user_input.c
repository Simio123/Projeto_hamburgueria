#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#elif __linux__
#endif

// Recebe a entrada do usuário que suporta até meio milhão de caracteres
// Boa sorte para estourar o buffer
char *get_user_input(char *prompt)
{
	static char input_buf[500000];
	printf(prompt);
	char *fp = fgets(input_buf, sizeof(input_buf), stdin);
	if (fp == NULL)
	{
		return NULL;
	}

	input_buf[strlen(input_buf) - 1] = '\0';
	return input_buf;
}

void limpar_buffer()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void limpartela()
{
#ifdef _WIN32
	// Código para limpar tela no Windows
	system("cls");
#elif __linux__
	// Código para limpar tela no Linux
	system("clear");
#else
	// Código para outros sistemas operacionais (se necessário)
	printf("Limpar tela não suportado para este sistema operacional.\n");
#endif
}

void pausarsistema() {
#ifdef _WIN32
    // Código para pausar o sistema no Windows
    system("pause");
#elif __linux__
    // Código para pausar o sistema no Linux
    printf("Pressione Enter para continuar...");
    getchar();
#else
    // Código para outros sistemas operacionais (se necessário)
    printf("Pausa não suportada para este sistema operacional.\n");
#endif
}