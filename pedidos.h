#ifndef PEDIDOS_H
#define PEDIDOS_H

#include <stdbool.h>

typedef struct Pedidos
{
	int numero_mesa;
	double valor_total;
	char id[17];
	char nome_cliente[100];
	char endereco_entrega[150];
	char telefone_cliente[20];
	char cpf_funcionario[12];
	char cpf_cliente[12];
	char data_pedido[11];
	char hora_pedido[8];
	char itens_pedido[300][300];
	int quantidade_pedido[300];
	double valor_pedido[300];

	struct Pedidos* proximo;

	int status;
} Pedidos;


#endif
