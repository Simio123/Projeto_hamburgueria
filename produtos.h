#ifndef PRODUTOS_H
#define PRODUTOS_H

// Estrutura de produtos
typedef struct Produto {
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

// Função para criar um novo produto
Produto* criarProduto(int status, int codigo, int quantidade, float preco, const char* nome, const char* tipo, const char* validade);

// Funções para manipular a lista encadeada
void inserirProduto(Produto** inicio, Produto* produto);
void removerProduto(Produto** inicio, int codigo);
void editarProduto(Produto* inicio, int codigo, int nova_quantidade, float novo_preco, const char* novo_nome, const char* novo_tipo, const char* nova_validade);

// Função para exibir a lista encadeada de produtos
void exibirListaEncadeada(Produto* inicio);

#endif
