#ifndef PEDIDOS_H
#define PEDIDOS_H

// Estrutura de pedidos
struct Pedido {
    int codigo;
    int quantidade;
    int tipo; // (1 para consumo no local e 0 para entrega)
    char nome[100];
    float preco;
    struct Pedido* proximo;
    int status;
};

// Função para criar um novo pedido
struct Pedido* criarPedido(int codigo, int quantidade, int tipo, const char* nome, float preco);

// Função para liberar a memória de um pedido
void liberarPedido(struct Pedido* pedido);

// Função para atualizar o status de um pedido
void atualizarStatus(struct Pedido* pedido, int novoStatus);

#endif
