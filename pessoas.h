#ifndef PESSOAS_H
#define PESSOAS_H

#include <stdbool.h>

typedef struct Pessoa
{
	double salario;
	char id[17];
	char nome[100];
	char cargo[100];
	char email[150];
	char telefone[20];
	char cpf[12];
	char data[11];

	struct Pessoa* proximo;

	int status;
} Pessoa;

void legenda_funcionario(void);
Pessoa* cadastro_funcionario(struct Pilha * pilha);
void salva_funcionario(Pessoa *funcionario);
void listagem_funcionarios(struct Pilha * pilha);
void listagem_funcionarios_i(struct Pilha * pilha);
void listagem_todos_funcionarios(struct Pilha * pilha);
void atualizar_funcionario(Pessoa* funcionario);
void editar_dados_funcionarios(struct Pilha * pilha);
bool procurar_funcionario(Pessoa * funcionario, struct Pilha * pilha);
void desabilita_funcionario(struct Pilha * pilha);
void readimite_funcionario(struct Pilha * pilha);

#endif
