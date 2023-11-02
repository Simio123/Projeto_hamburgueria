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

#endif
