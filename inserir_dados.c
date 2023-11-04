#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "inserir_dados.h"

bool recebe_idade()
{
	int idade;

	printf("Insira a idade:\t");

	if (scanf("%d", &idade) != 1 || idade <= 0 || idade > 150)
	{
		printf("Idade inválida\n");
		return false;
	}
	else
	{
		printf("Idade válida\n");
		return true;
	}
}

bool recebe_salario()
{
	double salario;
	int c;

	printf("Insira o salario:\t");

	if (scanf("%lf", &salario) != 1)
	{
		printf("Salario invalido\n");
		while ((c = getchar()) != '\n' && c != EOF);
		return false;
	}
	else
	{
		printf("Salario valido\n");
		return true;
	}
}

bool recebe_id();
bool recebe_cargo();
bool recebe_endereco();
bool recebe_email();
bool recebe_telefone();



int idade;
double salario;
char id[11];
char nome[100];
char cargo[100];
char endereco[150];
char email[150];
char telefone[20];
char cpf[12];
char data[11];
