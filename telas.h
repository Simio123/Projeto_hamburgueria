#ifndef TELAS_H
#define TELAS_H

// A estrutura de enum(enumerate) serve para enumerar as variaveis abaixo
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

	// Funções de funcionario
	CADASTRO_FUNCIONARIO,
	LISTAGEM_FUNCIONARIOS,
	LISTAGEM_FUNCIONARIOS_I,
	LISTAGEM_TODOS_FUNCIONARIOS,
	DESABILITA_FUNCIONARIO,
	READMITE_FUNCIONARIO,
	EDITA_DADOS_FUNCIONARIOS,

	// Funções de estoque
	CADASTRO_PRODUTO,
	LISTAGEM_PRODUTOS,
	LISTAGEM_PRODUTOS_I,
	LISTAGEM_TODOS_PRODUTOS,
	DESABILITA_PRODUTO,
	REPOE_PRODUTO,
	EDITA_DADOS_PRODUTOS,

	// funções de pedido
	CARDAPIO,
	CADASTRO_PEDIDO,
	EXIBE_PEDIDOS,
	EXIBE_PEDIDOS_F,
	FINALIZA_PEDIDO,

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

// Easter eggs
void beijo(int opcao, struct Pilha* pilha);

#endif
