#ifndef PRODUTOS_H
#define PRODUTOS_H

// Estrutura de produtos
struct Produto {
    int codigo;
    int quantidade;
    float preco;
    char nome[100];
    char tipo[50];
    char validade[11];

    // Aponta para o próximo produto na lista encadeada
    struct Produto* proximo;

    // Define o status do produto (1 para em estoque e 0 para em falta)
    int status;
};

#endif
