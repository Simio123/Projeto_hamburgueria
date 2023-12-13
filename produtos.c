#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "telas.h"
#include "validadores.h"
#include "produtos.h"
#include "pessoas.h"
#include "inserir_dados.h"
#include "user_input.h"

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
	while ((controle_n = getchar()) != '\n' && controle_n != EOF);
	Estoque *produto = malloc(sizeof(Estoque));

	int controle = 0, quantidade_v, status_v = 1, tipo = 3;
	double preco_v;
	char id_v[11], nome_v[100], tipo_v[50], data_v[11];

	while (controle != 3)
	{
		legenda_produto();
		printf("Insira o nome do produto(apenas letras):");
		recebe_nome(nome_v);

		legenda_produto();
		printf("Insira o tipo do produto(bebida, entrada, aperitivo):");
		recebe_tipo(tipo_v);

		legenda_produto();
		printf("Insira oid do produto:");
		recebe_id(id_v, tipo);

		legenda_produto();
		printf("Insira a quantidade disponivel do produto:");
		recebe_quantidade(&quantidade_v);

		legenda_produto();
		printf("Insira data de validade do produto:");
		recebe_data(data_v);

		legenda_produto();
		printf("Insira o preco do produto:");
		recebe_preco(&preco_v);

		if (produto != NULL)
		{
			produto->status = status_v;
			produto->quantidade = quantidade_v;
			produto->preco = preco_v;
			strncpy(produto->id, id_v, 17);
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
	salva_produto(produto);

	printf("Produto cadastrado com sucesso\n");
	system("pause");
	system("clear||cls");
	desempilhar(pilha);

	return produto;
	free(produto);
}

void salva_produto(Estoque * produto)
{
	FILE* file = fopen("produtos.dat", "ab");

	if (file == NULL)
	{
		printf("Erro ao abrir o arquivo para escrita.\n");
		return;
		fclose(file);
	}
	else
	{
		fwrite(produto, sizeof(Estoque), 1, file);
		fclose(file);
	}
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
		printf("Erro ao abrir o arquivo para leitura ou nao existem produtos cadastrados\n");
		fclose(file);
		system("pause");
		desempilhar(pilha);
	}
	else
	{
		printf("|***********|************************|*****************|*****************|******************|************|****************|\n");
		printf("|Status     |Nome                    |Data de validade |Tipo             |Quantidade        |Preco       |Id              |\n");

		while (fread(&produto, sizeof(Estoque), 1, file) == 1)
		{
			if (produto.status == 1)
			{
				printf("|************|************************|*****************|*****************|******************|************|****************|\n");
				printf("|Em estoque  |%-24s|%-17s|%-17s|%-18d|%-12.2f|%-16s|\n", produto.nome, produto.validade, produto.tipo, produto.quantidade, produto.preco, produto.id);

			}
		}
		fclose(file);
		system("pause");
		desempilhar(pilha);
	}
}

void listagem_produtos_i(struct Pilha * pilha)
{
	Estoque produto;
	system("clear||cls");
	printf("*******************************************************************************\n");
	printf("***                = = = = = Listagem de produtos = = = = =                 ***\n");
	printf("*******************************************************************************\n");

	FILE* file = fopen("produtos.dat", "rb");

	if (file == NULL)
	{
		printf("Erro ao abrir o arquivo para leitura ou nao existem produtos cadastrados\n");
		fclose(file);
		system("pause");
		desempilhar(pilha);
	}
	else
	{
		printf("|***********|************************|*****************|*****************|******************|************|****************|\n");
		printf("|Status     |Nome                    |Data de validade |Tipo             |Quantidade        |Preco       |Id              |\n");

		while (fread(&produto, sizeof(Estoque), 1, file) == 1)
		{
			if (produto.status == 0)
			{
				printf("|************|************************|*****************|*****************|******************|************|****************|\n");
				printf("|Sem estoque |%-24s|%-17s|%-17s|%-18d|%-12.2f|%-16s|\n", produto.nome, produto.validade, produto.tipo, produto.quantidade, produto.preco, produto.id);

			}
		}
		fclose(file);
		system("pause");
		desempilhar(pilha);
	}
}

void listagem_todos_produtos(struct Pilha * pilha)
{
	Estoque produto;
	system("clear||cls");
	printf("*******************************************************************************\n");
	printf("***                = = = = = Listagem de produtos = = = = =                 ***\n");
	printf("*******************************************************************************\n");

	FILE* file = fopen("produtos.dat", "rb");

	if (file == NULL)
	{
		printf("Erro ao abrir o arquivo para leitura ou nao existem produtos cadastrados\n");
		fclose(file);
		system("pause");
		desempilhar(pilha);
	}
	else
	{
		printf("|************|************************|*****************|*****************|******************|************|****************|\n");
		printf("|Status      |Nome                    |Data de validade |Tipo             |Quantidade        |Preco       |Id              |\n");

		while (fread(&produto, sizeof(Estoque), 1, file) == 1)
		{
			if (produto.status == 1)
			{
				printf("|************|************************|*****************|*****************|******************|************|****************|\n");
				printf("|Em estoque  |%-24s|%-17s|%-17s|%-18d|%-12.2f|%-16s|\n", produto.nome, produto.validade, produto.tipo, produto.quantidade, produto.preco, produto.id);
			}
			else
			{
				printf("|************|************************|*****************|*****************|******************|************|****************|\n");
				printf("|Sem estoque |%-24s|%-17s|%-17s|%-18d|%-12.2f|%-16s|\n", produto.nome, produto.validade, produto.tipo, produto.quantidade, produto.preco, produto.id);

			}
		}
		fclose(file);
		system("pause");
		desempilhar(pilha);
	}
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

	if(procurar_produto(&produto, pilha))
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

			char *opc = get_user_input("O que deseja fazer?\t");
			opc_v = atoi(opc);
			system("clear||cls");

			switch(opc_v)
			{
			case 1:
				printf("Insira a nova quantidade do produto\t");
				recebe_quantidade(&quantidade_v);
				produto.quantidade = quantidade_v;
				break;

			case 2:
				printf("Insira o novo preco do produto\t");
				recebe_preco(&preco_v);
				produto.preco = preco_v;
				break;

			case 3:
				printf("Insira o novo id do produto\t");
				recebe_id(id_v, tipo);
				strncpy(produto.id, id_v , 11);
				break;

			case 4:
				printf("Insira o novo nome do produto\t");
				recebe_nome(nome_v);
				strncpy(produto.nome, nome_v, 100);
				break;

			case 5:
				printf("Insira a nova data de validde do produto\t");
				recebe_data(data_v);
				strncpy(produto.validade, data_v, 11);
				break;

			case 6:
				printf("Insira o novo tipo do produto\t");
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

	FILE* file = fopen("produtos.dat", "r+b");

	if (file == NULL)
	{
		printf("Erro ao abrir o arquivo para leitura.\n");
		fclose(file);
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

bool procurar_produto(Estoque * produto, struct Pilha * pilha)
{
	limpar_buffer();
	char *nome_busca = get_user_input("Insira o nome do produto: ");

	FILE* file = fopen("produtos.dat", "rb");

	if (file == NULL)
	{
		printf("Erro ao abrir o arquivo para leitura.\n");
		return false;
		fclose(file);
		system("pause");
		desempilhar(pilha);
	}
	else
	{
		while (fread(produto, sizeof(Estoque), 1, file) == 1)
		{
			if (produto->status == 1 && !strcmp(nome_busca, produto->nome))
			{
				fclose(file);
				printf("Produto encontrado\n");
				system("pause");
				return true;
				desempilhar(pilha);
			}
		}
	}
	return false;
}

void desabilita_produto(struct Pilha * pilha)
{
	char nome_v[100];
	int controle = 0;
	Estoque produto;

	system("clear||cls");
	printf("*******************************************************************************\n");
	printf("***                = = = = = Exclusão de produtos = = = = =                 ***\n");
	printf("*******************************************************************************\n");

	limpar_buffer();
	printf("Insira o nome do produto que deseja retirar do estoque(apenas numeros):");
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
		printf("Produto retirado do estoque com sucesso.\n");
	}
	system("pause");
	fclose(file);
	desempilhar(pilha);
}

void repoe_produto(struct Pilha * pilha)
{
	char nome_v[100];
	int controle = 0;
	Estoque produto;

	system("clear || cls");
	printf("*******************************************************************************\n");
	printf("***                = = = = = reposicao de estoque = = = = =                 ***\n");
	printf("*******************************************************************************\n");

	limpar_buffer();
	printf("Insira o nome do produto que deseja recolocar no estoque:");
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
			produto.status = 1;
			fseek(file, -sizeof(Estoque), SEEK_CUR);
			fwrite(&produto, sizeof(Estoque), 1, file);
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
		printf("Funcionário readmitido com sucesso.\n");
	}
	system("pause");
	fclose(file);
	desempilhar(pilha);
}