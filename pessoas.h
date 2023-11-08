#ifndef PESSOAS_H
#define PESSOAS_H

#include <stdbool.h>

// Estrutura de pessoas
typedef struct Pessoa
{
	// Atributos principais
	int idade;
	double salario;
	char id[11];
	char nome[100];
	char cargo[100];
	char endereco[150];
	char email[150];
	char telefone[20];
	char cpf[12];
	char data[11];

	// Aponta para o próximo funcionário na lista encadeada
	struct Pessoa* proximo;

	// Define o status da pessoa (1 para ativo e 0 para inativo)
	int status;
} Pessoa;

void legenda_funcionario(void);
Pessoa* cadastro_funcionario(struct Pilha * pilha);
void salva_funcionario(Pessoa *funcionario);
void listagem_funcionarios(void);

void atualizar_funcionario(Pessoa* funcionario);
void editar_dados_funcionarios(void);
bool procurar_funcionario(Pessoa *funcionario);
void desabilita_funcionario(void);

#endif
