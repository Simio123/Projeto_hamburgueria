#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "inserir_dados.h"
#include "user_input.h"

bool recebe_idade(int* idade_v)
{
	int controle = 0;

	while (controle == 0)
	{
		char *idade_str = get_user_input("Insira a idade:\t");
		int idade_int = atoi(idade_str);

		if (idade_int <= 0 || idade_int > 150)
		{
			printf("Idade inv�lida\n");
		}
		else
		{
			printf("Idade v�lida: %d\n", idade_int);
			controle = 1;
			*idade_v = idade_int;
		}
	}
	return true;
}

bool recebe_salario(double* salario_v)
{
	int controle = 0;

	while (controle == 0)
	{
		char *salario = get_user_input("Insira o salario:\t");
		double salario_double = atof(salario);

		if (salario_double <= 0)
		{
			printf("Salario invalido\n");
		}
		else
		{
			*salario_v = salario_double;
			controle = 1;
		}
	}
	return true;
}

bool recebe_id(const char* id_v)
{
	int controle = 0;

	while (controle == 0)
	{
		char *id = get_user_input("Insira o ID (max de 11 digitos ou caracteres):\t");
		size_t tamanho = strlen(id);

		if (tamanho <= 0 || tamanho > 11)
		{
			printf("ID invalido\n");
		}
		else
		{
			strcpy((char*)id_v, id);
			controle = 1;
		}
	}
	return true;
}

bool recebe_cargo(const char* cargo_v)
{
	int controle = 0;
	int i;

	while (controle == 0)
	{
		char *cargo = get_user_input("Insira o cargo:\t");
		size_t tamanho = strlen(cargo);

		if (tamanho <= 0)
		{
			printf("Cargo inv�lido\n");
		}
		else
		{
			int cargo_valido = 1; // Suponha que o cargo � v�lido

			for (i = 0; cargo[i] != '\0'; i++)
			{
				char caractere = cargo[i];

				if (!isalpha(caractere) && caractere != ' ')
				{
					cargo_valido = 0;
					break;
				}
			}

			if (cargo_valido)
			{
				printf("Cargo cadastrado com sucesso\n");
				controle = 1;
				strcpy((char*)cargo_v, cargo);
			}
			else
			{
				printf("O cargo � inv�lido, por favor tente novamente\n");
			}
		}
	}
	return true;
}

bool recebe_endereco(const char* endereco_v)
{
	int controle = 0;

	while (controle == 0)
	{
		char *endereco = get_user_input("Insira o endere�o:\t");
		size_t tamanho = strlen(endereco);

		if (tamanho <= 0 || endereco[0] == '\0' || endereco[0] == ' ')
		{
			printf("Endere�o inv�lido. O endere�o n�o pode estar vazio ou conter apenas espa�os em branco.\n");
		}
		else
		{
			printf("Endere�o cadastrado com sucesso!");
			controle = 1;
			strcpy((char*)endereco_v, endereco);
		}
	}
	return true;
}