#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "telas.h"
#include "validadores.h"
#include "pessoas.h"
#include "inserir_dados.h"
#include "user_input.h"



// ######################################################################################
// ######################################################################################
// ######################################################################################

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
		listagem_funcionarios(pilha);

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
													strncpy(funcionario->id, id_v, 11);
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
	listagem_funcionarios(pilha);

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

void listagem_funcionarios(struct Pilha * pilha)
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
			printf("Status: %d(Ativo)\n", funcionario.status);
			printf("Idade: %d\n", funcionario.idade);
			printf("Salario: %.2f\n", funcionario.salario);
			printf("Id: %s\n", funcionario.id);
			printf("Nome: %s\n", funcionario.nome);
			printf("Cargo: %s\n", funcionario.cargo);
			printf("Endereco: %s\n", funcionario.endereco);
			printf("Email: %s\n", funcionario.email);
			printf("Telefone: %s\n", funcionario.telefone);
			printf("Cpf: %s\n", funcionario.cpf);
			printf("Data de nascimento: %s\n", funcionario.data);
			printf("\n");
		}
	}
	fclose(file);
	system("pause");
	desempilhar(pilha);
}

void listagem_funcionarios_i(struct Pilha * pilha)
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
		if (funcionario.status == 0)
		{
			printf("Status: %d(Inativo)\n", funcionario.status);
			printf("Idade: %d\n", funcionario.idade);
			printf("Salario: %.2f\n", funcionario.salario);
			printf("Id: %s\n", funcionario.id);
			printf("Nome: %s\n", funcionario.nome);
			printf("Cargo: %s\n", funcionario.cargo);
			printf("Endereco: %s\n", funcionario.endereco);
			printf("Email: %s\n", funcionario.email);
			printf("Telefone: %s\n", funcionario.telefone);
			printf("Cpf: %s\n", funcionario.cpf);
			printf("Data de nascimento: %s\n", funcionario.data);
			printf("\n");
		}
	}
	fclose(file);
	system("pause");
	desempilhar(pilha);
}

void editar_dados_funcionarios(struct Pilha * pilha)
{
	int idade_v, tipo = 0, opc_v;
	double salario_v;
	char id_v[11], nome_v[100], cargo_v[100], endereco_v[150], email_v[150], telefone_v[20], cpf_v[12], data_v[11];

	Pessoa funcionario;

	system("clear||cls");
	printf("*******************************************************************************\n");
	printf("***               = = = = = Edição de funcionários = = = = =                ***\n");
	printf("*******************************************************************************\n");

	if(procurar_funcionario(&funcionario))
	{
		do
		{
			system("clear||cls");
			printf("*******************************************************************************\n");
			printf("***               = = = = = Edição de funcionários = = = = =                ***\n");
			printf("*******************************************************************************\n");

			printf("1- Editar idade\n");
			printf("2- Editar salario\n");
			printf("3- Editar id\n");
			printf("4- Editar nome\n");
			printf("5- Editar cargo\n");
			printf("6- Editar endereco\n");
			printf("7- Editar email\n");
			printf("8- Editar telefone\n");
			printf("9- Editar cpf\n");
			printf("10- Editar data de nascimento\n");
			printf("0- Voltar\n");
			printf("\n");

			char *opc = get_user_input("O que deseja fazer?\t");
			opc_v = atoi(opc);
			system("clear||cls");

			switch(opc_v)
			{
			case 1:
				recebe_idade(&idade_v);
				funcionario.idade = idade_v;
				break;

			case 2:
				recebe_salario(&salario_v);
				funcionario.salario = salario_v;
				break;

			case 3:
				recebe_id(id_v, tipo);
				strncpy(funcionario.id, id_v , 11);
				break;

			case 4:
				recebe_nome(nome_v);
				strncpy(funcionario.nome, nome_v, 100);
				break;

			case 5:
				recebe_cargo(cargo_v);
				strncpy(funcionario.cargo, cargo_v, 100);
				break;

			case 6:
				recebe_endereco(endereco_v);
				strncpy(funcionario.endereco, endereco_v, 150);
				break;

			case 7:
				recebe_email(email_v);
				strncpy(funcionario.email, email_v, 150);
				break;

			case 8:
				recebe_telefone(telefone_v);
				strncpy(funcionario.telefone, telefone_v, 20);
				break;

			case 9:
				recebe_cpf(cpf_v);
				strncpy(funcionario.cpf, cpf_v, 12);
				break;

			case 10:
				recebe_data(data_v);
				strncpy(funcionario.data, data_v, 11);
				break;

			case 0:
				desempilhar(pilha);
				system("pause");
				break;

			default:
				printf("Opção inválida.\n");
			}
			printf("Alteração realizada\n");
			system("pause");
		}
		while(opc_v != 0);
		atualizar_funcionario(&funcionario);
	}
	else
	{
		printf("Funcionário não encontrado\n");
		system("pause");
		desempilhar(pilha);
	}
}

void atualizar_funcionario(Pessoa * funcionario)
{
	Pessoa tmp;

	FILE* file = fopen("funcionarios.dat", "r+");

	if (file == NULL)
	{
		printf("Erro ao abrir o arquivo para leitura.\n");
		return;
	}

	while (fread(&tmp, sizeof(Pessoa), 1, file) == 1)
	{
		if (tmp.status == 1 && !strcmp(funcionario->cpf, tmp.cpf))
		{
			fseek(file, -sizeof(Pessoa), SEEK_CUR);
			fwrite(funcionario, sizeof(Pessoa), 1, file);

			fclose(file);
			return;
		}
	}
	fclose(file);
}

bool procurar_funcionario(Pessoa * funcionario)
{
	int controle;
	while ((controle = getchar()) != '\n' && controle != EOF); // Limpar o buffer
	char *cpf_busca = get_user_input("Insira o CPF(somente números): ");

	FILE* file = fopen("funcionarios.dat", "rb");

	if (file == NULL)
	{
		printf("Erro ao abrir o arquivo para leitura.\n");
		return false;
	}

	while (fread(funcionario, sizeof(Pessoa), 1, file) == 1)
	{
		if (funcionario->status == 1 && !strcmp(cpf_busca, funcionario->cpf))
		{
			fclose(file);
			printf("Funcionário encontrado\n");
			system("pause");
			return true;
		}
	}
	return false;
}

// Exclusao
void desabilita_funcionario(struct Pilha * pilha)
{
	char cpf_v[12];
	int controle = 0;
	Pessoa funcionario;

	system("clear||cls");
	printf("*******************************************************************************\n");
	printf("***              = = = = = Exclusão de funcionários = = = = =               ***\n");
	printf("*******************************************************************************\n");

	listagem_funcionarios(pilha);

	recebe_cpf(cpf_v);

	FILE* file = fopen("funcionarios.dat", "rb+");

	if (file == NULL)
	{
		printf("Erro ao abrir o arquivo\n");
		return;
	}

	while (fread(&funcionario, sizeof(Pessoa), 1, file) == 1)
	{
		if (strcmp(funcionario.cpf, cpf_v) == 0)
		{
			funcionario.status = 0;
			fseek(file, -sizeof(Pessoa), SEEK_CUR);
			fwrite(&funcionario, sizeof(Pessoa), 1, file);
			controle = 1;
			break;
		}
	}

	if (!controle)
	{
		printf("\n");
		printf("Funcionário não encontrado.\n");
	}
	else
	{
		printf("\n");
		printf("Funcionário desabilitado com sucesso.\n");
	}
	system("pause");
	fclose(file);
}

// ######################################################################################
// ######################################################################################
// ######################################################################################


void legenda_produto(void)
{
	system("clear||cls");
	printf("*******************************************************************************\n");
	printf("***             = = = = = Menu de cadastro de produtos  = = = = =           ***\n");
	printf("*******************************************************************************\n");
}

Estoque* cadastro_produto(struct Pilha* pilha)
{
	int controle_n;
	while ((controle_n = getchar()) != '\n' && controle_n != EOF); // Limpar o buffer
	Estoque *produto = malloc(sizeof(Estoque));

	int controle = 0, quantidade_v, status_v = 1, tipo = 3;
	double preco_v;
	char id_v[11], nome_v[100], tipo_v[50], data_v[11];

	while (controle != 3)
	{
		legenda_produto();

		if(recebe_nome(nome_v))
		{
			legenda_funcionario();

			if(recebe_tipo(tipo_v))
			{
				legenda_funcionario();

				if(recebe_id(id_v, tipo))
				{
					legenda_funcionario();

					if(recebe_quantidade(&quantidade_v))
					{
						legenda_funcionario();

						if(recebe_data(data_v))
						{
							legenda_funcionario();

							if(recebe_preco(&preco_v))
							{
								legenda_funcionario();

								if (produto != NULL)
								{
									produto->status = status_v;
									produto->quantidade = quantidade_v;
									produto->preco = preco_v;
									strncpy(produto->id, id_v, 11);
									strncpy(produto->nome, nome_v, 100);
									strncpy(produto->validade, data_v, 11);
									strncpy(produto->tipo, tipo_v, 50);

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

	salva_produto(produto);
	free(produto);
	listagem_produtos(pilha);

	printf("Produto cadastrado com sucesso\n");
	system("pause");
	system("clear||cls");
	desempilhar(pilha);

	return produto;
}

void salva_produto(Estoque *produto)
{
	FILE* file = fopen("produtos.dat", "ab");

	if (file == NULL)
	{
		printf("Erro ao abrir o arquivo para escrita.\n");
		return;
	}

	fwrite(produto, sizeof(Estoque), 1, file);
	fclose(file);
}

void listagem_produtos(struct Pilha * pilha)
{
	Estoque produto;
	system("clear||cls");
	printf("*******************************************************************************\n");
	printf("***                = = = = = Listagem de produtos = = = = =                 ***\n");
	printf("*******************************************************************************\n");

	FILE* file = fopen("produtos.dat", "rb");

	if (file == NULL)
	{
		printf("Erro ao abrir o arquivo para leitura.\n");
		return;
	}

	while (fread(&produto, sizeof(Estoque), 1, file) == 1)
	{
		if (produto.status == 1)
		{
			printf("Status: %d (Em estoque)\n", produto.status);
			printf("Quantidade: %d\n", produto.quantidade);
			printf("Preço: %.2f\n", produto.preco);
			printf("Id: %s\n", produto.id);
			printf("Nome: %s\n", produto.nome);
			printf("Data de validade: %s\n", produto.validade);
			printf("Tipo: %s\n", produto.tipo);
			printf("\n");
		}
	}
	fclose(file);
	system("pause");
	desempilhar(pilha);
}

void editar_dados_produtos(struct Pilha * pilha)
{
	int quantidade_v, tipo = 0, opc_v;
	double preco_v;
	char id_v[11], nome_v[100], tipo_v[50], data_v[11];

	Estoque produto;

	system("clear||cls");
	printf("*******************************************************************************\n");
	printf("***                 = = = = = Edição de produtos = = = = =                  ***\n");
	printf("*******************************************************************************\n");

	if(procurar_produto(&produto))
	{
		do
		{
			system("clear||cls");
			printf("*******************************************************************************\n");
			printf("***                 = = = = = Edição de produtos = = = = =                  ***\n");
			printf("*******************************************************************************\n");

			printf("1- Editar quantidade\n");
			printf("2- Editar preço\n");
			printf("3- Editar id\n");
			printf("4- Editar nome\n");
			printf("5- Editar data de validade\n");
			printf("6- Editar tipo\n");
			printf("0- Voltar\n");
			printf("\n");

			int controle_n;
			while ((controle_n = getchar()) != '\n' && controle_n != EOF); // Limpar o buffer

			char *opc = get_user_input("O que deseja fazer?\t");
			opc_v = atoi(opc);
			system("clear||cls");

			switch(opc_v)
			{
			case 1:
				recebe_quantidade(&quantidade_v);
				produto.quantidade = quantidade_v;
				break;

			case 2:
				recebe_preco(&preco_v);
				produto.preco = preco_v;
				break;

			case 3:
				recebe_id(id_v, tipo);
				strncpy(produto.id, id_v , 11);
				break;

			case 4:
				recebe_nome(nome_v);
				strncpy(produto.nome, nome_v, 100);
				break;

			case 5:
				recebe_data(data_v);
				strncpy(produto.validade, data_v, 11);
				break;

			case 6:
				recebe_tipo(tipo_v);
				strncpy(produto.tipo, tipo_v, 50);
				break;

			case 0:
				desempilhar(pilha);
				system("pause");
				break;

			default:
				printf("Opção inválida.\n");
			}
			printf("Alteração realizada\n");
			system("pause");
		}
		while(opc_v != 0);
		atualizar_produto(&produto);
	}
	else
	{
		printf("Produto não encontrado\n");
		system("pause");
		desempilhar(pilha);
	}
}

void atualizar_produto(Estoque * produto)
{
	Estoque pro;

	FILE* file = fopen("funcionarios.dat", "r+");

	if (file == NULL)
	{
		printf("Erro ao abrir o arquivo para leitura.\n");
		return;
	}

	while (fread(&pro, sizeof(Estoque), 1, file) == 1)
	{
		if (pro.status == 1 && !strcmp(produto->nome, pro.nome))
		{
			fseek(file, -sizeof(Estoque), SEEK_CUR);
			fwrite(produto, sizeof(Estoque), 1, file);

			fclose(file);
			return;
		}
	}
	fclose(file);
}

bool procurar_produto(Estoque *produto)
{
	int controle;
	while ((controle = getchar()) != '\n' && controle != EOF); // Limpar o buffer
	char *nome_busca = get_user_input("Insira o nome do produto: ");

	FILE* file = fopen("funcionarios.dat", "rb");

	if (file == NULL)
	{
		printf("Erro ao abrir o arquivo para leitura.\n");
		return false;
	}

	while (fread(produto, sizeof(Estoque), 1, file) == 1)
	{
		if (produto->status == 1 && !strcmp(nome_busca, produto->nome))
		{
			fclose(file);
			printf("Produto encontrado\n");
			system("pause");
			return true;
		}
	}
	return false;
}

// Exclusao
void desabilita_produto(struct Pilha * pilha)
{
	char nome_v[100];
	int controle = 0;
	Estoque produto;

	system("clear||cls");
	printf("*******************************************************************************\n");
	printf("***                = = = = = Exclusão de produtos = = = = =                 ***\n");
	printf("*******************************************************************************\n");

	listagem_produtos(pilha);

	recebe_nome(nome_v);

	FILE* file = fopen("produtos.dat", "rb+");

	if (file == NULL)
	{
		printf("Erro ao abrir o arquivo\n");
		return;
	}

	while (fread(&produto, sizeof(Estoque), 1, file) == 1)
	{
		if (strcmp(produto.nome, nome_v) == 0)
		{
			produto.status = 0;
			fseek(file, -sizeof(Estoque), SEEK_CUR);
			fwrite(&produto, sizeof(Estoque), 1, file);
			controle = 1;
			break;
		}
	}

	if (!controle)
	{
		printf("\n");
		printf("Produto não encontrado.\n");
	}
	else
	{
		printf("\n");
		printf("Produto desabilitado com sucesso.\n");
	}
	system("pause");
	fclose(file);
}



// ######################################################################################
// ######################################################################################
// ######################################################################################

void legenda_pedido(void)
{
	system("clear||cls");
	printf("*******************************************************************************\n");
	printf("***             = = = = = Menu de cadastro de pedidos  = = = = =            ***\n");
	printf("*******************************************************************************\n");
}


