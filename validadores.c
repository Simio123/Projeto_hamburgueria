#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "validadores.h"
#include "user_input.h"

// validador de nomes
bool recebe_nome(char* nome_v)
{
	int controle = 0;
	while(controle == 0)
	{
		char *nome = get_user_input("");
		size_t tamanho = strlen(nome);

		if (nome[tamanho - 1] == '\n')
		{
			nome[tamanho - 1] = '\0';
		}

		if (valida_nome(nome))
		{
			controle = 1;
			strcpy((char*)nome_v, nome);
		}
		else
		{
			printf("Entrada invalida, por favor tente novamente\n");
			pausarsistema();
		}
	}
	return true;
}

bool valida_nome(char *nome)
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

// Validador de cpf
bool recebe_cpf(char* cpf_v)
{
	bool cpf_valido;

	do
	{
		char *cpf = get_user_input("");

		cpf_valido = valida_cpf(cpf);

		if (cpf_valido)
		{
			strcpy(cpf_v, cpf);
		}
		else
		{
			printf("Entrada invalida, por favor tente novamente\n");
			pausarsistema();
		}
	}
	while (!cpf_valido);

	return true;
}

bool valida_cpf(char *cpf)
{
	// Verifica o tamanho do CPF
	int i;
	if (strlen(cpf) != 11)
	{
		return false;
	}

	// Verifica se o CPF contém apenas dígitos
	for (i = 0; i < 11; i++)
	{
		if (!isdigit(cpf[i]))
		{
			return false;
		}
	}

	// Converte o CPF para um array de inteiros
	int numeros[11];
	for (i = 0; i < 11; i++)
	{
		numeros[i] = cpf[i] - '0';
	}

	// Calcula o primeiro dígito verificador
	int soma = 0;
	int peso = 10;
	for (i = 0; i < 9; i++)
	{
		soma += numeros[i] * peso;
		peso--;
	}
	int resto = soma % 11;
	int digito1 = (resto < 2) ? 0 : 11 - resto;

	// Verifica o primeiro dígito verificador
	if (digito1 != numeros[9])
	{
		return false;
	}

	// Calcula o segundo dígito verificador
	soma = 0;
	peso = 11;
	for (i = 0; i < 10; i++)
	{
		soma += numeros[i] * peso;
		peso--;
	}
	resto = soma % 11;
	int digito2 = (resto < 2) ? 0 : 11 - resto;

	// Verifica o segundo dígito verificador
	if (digito2 != numeros[10])
	{
		return false;
	}

	// Se todas as verificações passaram, o CPF é válido
	return true;
}

// Validador de datas
bool recebe_data(char* data_v)
{
	char *data = NULL;
	int controle = 0;
	while (controle == 0)
	{
		data = get_user_input("");

		int i;
		bool formato_valido = true;

		for (i = 0; data[i] != '\0'; i++)
		{
			if (!isdigit(data[i]) && data[i] != '/')
			{
				printf("Entrada invalida, por favor tente novamente\n");
				pausarsistema();
				formato_valido = false;
				break;
			}
		}

		if (formato_valido)
		{
			if (valida_data(data))
			{
				controle = 1;
				strcpy((char*)data_v, data);
			}
			else
			{
				printf("Entrada invalida, por favor tente novamente\n");
				pausarsistema();
			}
		}
	}
	return true;
}

bool valida_data(char *data)
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

					if (ano < 0 || ano > 2300 || mes < 1 || mes > 12 || dia < 1 || dia > 31)
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

// Validação e email
bool recebe_email(char* email_v)
{
	int controle = 0;

	while (controle == 0)
	{
		char *email = get_user_input("");
		size_t tamanho = strlen(email);

		if (tamanho <= 0 || email[0] == '\0' || email[0] == ' ' || !valida_email(email))
		{
			printf("Email inválido. O email não pode estar vazio, conter apenas espaços em branco ou não estar em um formato válido.\n");
			pausarsistema();
		}
		else
		{
			controle = 1;
			strcpy((char*)email_v, email);
		}
	}

	return true;
}

bool valida_email(char *email)
{
	int tamanho = strlen(email);
	int contador_arroba = 0;
	int contador_ponto = 0;
	int i;

	for (i = 0; i < tamanho; i++)
	{
		if (email[i] == '@')
		{
			contador_arroba++;
		}
		else if (email[i] == '.')
		{
			contador_ponto++;
		}
	}

	return (contador_arroba == 1 && contador_ponto >= 1);
}

// Validação de telefone
bool recebe_telefone(char* telefone_v)
{
	int controle = 0;

	while (controle == 0)
	{
		char *telefone = get_user_input("");
		size_t tamanho = strlen(telefone);

		if (tamanho != 14 || !valida_telefone(telefone))
		{
			printf("Número de telefone inválido. Certifique-se de que esteja no formato (xx)xxxxx-xxxx.\n");
			pausarsistema();
		}
		else
		{
			controle = 1;
			strcpy((char*)telefone_v, telefone);
		}
	}
	return true;
}

bool valida_telefone(char *telefone)
{
	int tamanho = strlen(telefone);

	if (tamanho != 14 || telefone[0] != '(' || telefone[3] != ')' || telefone[9] != '-')
	{
		return false;
	}
	else if (!isdigit(telefone[1]) || !isdigit(telefone[2]) || !isdigit(telefone[4]) || !isdigit(telefone[5]) || !isdigit(telefone[6]) || !isdigit(telefone[7]) || !isdigit(telefone[8]))
	{
		return false;
	}
	else if(!isdigit(telefone[10]) || !isdigit(telefone[11]) || !isdigit(telefone[12]) || !isdigit(telefone[13]))
	{
		return false;
	}
	return true;
}
