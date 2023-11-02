#include <stdio.h>
#include <stdlib.h>
#include "pedidos.h" // Inclua o cabeçalho que define a estrutura Pedido

// Função para criar um novo pedido
struct Pedido* criarPedido(int codigo, int quantidade, int tipo, const char* nome, float preco) {
    struct Pedido* novoPedido = (struct Pedido*)malloc(sizeof(struct Pedido));
    if (novoPedido == NULL) {
        printf("Erro: Falha na alocação de memória para o pedido\n");
        return NULL;
    }

    novoPedido->codigo = codigo;
    novoPedido->quantidade = quantidade;
    novoPedido->tipo = tipo;
    snprintf(novoPedido->nome, sizeof(novoPedido->nome), "%s", nome); // Copia o nome
    novoPedido->preco = preco;
    novoPedido->proximo = NULL;
    novoPedido->status = 0; // Inicialmente, o status é "em preparação"

    return novoPedido;
}

// Função para liberar a memória de um pedido
void liberarPedido(struct Pedido* pedido) {
    if (pedido != NULL) {
        free(pedido);
    }
}

// Função para atualizar o status de um pedido
void atualizarStatus(struct Pedido* pedido, int novoStatus) {
    if (pedido != NULL) {
        pedido->status = novoStatus;
    }
}
