#ifndef TELAS_H
#define TELAS_H

enum Tela {
	// Telas iniciais
    TELA_INICIAL,
    TELA_LOGIN,
    TELA_INFO_PROJETO,
    TELA_INFO_EQUIPE,
    // Easter egg
    BEIJO,
    // Telas secundárias 
    
};

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

// Telas secundárias
void beijo(int opcao, struct Pilha* pilha);

#endif
