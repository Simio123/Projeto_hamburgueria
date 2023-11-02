#ifndef PESSOAS_H
#define PESSOAS_H

// Estrutura de pessoas
typedef struct Pessoa {
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

// Função para criar uma nova pessoa
struct Pessoa* criarPessoa(int status, int id, const char* nome, const const char* cargo, double salario, int idade, const char* endereco, const char* email, const char* telefone, const char* cpf, const char* data);

// Funções para manipular a lista encadeada de pessoas
void inserirPessoa(struct Pessoa** inicio, struct Pessoa* pessoa);
void removerPessoa(struct Pessoa** inicio, int id);
void editarPessoa(struct Pessoa* inicio, int id, const char* novo_nome, const char* novo_cargo, double novo_salario, int nova_idade, const char* novo_endereco, const char* novo_email, const char* novo_telefone, const char* novo_cpf, const char* nova_data);

// Função para exibir a lista encadeada de pessoas
void exibirListaEncadeada(struct Pessoa* inicio);

#endif
