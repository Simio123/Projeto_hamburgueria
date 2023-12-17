#ifndef PEDIDOS_H
#define PEDIDOS_H

#include <stdbool.h>

typedef struct Pedidos
{
	char id[17];
	char nome_cliente[100];
	char cpf_cliente[12];
	char data_pedido[11];
	char hora_pedido[9];
	char item_pedido[100][100];
	int quantidade_pedido[100];
	double val_ped[100];
	double valor_pedido;
	int n_ped;

	struct Pedidos* proximo;

	int status;
} Pedidos;

void legenda_pedido(void);
Pedidos* cadastro_pedido(Estoque *produto, struct Pilha * pilha);
void salva_pedido(Pedidos *pedido);
void exibe_pedidos(struct Pilha * pilha);
bool pedido_com_quantidade_existente(char *id, int quantidade, double *preco_t, double *preco_u);
bool pedido_com_id_existente(char* id);
void finaliza_pedido(struct Pilha * pilha);
void exibe_pedidos_f(struct Pilha * pilha);
void pedidos_por_hora(Pedidos vetor[], int tamanho);

#endif
