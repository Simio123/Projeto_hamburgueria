#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "validadores.h"

// validador de nomes
bool recebe_nome()
{
	char nome[100];

	printf("Insira o nome:\t");
	fgets(nome, sizeof(nome), stdin);

	// Remove a quebra de linha caso ela exista
	size_t tamanho = strlen(nome);
	if (nome[tamanho - 1] == '\n')
	{
		nome[tamanho - 1] = '\0';
	}

	if (nome[0] == '\0')
	{
		printf("O nome é inválido, por favor tente novamente\n");
		return false;
	}

	if (valida_nome(nome))
	{
		printf("Nome cadastrado com sucesso\n");
		return true;
	}
	else
	{
		printf("O nome é inválido, por favor tente novamente\n");
		return false;
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


// Validador de cpfs
bool recebe_cpf()
{
    char cpf[12];
    bool cpf_valido;

    do {
        printf("Digite um CPF (somente números):\n");
        fgets(cpf, sizeof(cpf), stdin);
        getchar();

        cpf_valido = valida_cpf(cpf);

        if (cpf_valido) {
            printf("CPF válido!\n");
        } else {
            printf("CPF inválido! Tente novamente.\n");
        }
    } while (!cpf_valido);

    return true;
}

bool valida_cpf(const char *cpf) {
    // Verifica o tamanho do CPF
    int i;
    if (strlen(cpf) != 11) {
        return false;
    }

    // Verifica se o CPF contém apenas dígitos
    for (i = 0; i < 11; i++) {
        if (!isdigit(cpf[i])) {
            return false;
        }
    }

    // Converte o CPF para um array de inteiros
    int numeros[11];
    for (i = 0; i < 11; i++) {
        numeros[i] = cpf[i] - '0';
    }

    // Calcula o primeiro dígito verificador
    int soma = 0;
    int peso = 10;
    for (i = 0; i < 9; i++) {
        soma += numeros[i] * peso;
        peso--;
    }
    int resto = soma % 11;
    int digito1 = (resto < 2) ? 0 : 11 - resto;

    // Verifica o primeiro dígito verificador
    if (digito1 != numeros[9]) {
        return false;
    }

    // Calcula o segundo dígito verificador
    soma = 0;
    peso = 11;
    for (i = 0; i < 10; i++) {
        soma += numeros[i] * peso;
        peso--;
    }
    resto = soma % 11;
    int digito2 = (resto < 2) ? 0 : 11 - resto;

    // Verifica o segundo dígito verificador
    if (digito2 != numeros[10]) {
        return false;
    }

    // Se todas as verificações passaram, o CPF é válido
    return true;
}



// Validador de datas
bool recebe_data()
{
	int i;
	char data[11];
	bool controle = true;

	while (controle == true)
	{
		printf("Digite a data no formato DD/MM/AAAA:\n");
		fgets(data, sizeof(data), stdin);

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
		return true;
	}
	else
	{
		printf("A data não é válida, insira novamente\n");
		return false;
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

