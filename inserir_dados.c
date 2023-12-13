#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "inserir_dados.h"
#include "user_input.h"

bool recebe_salario(double* salario_v)
{
	int controle = 0;

	while (controle == 0)
	{
		char *salario = get_user_input("");
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

bool recebe_id(char* id_v, int tipo)
{
	int controle = 0;
	char str1[10];
	char resultado[15];

	switch (tipo)
	{
	case 0:
		strcpy(str1, "FUN-");
		break;
	case 1:
		strcpy(str1, "CLI-");
		break;
	case 2:
		strcpy(str1, "PED-");
		break;
	case 3:
		strcpy(str1, "PRO-");
		break;
	default:
		printf("Tipo inválido\n");
		return false;
	}

	while (controle == 0)
	{
		char* id = get_user_input("");
		size_t tamanho = strlen(id);

		if (tamanho <= 0 || tamanho > 11)
		{
			printf("ID inválido\n");
		}
		else
		{
			strcpy(resultado, str1);
			strcat(resultado, id);
			strcpy((char*)id_v, resultado);
			controle = 1;
		}
	}

	return true;
}

bool recebe_cargo(char* cargo_v)
{
	int controle = 0, i;

	while (controle == 0)
	{
		char *cargo = get_user_input("");
		size_t tamanho = strlen(cargo);

		if (tamanho <= 1)
		{
			printf("Cargo inválido\n");
		}
		else
		{
			int cargo_valido = 1;

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
				printf("O cargo é inválido, por favor tente novamente\n");
			}
		}
	}
	return true;
}

bool recebe_endereco(char* endereco_v)
{
	int controle = 0;

	while (controle == 0)
	{
		char *endereco = get_user_input("");
		size_t tamanho = strlen(endereco);

		if (tamanho <= 0 || endereco[0] == '\0' || endereco[0] == ' ')
		{
			printf("Endereço inválido. O endereço não pode estar vazio ou conter apenas espaços em branco.\n");
		}
		else
		{
			printf("Endereço cadastrado com sucesso!");
			controle = 1;
			strcpy((char*)endereco_v, endereco);
		}
	}
	return true;
}

bool recebe_preco(double* preco_v)
{
	int controle = 0;

	while (controle == 0)
	{
		char *preco = get_user_input("");
		double preco_double = atof(preco);

		if (preco_double <= 0)
		{
			printf("Preco invalido\n");
		}
		else
		{
			*preco_v = preco_double;
			controle = 1;
		}
	}
	return true;
}

bool recebe_tipo(char* tipo_v)
{
	int controle = 0, i;

	while (controle == 0)
	{
		char *tipo = get_user_input("");
		size_t tamanho = strlen(tipo);

		if (tamanho <= 0)
		{
			printf("Tipo inválido\n");
		}
		else
		{
			int tipo_valido = 1;

			for (i = 0; tipo[i] != '\0'; i++)
			{
				char caractere = tipo[i];

				if (!isalpha(caractere) && caractere != ' ')
				{
					tipo_valido = 0;
					break;
				}
			}

			if (tipo_valido)
			{
				printf("Tipo cadastrado com sucesso\n");
				controle = 1;
				strcpy((char*)tipo_v, tipo);
			}
			else
			{
				printf("O tipo é inválido, por favor tente novamente\n");
			}
		}
	}
	return true;
}

bool recebe_quantidade(int* quantidade_v)
{
	int controle = 0;

	while (controle == 0)
	{
		char *quantidade_str = get_user_input("");
		int quantidade_int = atoi(quantidade_str);

		if (quantidade_int <= 0)
		{
			printf("Quantidade inválida\n");
		}
		else
		{
			controle = 1;
			*quantidade_v = quantidade_int;
		}
	}
	return true;
}