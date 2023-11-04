#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "telas.h"
#include "validadores.h"
#include "pessoas.h"
#include "inserir_dados.h"

void legenda_funcionario(void)
{
	system("clear||cls");
	printf("*******************************************************************************\n");
	printf("***           = = = = = Menu de cadastro de funcion�rio = = = = =           ***\n");
	printf("*******************************************************************************\n");
}

Pessoa* cadastro_funcionario(struct Pilha * pilha)
{
	Pessoa *funcionario;
	funcionario = (Pessoa*)malloc(sizeof(Pessoa));
	int controle = 0;

	legenda_funcionario();

	do
	{
		if (recebe_cpf()) // Se o CPF for v�lido, entre neste bloco
		{
			legenda_funcionario();

			if (recebe_nome()) // Se nome for v�lido, entre neste bloco
			{
				legenda_funcionario();

				if (recebe_data()) // Se a data for valida, entre neste bloco
				{
					legenda_funcionario();

					printf("Funcion�rio cadastrado com sucesso\n");
					system("pause");
					system("clear||cls");
					controle = 3;
					desempilhar(pilha);
				}
				else
				{
					controle = 0; // A data n�o � v�lida, reiniciamos controle
				}
			}
			else
			{
				controle = 0; // O nome n�o � v�lido, reiniciamos controle
			}
		}
		else
		{
			controle = 0; // O CPF n�o � v�lido, reiniciamos controle
		}
	}
	while (controle != 3);
	return funcionario;
}


