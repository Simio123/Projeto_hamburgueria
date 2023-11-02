#include <stdio.h>
#include <stdlib.h>
#include "pedidos.h" // Inclua o cabe�alho que define a estrutura Pedido

// Fun��o para criar um novo pedido
struct Pedido* criarPedido(int codigo, int quantidade, int tipo, const char* nome, float preco) {
    struct Pedido* novoPedido = (struct Pedido*)malloc(sizeof(struct Pedido));
    if (novoPedido == NULL) {
        printf("Erro: Falha na aloca��o de mem�ria para o pedido\n");
        return NULL;
    }

    novoPedido->codigo = codigo;
    novoPedido->quantidade = quantidade;
    novoPedido->tipo = tipo;
    snprintf(novoPedido->nome, sizeof(novoPedido->nome), "%s", nome); // Copia o nome
    novoPedido->preco = preco;
    novoPedido->proximo = NULL;
    novoPedido->status = 0; // Inicialmente, o status � "em prepara��o"

    return novoPedido;
}

// Fun��o para liberar a mem�ria de um pedido
void liberarPedido(struct Pedido* pedido) {
    if (pedido != NULL) {
        free(pedido);
    }
}

// Fun��o para atualizar o status de um pedido
void atualizarStatus(struct Pedido* pedido, int novoStatus) {
    if (pedido != NULL) {
        pedido->status = novoStatus;
    }
}
