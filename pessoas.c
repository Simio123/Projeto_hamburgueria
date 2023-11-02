#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoas.h"

struct Pessoa* criarPessoa(int status, int id, const char* nome, const char* cargo, double salario, int idade, const char* endereco, const char* email, const char* telefone, const char* cpf, const char* data)
{
    struct Pessoa* pessoa = (struct Pessoa*)malloc(sizeof(struct Pessoa));

    if (pessoa != NULL)
    {
        pessoa->status = status;
        pessoa->id = id;
        strncpy(pessoa->nome, nome, sizeof(pessoa->nome));
        strncpy(pessoa->cargo, cargo, sizeof(pessoa->cargo));
        pessoa->salario = salario;
        pessoa->idade = idade;
        strncpy(pessoa->endereco, endereco, sizeof(pessoa->endereco));
        strncpy(pessoa->email, email, sizeof(pessoa->email));
        strncpy(pessoa->telefone, telefone, sizeof(pessoa->telefone));
        strncpy(pessoa->cpf, cpf, sizeof(pessoa->cpf));
        strncpy(pessoa->data, data, sizeof(pessoa->data));
        pessoa->proximo = NULL; // Inicializa o próximo como NULL
    }
    return pessoa;
}

void inserirPessoa(struct Pessoa** inicio, struct Pessoa* pessoa)
{
    if (pessoa != NULL)
    {
        pessoa->proximo = *inicio;
        *inicio = pessoa;
    }
}

void removerPessoa(struct Pessoa** inicio, int id)
{
    struct Pessoa* anterior = NULL;
    struct Pessoa* atual = *inicio;

    while (atual != NULL && atual->id != id)
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

void editarPessoa(struct Pessoa* inicio, int id, const char* novo_nome, const char* novo_cargo, double novo_salario, int nova_idade, const char* novo_endereco, const char* novo_email, const char* novo_telefone, const char* novo_cpf, const char* nova_data)
{
    struct Pessoa* atual = inicio;

    while (atual != NULL)
    {
        if (atual->id == id)
        {
            strncpy(atual->nome, novo_nome, sizeof(atual->nome));
            strncpy(atual->cargo, novo_cargo, sizeof(atual->cargo));
            atual->salario = novo_salario;
            atual->idade = nova_idade;
            strncpy(atual->endereco, novo_endereco, sizeof(atual->endereco));
            strncpy(atual->email, novo_email, sizeof(atual->email));
            strncpy(atual->telefone, novo_telefone, sizeof(atual->telefone));
            strncpy(atual->cpf, novo_cpf, sizeof(atual->cpf));
            strncpy(atual->data, nova_data, sizeof(atual->data);
            return; // Pessoa encontrada e editada
        }
        atual = atual->proximo;
    }
}

void exibirListaEncadeada(struct Pessoa* inicio)
{
    struct Pessoa* atual = inicio;
    while (atual != NULL)
    {
        printf("ID: %d\n", atual->id);
        printf("Nome: %s\n", atual->nome);
        printf("Cargo: %s\n", atual->cargo);
        printf("Salário: %.2f\n", atual->salario);
        printf("\n");
        atual = atual->proximo;
    }
}
