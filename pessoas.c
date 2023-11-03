#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "telas.h"

void adicionar_pessoa(int opcao, struct Pilha* pilha)
{
	int ok;
	system("clear||cls");
	printf("*******************************************************************************\n");
	printf("***             = = = = = Menu de cadastro = = = = =                        ***\n");
	printf("*******************************************************************************\n");
	printf("\n");
	printf("Insira o id:\t");
	scanf("%d", &ok);
	printf("ID cadastrado com sucesso\n");
	system("pause");
	desempilhar(pilha);


}
