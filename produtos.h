#ifndef PRODUTOS_H
#define PRODUTOS_H

#include <stdbool.h>

typedef struct Estoque
{
	int quantidade;
	double preco;
	char id[17];
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
void listagem_produtos_i(struct Pilha * pilha);
void listagem_todos_produtos(struct Pilha * pilha);
void atualizar_produto(Estoque* produto);
void editar_dados_produtos(struct Pilha * pilha);
bool procurar_produto(Estoque * produto, struct Pilha * pilha);
void desabilita_produto(struct Pilha * pilha);
void repoe_produto(struct Pilha * pilha);
void cardapio(struct Pilha * pilha);

bool produto_com_id_existente(char* id);

#endif
