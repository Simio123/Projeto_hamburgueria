#ifndef PESSOAS_H
#define PESSOAS_H


void adicionar_pessoa(int opcao, struct Pilha* pilha);

// Estrutura de pessoas
struct Pessoa {
    // Atributos principais
    int id;
    char nome[100];
    char cargo[100];
    double salario;
    int idade;
    char endereco[150];
    char email[150];
    char telefone[20];
    char cpf[12];
    char data[11];

    // Aponta para o próximo funcionário na lista encadeada
    struct Pessoa* proximo;

    // Define o status da pessoa (1 para ativo e 0 para inativo)
    int status;
};

#endif
