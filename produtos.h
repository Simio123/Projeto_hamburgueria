#ifndef PRODUTOS_H
#define PRODUTOS_H

// Estrutura de produtos
typedef struct Produto
{
	int codigo;
	int quantidade;
	double preco;
	char nome[100];
	char tipo[50];
	char validade[11];

	// Aponta para o próximo produto na lista encadeada
	struct Produto* proximo;

	// Define o status do produto (1 para em estoque e 0 para em falta)
	int status;
} Produto;


void legenda_produtos(void);
Produto* cadastro_produtos(struct Pilha * pilha);
#endif
