#ifndef TELAS_H
#define TELAS_H

enum Tela {
    // Telas iniciais
    TELA_INICIAL,
    TELA_LOGIN,
    TELA_INFO_PROJETO,
    TELA_INFO_EQUIPE,

    // Telas secund�rias 
    TELA_ADMINISTRADOR,
    TELA_FUNCIONARIO,
    TELA_CLIENTE,

    // Telas terciarias
    TELA_ESTOQUE,
    TELA_PEDIDOS,
    TELA_RELATORIOS,
    TELA_DELIVERY,
    TELA_OPCOES_DE_PAGAMENTO,

    // Easter eggs
    BEIJO,
};


typedef struct Produto Produto;
Produto* criarProduto(int status, int codigo, int quantidade, const char* nome, const char* tipo, const char* validade);
void e_empilhar(Produto** topo, Produto* produto);
void e_desempilhar(Produto** topo);
void e_exibirPilha(Produto* topo);

typedef struct Pessoa Pessoa;
Pessoa* criarPessoa(int status, int id, const char* nome, const char* cargo, double salario, int idade, const char* endereco, const char* email, const char* telefone, const char* cpf, const char* data);
void p_empilhar(Pessoa** topo, Pessoa* pessoa);
void p_desempilhar(Pessoa** topo);
void exibirPilha(Pessoa* topo);


struct Pilha;
struct Pilha* criarPilha();
void empilhar(struct Pilha* pilha, enum Tela tela);
enum Tela desempilhar(struct Pilha* pilha);
void executarTela(struct Pilha* pilha);

// Telas principais
void tela_inicial(int opcao, struct Pilha* pilha);
void tela_login(int opcao, struct Pilha* pilha);
void tela_info_projeto(int opcao, struct Pilha* pilha);
void tela_info_equipe(int opcao, struct Pilha* pilha);

// Telas secund�rias 
void administrador(int opcao, struct Pilha* pilha);
void funcionario(int opcao, struct Pilha * pilha);
void cliente(int opcao, struct Pilha * pilha);

// Telas terciarias
void estoque(int opcao, struct Pilha * pilha);
void pedidos(int opcao, struct Pilha * pilha);
void relatorios(int opcao, struct Pilha * pilha);
void delivery(int opcao, struct Pilha * pilha);
void opcoes_de_pagamento(int opcao, struct Pilha * pilha);

// Easter eggs
void beijo(int opcao, struct Pilha* pilha);

#endif