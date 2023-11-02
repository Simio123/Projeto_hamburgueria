#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produtos.h"

Produto* criarProduto(int status, int codigo, int quantidade, const char* nome, const char* tipo, const char* validade)
{
    Produto* produto = (Produto*)malloc(sizeof(Produto));

    if (produto != NULL)
    {
        produto->status = status;
        produto->codigo = codigo;
        produto->quantidade = quantidade;
        produto->preco = 0.0; // Inicializa o preço como 0.0
        strncpy(produto->nome, nome, sizeof(produto->nome));
        strncpy(produto->tipo, tipo, sizeof(produto->tipo));
        strncpy(produto->validade, validade, sizeof(produto->validade));
        produto->proximo = NULL; // Inicializa o próximo como NULL
    }
    return produto;
}

void inserirProduto(Produto** inicio, Produto* produto)
{
    if (produto != NULL)
    {
        produto->proximo = *inicio;
        *inicio = produto;
    }
}

void removerProduto(Produto** inicio, int codigo)
{
    Produto* anterior = NULL;
    Produto* atual = *inicio;

    while (atual != NULL && atual->codigo != codigo)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual != NULL)
    {
        if (anterior != NULL)
        {
            anterior->proximo = atual->proximo;
        }
        else
        {
            *inicio = atual->proximo;
        }
        free(atual);
    }
}

void editarProduto(Produto* inicio, int codigo, int nova_quantidade, float novo_preco, const char* novo_nome, const char* novo_tipo, const char* nova_validade)
{
    Produto* atual = inicio;

    while (atual != NULL)
    {
        if (atual->codigo == codigo)
        {
            atual->quantidade = nova_quantidade;
            atual->preco = novo_preco;
            strncpy(atual->nome, novo_nome, sizeof(atual->nome));
            strncpy(atual->tipo, novo_tipo, sizeof(atual->tipo));
            strncpy(atual->validade, nova_validade, sizeof(atual->validade);
            return; // Produto encontrado e editado
        }
        atual = atual->proximo;
    }
}

void exibirListaEncadeada(Produto* inicio)
{
    Produto* atual = inicio;
    while (atual != NULL)
    {
        printf("Código: %d\n", atual->codigo);
        printf("Nome: %s\n", atual->nome);
        printf("Tipo: %s\n", atual->tipo);
        printf("Quantidade: %d\n", atual->quantidade);
        printf("Preço: %.2f\n", atual->preco);
        printf("Validade: %s\n", atual->validade);
        printf("Status: %d\n", atual->status);
        printf("\n");
        atual = atual->proximo;
    }
}
