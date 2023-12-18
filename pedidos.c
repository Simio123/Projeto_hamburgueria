#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "telas.h"
#include "produtos.h"
#include "validadores.h"
#include "pessoas.h"
#include "inserir_dados.h"
#include "user_input.h"
#include "pedidos.h"

void legenda_pedido(void)
{
	limpartela();
	printf("*******************************************************************************\n");
	printf("***                 = = = = = Cadastro de Pedidos = = = = =                 ***\n");
	printf("*******************************************************************************\n");
}


//Essa função realiza o cadastro de um novo pedido, coletando
// informações sobre produtos, cliente e comanda, e salva essas informações
// em uma estrutura de dados.
Pedidos* cadastro_pedido(Estoque *produto, struct Pilha * pilha)
{
	Pedidos *pedido = calloc(1, sizeof(Pedidos));
	limpar_buffer();
	time_t t;
	time(&t);

	double preco_t, preco_u;
	int controle = 0, tipo = 3, tipo2 = 2, quantidade_v, n_pedidos = 0, controle2 = 0, controle3 = 0, controle4 = 0, controle5 = 0;
	char id_v[17], nome_v[100], cpf_v[12], data_pedido_v[11], hora_pedido_v[9];

	// Pega do sistema automaticamente a hora e a data atuais
	strftime(hora_pedido_v, sizeof(hora_pedido_v), "%H:%M:%S", localtime(&t));
	strftime(data_pedido_v, sizeof(data_pedido_v), "%d/%m/%Y", localtime(&t));

	legenda_pedido();
	while (controle != 3)
	{
		do
		{
			do
			{
				printf("Insira id do produto %d:", n_pedidos + 1);
				recebe_id(id_v, tipo);

				if(produto_com_id_existente(id_v))
				{

					strncpy(pedido->item_pedido[n_pedidos], id_v, 17);
					controle3 = 1;
				}
				else
				{
					printf("Nao existem produtos cadastrados com esse id, por favor insira um ID diferente.\n");
					pausarsistema();
				}
			}
			while(controle3 != 1);


			// Aqui está minha versão simia de um carrinho de compras utiliando uma matriz
			// dentro da struct
			// Obviamente seria mais prático criar um array de structs dentro da struct
			// porém a preguiça de mudar é grande e a burrice pra fazer assim foi muita
			do
			{
				legenda_pedido();
				printf("Insira a quantidade do produto %d:", n_pedidos + 1);
				recebe_quantidade(&quantidade_v);

				if(pedido_com_quantidade_existente(id_v, quantidade_v, &preco_t, &preco_u))
				{
					pedido->quantidade_pedido[n_pedidos] = quantidade_v;
					pedido->val_ped[n_pedidos] = preco_u;
					pedido->valor_pedido += preco_t;
					controle4 = 1;
				}
				else
				{
					printf("A quantidade de produtos e insuficiente, por favor insira um numero diferente.\n");
					pausarsistema();
				}
			}
			while(controle4 != 1);

			char *resposta = get_user_input("Deseja adicionar mais algum produto ao seu pedido?(insira s em caso afirmativo)\t");
			if(strcmp(resposta, "s") == 0)
			{
				controle = 0;
				n_pedidos += 1;
			}
			else
			{
				controle2 = 1;
			}
		}
		while (controle2 != 1);

		legenda_pedido();
		printf("Insira seu nome(apenas letras):");
		recebe_nome(nome_v);

		legenda_pedido();
		printf("Insira seu cpf(apenas numeros):");
		recebe_cpf(cpf_v);

		do
		{
			printf("Insira id da sua comanda :");
			recebe_id(id_v, tipo2);

			if(!pedido_com_id_existente(id_v))
			{
				strncpy(pedido->id, id_v, 17);
				controle5 = 1;
			}
			else
			{
				printf("Já existe uma comanda com esse id, por favor insira um ID diferente.\n");
				pausarsistema();
			}
		}
		while(controle5 != 1);

		if (pedido != NULL)
		{
			pedido->status = 1;
			pedido->n_ped = n_pedidos;

			strncpy(pedido->hora_pedido, hora_pedido_v, 9);
			strncpy(pedido->data_pedido, data_pedido_v, 11);
			strncpy(pedido->nome_cliente, nome_v, 100);
			strncpy(pedido->cpf_cliente, cpf_v, 12);

			controle = 3;
		}
		else
		{
			printf("Falha na alocação de memória\n");
		}
	}
	salva_pedido(pedido);

	printf("Pedido registrado com sucesso\n");
	pausarsistema();
	limpartela();
	desempilhar(pilha);

	return pedido;
}

void salva_pedido(Pedidos * pedido)
{
	FILE* file = fopen("pedidos.dat", "ab");

	if (file == NULL)
	{
		printf("Erro ao abrir o arquivo para escrita.\n");
		return;
		fclose(file);
	}
	else
	{
		fwrite(pedido, sizeof(Pedidos), 1, file);
		fclose(file);
	}
}

void pedidos_por_hora(Pedidos vetor[], int tamanho)
{
	int i, j;
	Pedidos temp;

	for (i = 0; i < tamanho - 1; i++)
	{
		for (j = 0; j < tamanho - 1 - i; j++)
		{
			if (strcmp(vetor[j].hora_pedido, vetor[j + 1].hora_pedido) > 0)
			{
				temp = vetor[j];
				vetor[j] = vetor[j + 1];
				vetor[j + 1] = temp;
			}
		}
	}
}

// Essa função exibe os pedidos que estão em aberto
// Ela lê os pedidos de um arquivo binário, seleciona aqueles que
// estão em aberto, exibe suas informações por ordem de horario dos pedidos
// do mais antigo para o mais novo
void exibe_pedidos(struct Pilha* pilha)
{
	int i, j;
	Pedidos ped;
	Pedidos vetorPedidos[100];

	limpartela();
	printf("*******************************************************************************\n");
	printf("***                   = = = = = Menu de Pedidos = = = = =                   ***\n");
	printf("*******************************************************************************\n");

	FILE* file = fopen("pedidos.dat", "rb");

	if (file == NULL)
	{
		printf("Erro ao abrir o arquivo para leitura ou não existem pedidos\n");
		fclose(file);
		pausarsistema();
		desempilhar(pilha);
	}
	else
	{
		int numPedidos = 0;

		while (fread(&ped, sizeof(Pedidos), 1, file) == 1)
		{
			if (ped.status == 1)
			{
				vetorPedidos[numPedidos] = ped;
				numPedidos++;
			}
		}

		pedidos_por_hora(vetorPedidos, numPedidos);

		for (i = 0; i < numPedidos; i++)
		{
			printf("\n                     __________________________________                         \n");
			printf("*********************|      Comanda %-17s |************************\n", vetorPedidos[i].id);
			printf("|*********|*********|***********|*****************************|***************|\n");
			printf("|Status   |Hora     |Data       |Nome do cliente              |Cpf do cliente |\n");
			printf("|Em aberto|%s |%s |%-28s |%-14s |\n", vetorPedidos[i].hora_pedido, vetorPedidos[i].data_pedido,
				   vetorPedidos[i].nome_cliente, vetorPedidos[i].cpf_cliente);
			printf("*******************************************************************************\n");
			printf("|Id do produto                |Quantidade            |preco unitario          |\n");
			for ( j = 0; j <= vetorPedidos[i].n_ped; j++)
			{
				printf("|%-28s |%-22d|  %-21.2f |\n", vetorPedidos[i].item_pedido[j], vetorPedidos[i].quantidade_pedido[j],
					   vetorPedidos[i].val_ped[j]);
			}
			printf("********************************************************************************\n");
			printf("|                                  |valor total |                              |\n");
			printf("|                                  |%-6.2f      |                              |\n",
				   vetorPedidos[i].valor_pedido);
			printf("********************************************************************************\n");
		}

		fclose(file);
		pausarsistema();
		desempilhar(pilha);
	}
}

// Exibe os pedidos que já foram finalizados
void exibe_pedidos_f(struct Pilha * pilha)
{
	int i;
	Pedidos ped;

	limpartela();
	printf("*******************************************************************************\n");
	printf("***                   = = = = = Menu de Pedidos = = = = =                   ***\n");
	printf("*******************************************************************************\n");

	FILE* file = fopen("pedidos.dat", "rb");

	if (file == NULL)
	{
		printf("Erro ao abrir o arquivo para leitura ou não existem pedidos\n");
		fclose(file);
		pausarsistema();
		desempilhar(pilha);
	}
	else
	{
		while (fread(&ped, sizeof(Pedidos), 1, file) == 1)
		{
			if(ped.status == 0)
			{
				printf("\n                     __________________________________                         \n");
				printf("**********************|      Comanda %-17s |************************\n", ped.id);
				printf("|**********|*********|***********|*****************************|***************|\n");
				printf("|Status    |Hora     |Data       |Nome do cliente              |Cpf do cliente |\n");
				printf("|Finalizado|%s |%s |%-28s |%-14s |\n", ped.hora_pedido, ped.data_pedido, ped.nome_cliente, ped.cpf_cliente);
				printf("*******************************************************************************\n");
			}
			printf("|Id do produto                |Quantidade            |preco unitario          |\n");
			for (i = 0; i <= ped.n_ped; i++)
			{
				printf("|%-28s |%-22d|  %-21.2f |\n", ped.item_pedido[i], ped.quantidade_pedido[i], ped.val_ped[i]);
			}
			printf("*******************************************************************************\n");
			printf("|                                  |valor total |                             |\n");
			printf("|                                  |%-6.2f      |                             |\n", ped.valor_pedido);
			printf("*******************************************************************************\n");
		}
		fclose(file);
		pausarsistema();
		desempilhar(pilha);
	}
}

void finaliza_pedido(struct Pilha * pilha)
{
	char id_v[17];
	int controle  = 0, controle2 = 0, tipo2 = 2;
	Pedidos ped;

	limpartela();
	printf("*******************************************************************************\n");
	printf("***               = = = = = Finalização de pedidos = = = = =                ***\n");
	printf("*******************************************************************************\n");

	limpar_buffer();
	FILE* file2 = fopen("pedidos.dat", "rb+");

	if (file2 == NULL)
	{
		printf("Erro ao abrir o arquivo\n");
		fclose(file2);
		pausarsistema();
		desempilhar(pilha);
		return;
	}
	do
	{
		printf("Insira id da comanda:");
		recebe_id(id_v, tipo2);

		if(pedido_com_id_existente(id_v))
		{
			controle2 = 1;
		}
		else
		{
			printf("Comanda não encontrada, tente novamente\n");
		}
	}
	while(controle2 != 1);

	while (fread(&ped, sizeof(Pedidos), 1, file2) == 1)
	{
		if (strcmp(ped.id, id_v) == 0 && ped.status == 1)
		{
			ped.status = 0;
			fseek(file2, -sizeof(Pedidos), SEEK_CUR);
			fwrite(&ped, sizeof(Pedidos), 1, file2);
			controle = 1;
			break;
		}
	}
	desempilhar(pilha);
}

// Verifica se a quantidade no estoque é suficiente para cobrir a requisição do pedido
bool pedido_com_quantidade_existente(char *id, int quantidade, double *preco_t, double *preco_u)
{
	FILE *file = fopen("produtos.dat", "rb");

	if (file == NULL)
	{
		printf("Erro ao abrir o arquivo para leitura.\n");
		return false;
	}

	Estoque produto_atual;

	while (fread(&produto_atual, sizeof(Estoque), 1, file) == 1)
	{
		if (strcmp(produto_atual.id, id) == 0)
		{
			if (quantidade <= produto_atual.quantidade)
			{
				*preco_u = produto_atual.preco;
				*preco_t = quantidade * produto_atual.preco;
				fclose(file);

				return true;
			}
			else
			{
				fclose(file);
				return false;
			}
		}
	}

	fclose(file);
	return false;
}

// Impede o cadastramento do mesmo id para duas comandas
bool pedido_com_id_existente(char* id)
{
	FILE* file = fopen("pedidos.dat", "rb");

	if (file == NULL)
	{
		printf("Erro ao abrir o arquivo para leitura.\n");
		return false;
	}

	Pedidos pedido_atual;

	while (fread(&pedido_atual, sizeof(Pedidos), 1, file) == 1)
	{
		if (strcmp(pedido_atual.id, id) == 0)
		{
			fclose(file);
			return true;
		}
	}
	fclose(file);
	return false;
}

