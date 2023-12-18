#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#elif __linux__
#endif

// Recebe a entrada do usu�rio que suporta at� cinco milh�es de caracteres
// Boa sorte para estourar o buffer
char *get_user_input(char *prompt)
{
	static char input_buf[5000000];
	printf(prompt);
	char *fp = fgets(input_buf, sizeof(input_buf), stdin);
	if (fp == NULL)
	{
		return NULL;
	}

	input_buf[strlen(input_buf) - 1] = '\0';
	return input_buf;
}

// Fun��o que limpa o buffer para evitar quebra de codigo
void limpar_buffer()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

// A fun��o foi feita pra identificar se o programa est� sendo compilado no linux ou no windows
// e com base nisso utiliza as devidas fun��es do sistema para limpar a tela
void limpartela()
{
#ifdef _WIN32
	// C�digo para limpar tela no Windows
	system("cls");
#elif __linux__
	// C�digo para limpar tela no Linux
	system("clear");
#else
	printf("Limpar tela n�o suportado para este sistema operacional.\n");
#endif
}

// A fun��o foi feita pra identificar se o programa est� sendo compilado no linux ou no windows
// e com base nisso utiliza as devidas fun��es do sistema para congelar a tela
void pausarsistema() {
#ifdef _WIN32
    // C�digo para pausar o sistema no Windows
    system("pause");
#elif __linux__
    // C�digo para pausar o sistema no Linux
    printf("Pressione Enter para continuar...");
    getchar();
#else
    printf("Pausa n�o suportada para este sistema operacional.\n");
#endif
}