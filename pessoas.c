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
	Pessoa *funcionario = malloc(sizeof(Pessoa));

	int controle = 0, idade, status;
	double salario;
	char id[11], nome[100], cargo[100], endereco[150], email[150], telefone[20], cpf[12], data[11];

	legenda_funcionario();

	while (controle != 3)
	{
		recebe_telefone();
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

									if(recebe_email())
									{
										legenda_funcionario();

										if(recebe_telefone())
										{
											legenda_funcionario();

											if (funcionario != NULL)
											{
												funcionario->idade = idade;
												funcionario->salario = salario;
												strncpy(funcionario->id, id, 11);
												strncpy(funcionario->nome, nome, 100);
												strncpy(funcionario->cargo, cargo, 100);
												strncpy(funcionario->endereco, endereco, 150);
												strncpy(funcionario->email, email, 150);
												strncpy(funcionario->telefone, telefone, 20);
												strncpy(funcionario->cpf, cpf, 12);
												strncpy(funcionario->data, data, 11);
												funcionario->status = status;

												printf("Funcionário cadastrado com sucesso\n");
												system("pause");
												system("clear||cls");
												controle = 3;
												desempilhar(pilha);
											}
											else
											{
												printf("Falha na alocação de memória\n");
											}

										}

									}
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




