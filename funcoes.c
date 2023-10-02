#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "funcoes.h"

void recebe_nome()
{
	char nome[70];

	printf("Insira seu nome: ");
	fgets(nome, sizeof(nome), stdin);

	int tamanho = strlen(nome);
	if (tamanho > 0 && nome[tamanho - 1] == '\n')
	{
		nome[tamanho - 1] = '\0';
	}

	if (valida_nome(nome))
	{
		printf("O nome é válido.\n");
	}
	else
	{
		printf("O nome é inválido.\n");
	}
}

bool valida_nome(const char *nome)
{
	int i;
	if (nome[0] == '\0')
	{
		return false;
	}
	else
	{
		for (i = 0; nome[i] != '\0'; i++)
		{
			char caractere = nome[i];

			if (!isalpha(caractere) && caractere != ' ')
			{
				return false;
			}
		}
		return true;
	}
}

void recebe_cpf()
{
	int i;
	char cpf[12];
	bool controle = true;

	while(controle == true)
	{
		printf("Digite um CPF (somente números):\n");
		scanf("%s", cpf);

		for (i = 0; cpf[i] != '\0'; i++)
		{
			if (!isdigit(cpf[i]))
			{
				printf("Insira apenas numeros\n");
				controle = true;
			}
		}
		controle = false;
	}

	if (valida_cpf(cpf))
	{
		printf("CPF válido!\n");
	}
	else
	{
		printf("CPF inválido!\n");
	}
}

bool valida_cpf(const char *cpf)
{
	int i;
	if (strlen(cpf) != 11)
	{
		return false;
	}
	else
	{
		for (i = 0; i < 11; i++)
		{
			if (!isdigit(cpf[i]))
			{
				return false;
			}
			else
			{
				int numeros[11];
				for (i = 0; i < 11; i++)
				{
					numeros[i] = cpf[i] - '0';
				}

				int soma = 0;
				for (i = 0; i < 9; i++)
				{
					soma += numeros[i] * (10 - i);
				}
				int resto = soma % 11;
				int digito1 = (resto < 2) ? 0 : (11 - resto);

				if (digito1 != numeros[9])
				{
					return false;
				}
				else
				{
					soma = 0;
					for (i = 0; i < 10; i++)
					{
						soma += numeros[i] * (11 - i);
					}
					resto = soma % 11;
					int digito2 = (resto < 2) ? 0 : (11 - resto);

					if (digito2 != numeros[10])
					{
						return false;
					}
				}
			}
		}
	}
	return true;
}

void recebe_data()
{
	int i;
	char data[11];
	bool controle = true;

	while (controle == true)
	{
		printf("Digite a data no formato DD/MM/AAAA:\n");
		scanf("%s", data);

		for (i = 0; data[i] != '\0'; i++)
		{
			if (!isdigit(data[i]) && data[i] != '/')
			{
				printf("Insira apenas numeros e barras\n");
				controle = true;
			}
		}
		controle = false;
	}

	if (valida_data(data))
	{
		printf("A data é válida.\n");
	}
	else
	{
		printf("A data não é válida.\n");
	}

}

bool valida_data(const char *data)
{
	int dia, mes, ano;
	char *token;
	char copiaData[11];
	strcpy(copiaData, data);

	if (strlen(copiaData) != 10)
	{
		return false;
	}
	else
	{
		token = strtok(copiaData, "/");
		if (token == NULL)
		{
			return false;
		}
		else
		{
			dia = atoi(token);
			token = strtok(NULL, "/");

			if (token == NULL)
			{
				return false;
			}
			else
			{
				mes = atoi(token);
				token = strtok(NULL, "/");

				if (token == NULL)
				{
					return false;
				}
				else
				{
					ano = atoi(token);

					if (ano < 0 || mes < 1 || mes > 12 || dia < 1 || dia > 31)
					{
						return false;
					}
					else
					{
						if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30)
						{
							return false;
						}
						else
						{
							if (mes == 2)
							{
								bool bissexto = (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
								if ((bissexto && dia > 29) || (!bissexto && dia > 28))
								{
									return false;
								}
							}
						}
					}
				}
			}
		}
	}
	return true;
}

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

