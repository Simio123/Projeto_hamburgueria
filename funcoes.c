#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int login()
{
	char usuario[50];
	char senha[50];

	printf("Digite o login: ");
	scanf("%s", usuario);

	printf("Digite a senha: ");
	scanf("%s", senha);

	// verificação do login e senha
	if (strcmp(usuario, "sim") == 0 && strcmp(senha, "123") == 0)
	{
		printf("Login bem-sucedido!\n");
		system("PAUSE");
		return 1;
	}
	else
	{
		printf("Login ou senha incorretos.\n");
		system("PAUSE");
		return 0;
	}
}
