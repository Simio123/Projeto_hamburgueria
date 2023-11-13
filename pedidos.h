#ifndef PEDIDOS_H
#define PEDIDOS_H

#include <stdbool.h>

// Estrutura de pedidos
typedef struct Pedido
{
	int codigo;
	int quantidade;
	int tipo; // (1 para consumo no local e 0 para entrega)
	char nome[100];
	float preco;

	// Aponta para o próximo pedido na lista encadeada
	struct Pedido* proximo;

	// Define o status do pedido (1 para em preparação e 0 para entregue)
	int status;
} Pedido;

/*
void legenda_pedido(void);

Pedido* cadastro_pedido(struct Pilha * pilha);

*/ 
#endif
