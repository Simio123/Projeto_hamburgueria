#ifndef PESSOAS_H
#define PESSOAS_H

#include <stdbool.h>

// Estrutura de pessoas
// ######################################################################################
// ######################################################################################
// ######################################################################################
typedef struct Pessoa
{
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

	struct Pessoa* proximo;

	int status;
} Pessoa;

void legenda_funcionario(void);
Pessoa* cadastro_funcionario(struct Pilha * pilha);
void salva_funcionario(Pessoa *funcionario);
void listagem_funcionarios(struct Pilha * pilha);
void listagem_funcionarios_i(struct Pilha * pilha);
void atualizar_funcionario(Pessoa* funcionario);
void editar_dados_funcionarios(struct Pilha * pilha);
bool procurar_funcionario(Pessoa *funcionario);
void desabilita_funcionario(struct Pilha * pilha);


// Estrutura de estoque
// ######################################################################################
// ######################################################################################
// ######################################################################################
typedef struct Estoque
{
	int quantidade;
	double preco;
	char id[11];
	char nome[100];
	char tipo[50];
	char validade[11];

	struct Estoque* proximo;

	int status;
} Estoque;

void legenda_produto(void);
Estoque* cadastro_produto(struct Pilha* pilha);
void salva_produto(Estoque *produto);
void listagem_produtos(struct Pilha * pilha);
void atualizar_produto(Estoque* produto);
void editar_dados_produtos(struct Pilha * pilha);
bool procurar_produto(Estoque *produto);
void desabilita_produto(struct Pilha * pilha);


// Estrutura de pedidos
// ######################################################################################
// ######################################################################################
// ######################################################################################
typedef struct Pedido
{
	char id[11];
	int quantidade;
	int tipo;
	char nome[100];
	double preco;

	struct Pedido* proximo;

	int status;
} Pedido;

void legenda_pedido(void);
Pedido* cadastro_pedido(struct Pilha* pilha);
void salva_pedido(Pedido *pedido);
void listagem_pedidos(struct Pilha * pilha);
void atualizar_pedido(Estoque* produto);
void editar_pedido(struct Pilha * pilha);
bool procurar_pedido(Pedido *pedido);
void finaliza_pedido(struct Pilha * pilha);




#endif
