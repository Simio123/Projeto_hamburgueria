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
	printf("***           = = = = = Menu de cadastro de funcionário = = = = =           ***\n");
	printf("*******************************************************************************\n");
}

Pessoa* cadastro_funcionario(struct Pilha * pilha)
{
	Pessoa *funcionario = malloc(sizeof(Pessoa)); ;
	int controle = 0;

	legenda_funcionario();

	while (controle != 3)
	{
		if (recebe_cpf())
		{
			legenda_funcionario();

			if (recebe_nome())
			{
				legenda_funcionario();

				if (recebe_data())
				{
					legenda_funcionario();

					if(recebe_idade())
					{
						legenda_funcionario();

						if(recebe_salario())
						{
							legenda_funcionario();

							if(recebe_id())
							{
								legenda_funcionario();

								if(recebe_cargo())
								{
									legenda_funcionario();
									printf("Funcionário cadastrado com sucesso\n");
									system("pause");
									system("clear||cls");
									controle = 3;
									desempilhar(pilha);
								}
							}
						}
					}
				}
			}
		}
	}
	return funcionario;
}



