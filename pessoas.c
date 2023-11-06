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

	int controle = 0, idade_v, status_v = 1;
	double salario_v;
	char id_v[11], nome_v[100], cargo_v[100], endereco_v[150], email_v[150], telefone_v[20], cpf_v[12], data_v[11];

	while (controle != 3)
	{
		legenda_funcionario();

		if (recebe_cpf(cpf_v))
		{
			legenda_funcionario();

			if (recebe_nome(nome_v))
			{
				legenda_funcionario();

				if (recebe_data(data_v))
				{
					legenda_funcionario();

					if(recebe_idade(&idade_v))
					{
						legenda_funcionario();

						if(recebe_salario(&salario_v))
						{
							legenda_funcionario();

							if(recebe_id(id_v))
							{
								legenda_funcionario();

								if(recebe_cargo(cargo_v))
								{
									legenda_funcionario();

									if(recebe_email(email_v))
									{
										legenda_funcionario();

										if(recebe_telefone(telefone_v))
										{
											legenda_funcionario();

											if(recebe_endereco(endereco_v))
											{
												legenda_funcionario();

												if (funcionario != NULL)
												{
													funcionario->status = status_v;
													funcionario->idade = idade_v;
													funcionario->salario = salario_v;
													strncpy(funcionario->id, id_v, 11);
													strncpy(funcionario->nome, nome_v, 100);
													strncpy(funcionario->cargo, cargo_v, 100);
													strncpy(funcionario->endereco, endereco_v, 150);
													strncpy(funcionario->email, email_v, 150);
													strncpy(funcionario->telefone, telefone_v, 20);
													strncpy(funcionario->cpf, cpf_v, 12);
													strncpy(funcionario->data, data_v, 11);

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
	}
	return funcionario;
}




