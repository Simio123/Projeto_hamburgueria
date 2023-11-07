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

	int controle = 0, idade_v, status_v = 1, tipo = 0;
	double salario_v;
	char id_v[11], nome_v[100], cargo_v[100], endereco_v[150], email_v[150], telefone_v[20], cpf_v[12], data_v[11];
	while (controle != 3)
	{
		legenda_funcionario();
		listagem_funcionarios();

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

							if(recebe_id(id_v, tipo))
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
													strncpy(funcionario->id, id_v, 15);
													strncpy(funcionario->nome, nome_v, 100);
													strncpy(funcionario->cargo, cargo_v, 100);
													strncpy(funcionario->endereco, endereco_v, 150);
													strncpy(funcionario->email, email_v, 150);
													strncpy(funcionario->telefone, telefone_v, 20);
													strncpy(funcionario->cpf, cpf_v, 12);
													strncpy(funcionario->data, data_v, 11);

													controle = 3;
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

	salva_funcionario(funcionario);
	free(funcionario);
	listagem_funcionarios();

	printf("Funcionário cadastrado com sucesso\n");
	system("pause");
	system("clear||cls");
	desempilhar(pilha);

	return funcionario;
}


void salva_funcionario(Pessoa *funcionario)
{
	FILE* file = fopen("funcionarios.dat", "ab");

	if (file == NULL)
	{
		printf("Erro ao abrir o arquivo para escrita.\n");
		return;
	}

	fwrite(funcionario, sizeof(Pessoa), 1, file);
	fclose(file);
}

void listagem_funcionarios(void)
{
	Pessoa funcionario;
	system("clear||cls");
	printf("*******************************************************************************\n");
	printf("***              = = = = = Listagem de funcionários = = = = =               ***\n");
	printf("*******************************************************************************\n");

	FILE* file = fopen("funcionarios.dat", "rb");

	if (file == NULL)
	{
		printf("Erro ao abrir o arquivo para leitura.\n");
		return;
	}

	while (fread(&funcionario, sizeof(Pessoa), 1, file) == 1)
	{
		if (funcionario.status == 1)
		{
			printf("Status: %d\n", funcionario.status);
			printf("Idade: %d\n", funcionario.idade);
			printf("Salario: %.2f\n", funcionario.salario);
			printf("Id: %s\n", funcionario.id);
			printf("Nome: %s\n", funcionario.nome);
			printf("Cargo: %s\n", funcionario.cargo);
			printf("Endereco: %s\n", funcionario.endereco);
			printf("Email: %s\n", funcionario.email);
			printf("Telefone: %s\n", funcionario.telefone);
			printf("Funcionario->cpf: %s\n", funcionario.cpf);
			printf("Funcionario->data: %s\n", funcionario.data);
		}
	}
	fclose(file);
}

