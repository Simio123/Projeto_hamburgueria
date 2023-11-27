#ifndef TELAS_H
#define TELAS_H

enum Tela
{
	// Telas iniciais
	TELA_INICIAL,
	TELA_LOGIN,
	TELA_INFO_PROJETO,
	TELA_INFO_EQUIPE,

	// Telas secundárias
	TELA_ADMINISTRADOR,
	TELA_FUNCIONARIO,
	TELA_CLIENTE,

	// Telas terciarias
	TELA_ESTOQUE,
	TELA_PEDIDOS,
	TELA_RELATORIOS,
	TELA_DELIVERY,
	TELA_OPCOES_DE_PAGAMENTO,

	// Funções de cadastro
	CADASTRO_FUNCIONARIO,
	LISTAGEM_FUNCIONARIOS,
	LISTAGEM_FUNCIONARIOS_I,
	DESABILITA_FUNCIONARIO,
	EDITA_DADOS_FUNCIONARIOS,

	CADASTRO_PRODUTO,
	LISTAGEM_PRODUTOS,
	DESABILITA_PRODUTO,
	EDITA_DADOS_PRODUTOS,


	// funções de pedido

	// Easter eggs
	BEIJO,


};

struct Pilha;
struct Pilha* criarPilha();
void empilhar(struct Pilha* pilha, enum Tela tela);
enum Tela desempilhar(struct Pilha* pilha);
void executarTela(struct Pilha* pilha);

// Telas principais
void tela_inicial(int opcao, int controle, struct Pilha* pilha);
void tela_login(int opcao, int controle, struct Pilha* pilha);
void tela_info_projeto(int opcao, int controle, struct Pilha* pilha);
void tela_info_equipe(int opcao, int controle, struct Pilha* pilha);

// Telas secundárias
void administrador(int opcao, int controle, struct Pilha* pilha);
void funcionario(int opcao, int controle, struct Pilha* pilha);
void cliente(int opcao, int controle, struct Pilha* pilha);

// Telas terciarias
void estoque(int opcao, int controle, struct Pilha* pilha);
void pedidos(int opcao, int controle, struct Pilha* pilha);
void relatorios(int opcao, int controle, struct Pilha* pilha);
void delivery(int opcao, int controle, struct Pilha* pilha);
void opcoes_de_pagamento(int opcao, int controle, struct Pilha* pilha);

// Easter eggs
void beijo(int opcao, struct Pilha* pilha);

#endif
