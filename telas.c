#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "telas.h"
#include "funcoes.h"


// Estrutura de pedidos
typedef struct Pedido {
    // Atributos principais
    int codigo;
    int quantidade;
    char nome[100];
    char tipo[50];
    char validade[11];

    // Aponta para o pr�ximo produto na pilha
    struct Produto* proximo;

    // Define o status do produto (1 para entregue e 0 para em prepara��o/a caminho)
    int status;
};




// Estrutura de produtos
typedef struct Produto {
    // Atributos principais
    int codigo;
    int quantidade;
    char nome[100];
    char tipo[50];
    char validade[11];

    // Aponta para o pr�ximo produto na pilha
    struct Produto* proximo;

    // Define o status do produto (1 para em estoque e 0 para em falta)
    int status;
};

Produto* criarProduto(int status, int codigo, int quantidade, const char* nome, const char* tipo, const char* validade)
{
    Produto* produto = (Produto*)malloc(sizeof(Produto));

    if (produto != NULL)
    {
        produto->status = status;
        produto->codigo = codigo;
        produto->quantidade = quantidade;
        strncpy(produto->nome, nome, sizeof(produto->nome));
        strncpy(produto->tipo, tipo, sizeof(produto->tipo));
        strncpy(produto->validade, validade, sizeof(produto->validade));
        produto->proximo = NULL; // Inicializa o pr�ximo como NULL
    }
    return produto;
}

void e_empilhar(Produto** topo, Produto* produto)
{
    if (produto != NULL)
    {
        produto->proximo = *topo;
        *topo = produto;
    }
}

void e_desempilhar(Produto** topo)
{
    if (*topo != NULL)
    {
        Produto* temp = *topo;
        *topo = (*topo)->proximo;
        free(temp);
    }
}

void e_exibirPilha(Produto* topo)
{
    Produto* atual = topo;
    while (atual != NULL)
    {
        printf("C�digo: %d\n", atual->codigo); // Corre��o: exibir o campo 'codigo' corretamente
        printf("Nome: %s\n", atual->nome);
        printf("Tipo: %s\n", atual->tipo);
        printf("Quantidade: %d\n", atual->quantidade);
        printf("Validade: %s\n", atual->validade);
        printf("Status: %d\n", atual->status);
        printf("\n");
        atual = atual->proximo;
    }
}

// Estrutua de pessoas
typedef struct Pessoa
{
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

	// Aponta para o pr�ximo funcion�rio na pilha
	struct Pessoa* proximo;

	// Define o status da pessoa na pilha (1 para ativo e 0 para inativo)
	int status;
};

Pessoa* criarPessoa(int status, int id, const char* nome, const char* cargo, double salario, int idade, const char* endereco, const char* email, const char* telefone, const char* cpf, const char* data)
{
	Pessoa* pessoa = (Pessoa*)malloc(sizeof(Pessoa));

	if (pessoa != NULL)
	{
		pessoa->status = status;
		pessoa->id = id;
		strncpy(pessoa->nome, nome, sizeof(pessoa->nome));
		strncpy(pessoa->cargo, cargo, sizeof(pessoa->cargo));
		pessoa->salario = salario;
		pessoa->idade = idade;
		strncpy(pessoa->endereco, endereco, sizeof(pessoa->endereco));
		strncpy(pessoa->email, email, sizeof(pessoa->email));
		strncpy(pessoa->telefone, telefone, sizeof(pessoa->telefone));
		strncpy(pessoa->cpf, cpf, sizeof(pessoa->cpf));
		strncpy(pessoa->data, data, sizeof(pessoa->data));
	}
	return pessoa;
}

void p_empilhar(Pessoa** topo, Pessoa* pessoa)
{
	pessoa->proximo = *topo;
	*topo = pessoa;
}

void p_desempilhar(Pessoa** topo)
{
	if (*topo != NULL)
	{
		Pessoa* temp = *topo;
		*topo = (*topo)->proximo;
		free(temp);
	}
}

void exibirPilha(Pessoa* topo)
{
	Pessoa* atual = topo;
	while (atual != NULL)
	{
		printf("ID: %d\n", atual->id);
		printf("Nome: %s\n", atual->nome);
		printf("Cargo: %s\n", atual->cargo);
		printf("Sal�rio: %.2f\n", atual->salario);
		printf("\n");
		atual = atual->proximo;
	}
}


// Estrutura da pilha de telas
struct No
{
	enum Tela tela;
	struct No* proximo;
};

struct Pilha
{
	struct No* topo;
};

struct Pilha* criarPilha()
{
	struct Pilha* pilha = (struct Pilha*)malloc(sizeof(struct Pilha));
	pilha->topo = NULL;
	return pilha;
}

void empilhar(struct Pilha* pilha, enum Tela tela)
{
	struct No* novoNo = (struct No*)malloc(sizeof(struct No));
	novoNo->tela = tela;
	novoNo->proximo = pilha->topo;
	pilha->topo = novoNo;
}

enum Tela desempilhar(struct Pilha* pilha)
{
	if (pilha->topo == NULL)
	{
		printf("A pilha est� vazia!\n");
		exit(1);
	}

	struct No* temp = pilha->topo;
	enum Tela telaDesempilhada = temp->tela;
	pilha->topo = temp->proximo;
	free(temp);

	return telaDesempilhada;
}

void executarTela(struct Pilha* pilha)
{
	int opcao = 1000;

	while (pilha->topo != NULL)
	{
		enum Tela telaAtual = pilha->topo->tela;

		switch (telaAtual)
		{
		case TELA_INICIAL:
			tela_inicial(opcao, pilha);
			break;

		case TELA_LOGIN:
			tela_login(opcao, pilha);
			break;

		case TELA_INFO_PROJETO:
			tela_info_projeto(opcao, pilha);
			break;

		case TELA_INFO_EQUIPE:
			tela_info_equipe(opcao, pilha);
			break;

			// Telas secund�rias
		case TELA_ADMINISTRADOR:
			administrador(opcao, pilha);
			break;

		case TELA_FUNCIONARIO:
			funcionario(opcao, pilha);
			break;

		case TELA_CLIENTE:
			cliente(opcao, pilha);
			break;

			// Telas terciarias
		case TELA_ESTOQUE:
			estoque(opcao, pilha);
			break;

		case TELA_PEDIDOS:
			pedidos(opcao, pilha);
			break;

		case TELA_RELATORIOS:
			relatorios(opcao, pilha);
			break;

		case TELA_DELIVERY:
			delivery(opcao, pilha);
			break;

		case TELA_OPCOES_DE_PAGAMENTO:
			opcoes_de_pagamento(opcao, pilha);
			break;

			// Easter eggs
		case BEIJO:
			beijo(opcao, pilha);
			break;

		}
	}
}

// Telas principais
void tela_inicial(int opcao, struct Pilha* pilha)
{
	system("clear||cls");
	printf("\n");
	printf("*******************************************************************************\n");
	printf("***             Universidade Federal do Rio Grande do Norte                 ***\n");
	printf("***             Centro de Ensino Superior do Serid�                         ***\n");
	printf("***             Departamento de Computa��o e Tecnologia                     ***\n");
	printf("***             Disciplina: Programa��o                                     ***\n");
	printf("***             Professor: Flavius Gorgonio                                 ***\n");
	printf("***             Projeto: Sistema de Gest�o de Hamburgueria                  ***\n");
	printf("***             Aluno: Emerson da Silva Santos                              ***\n");
	printf("***             Linguagem: C                                                ***\n");
	printf("*******************************************************************************\n");
	printf("*******************************************************************************\n");
	printf("***   = = = = =  Bem vindo ao Sistema de Gest�o de Hamburgueria = = = = =   ***\n");
	printf("***                                                                         ***\n");
	printf("***             1. Login                                                    ***\n");
	printf("***             2. Consultar informa��es sobre o projeto                    ***\n");
	printf("***             3. Consultar informa��es sobre Equipe responsavel           ***\n");
	printf("***             0. Sair                                                     ***\n");
	printf("***                                                                         ***\n");
	printf("*******************************************************************************\n");
	printf("O que deseja fazer?\n");
	scanf("%d", &opcao);

	switch(opcao)
	{
	case 1:
		empilhar(pilha, TELA_LOGIN);
		break;

	case 2:
		empilhar(pilha, TELA_INFO_PROJETO);
		break;

	case 3:
		empilhar(pilha, TELA_INFO_EQUIPE);
		break;

	case 0:
		printf("Saindo do programa...\n");
		free(pilha);
		exit(0);
		break;
	}
}

void tela_login(int opcao, struct Pilha* pilha)
{
	system("clear||cls");
	printf("*******************************************************************************\n");
	printf("***             = = = = = Menu de login = = = = =                           ***\n");
	printf("***                                                                         ***\n");
	printf("***             1. Administrador                                            ***\n");
	printf("***             2. Funcion�rio                                              ***\n");
	printf("***             3. Cliente                                                  ***\n");
	printf("***             0. Voltar                                                   ***\n");
	printf("***                                                                         ***\n");
	printf("*******************************************************************************\n");
	printf("Como deseja entrar no sistema?\n");
	scanf("%d", &opcao);

	switch(opcao)
	{
	case 1:
		empilhar(pilha, TELA_ADMINISTRADOR);
		break;

	case 2:
		empilhar(pilha, TELA_FUNCIONARIO);
		break;

	case 3:
		empilhar(pilha, TELA_CLIENTE);
		break;

	case 0:
		desempilhar(pilha);
		break;
	}
}

void tela_info_projeto(int opcao, struct Pilha* pilha)
{
	system("clear||cls");
	printf("*******************************************************************************\n");
	printf("***             = = = = = informa��es sobre o projeto = = = = =             ***\n");
	printf("***                                                                         ***\n");
	printf("***             O Programa gerencia o funcionamento de uma hamburgueria     ***\n");
	printf("***       fins did�ticos de ilustra��o. O programa cont�m os principais     ***\n");
	printf("***       e funcionalidades que ser�o exigidos na avalia��o dos projetos    ***\n");
	printf("***       desenvolvidos pelos alunos ao longo da disciplina. Serve como u   ***\n");
	printf("***       de consulta e refer�ncia para o desenvolvidos dos demais proje    ***\n");
	printf("***                                                                         ***\n");
	printf("*******************************************************************************\n");
	printf("Insira 0 para voltar\n");
	scanf("%d", &opcao);

	if (opcao == 0)
	{
		desempilhar(pilha);
	}
}

void tela_info_equipe(int opcao, struct Pilha* pilha)
{
	system("clear||cls");
	printf("*******************************************************************************\n");
	printf("***             = = = = = informa��es sobre Equipe responsavel = = = = =    ***\n");
	printf("***                                                                         ***\n");
	printf("***             Este projeto exemplo foi desenvolvido por:                  ***\n");
	printf("***             Emerson da Silva santos                                     ***\n");
	printf("***             E-mail: emerson.santos.125@ufrn.edu.br                      ***\n");
	printf("***             Git: https://github.com/Simio123/Projeto_hamburgueria.git   ***\n");
	printf("***                                                                         ***\n");
	printf("*******************************************************************************\n");
	printf("Insira 0 para voltar\n");
	scanf("%d", &opcao);

	if (opcao == 0)
	{
		desempilhar(pilha);
	}
}


// Telas secund�rias

void administrador(int opcao, struct Pilha* pilha)
{
	system("clear||cls");
	printf("*******************************************************************************\n");
	printf("***             = = = = = Menu de administrador = = = = =                   ***\n");
	printf("***                                                                         ***\n");
	printf("***             1. Demitir funcion�rio                                      ***\n");
	printf("***             2. Acessar estoque                                          ***\n");
	printf("***             3. Cadastrar Funcion�rio                                    ***\n");
	printf("***             4. Editar dados dos funcon�rios                             ***\n");
	printf("***             5. Exibir relatorios                                        ***\n");
	printf("***             6. Cadastrar promo��o                                       ***\n");
	printf("***             0. Voltar                                                   ***\n");
	printf("***                                                                         ***\n");
	printf("*******************************************************************************\n");
	printf("Como deseja entrar no sistema?\n");
	scanf("%d", &opcao);

	switch(opcao)
	{
	case 1:
		printf("fun��o demiss�o");
		break;

	case 2:
		empilhar(pilha, TELA_ESTOQUE);
		break;

	case 3:
		printf("Tela");
		break;

	case 4:
		printf("Tela");
		break;

	case 5:
		printf("Tela");
		break;

	case 0:
		desempilhar(pilha);
		break;
	}
}

void funcionario(int opcao, struct Pilha * pilha)
{
	system("clear||cls");
	printf("*******************************************************************************\n");
	printf("***             = = = = = Menu de funcionario = = = = =                     ***\n");
	printf("***                                                                         ***\n");
	printf("***             1. Editar dados pessoais                                    ***\n");
	printf("***             2. Pedir demiss�o                                           ***\n");
	printf("***             3. Acessar estoque                                          ***\n");
	printf("***             4. Verificar pedidos                                        ***\n");
	printf("***             0. Voltar                                                   ***\n");
	printf("***                                                                         ***\n");
	printf("*******************************************************************************\n");
	printf("Como deseja entrar no sistema?\n");
	scanf("%d", &opcao);

	switch(opcao)
	{
	case 1:
		printf("Tela");
		break;

	case 2:
		printf("Tela");
		break;

	case 3:
		empilhar(pilha, TELA_ESTOQUE);
		break;

	case 4:
		empilhar(pilha, TELA_PEDIDOS);
		break;

	case 0:
		desempilhar(pilha);
		break;
	}
}

void cliente(int opcao, struct Pilha * pilha)
{
	system("clear||cls");
	printf("*******************************************************************************\n");
	printf("***             = = = = = Menu de cliente = = = = =                         ***\n");
	printf("***                                                                         ***\n");
	printf("***             1. Realizar pedido                                          ***\n");
	printf("***             2. Reservar mesa                                            ***\n");
	printf("***             3. Registrar reclama��o                                     ***\n");
	printf("***             4. Registrar sugest�o                                       ***\n");
	printf("***             5. Avaliar comida e atendimento                             ***\n");
	printf("***             0. Voltar                                                   ***\n");
	printf("***                                                                         ***\n");
	printf("*******************************************************************************\n");
	printf("Como deseja entrar no sistema?\n");
	scanf("%d", &opcao);

	switch(opcao)
	{
	case 1:
		printf("Tela");
		break;

	case 2:
		printf("Tela");
		break;

	case 3:
		printf("Tela");
		break;

	case 4:
		printf("Tela");
		break;

	case 5:
		printf("Tela");
		break;

	case 0:
		desempilhar(pilha);
		break;
	}
}


// Telas terciarias

void estoque(int opcao, struct Pilha * pilha)
{
	system("clear||cls");
	printf("*******************************************************************************\n");
	printf("***             = = = = = Menu Estoque = = = = =                            ***\n");
	printf("***                                                                         ***\n");
	printf("***             1. Buscar produto                                           ***\n");
	printf("***             2. Editar estoque                                           ***\n");
	printf("***             3. Zerar estoque                                            ***\n");
	printf("***             0. Voltar                                                   ***\n");
	printf("***                                                                         ***\n");
	printf("*******************************************************************************\n");
	printf("Como deseja entrar no sistema?\n");
	scanf("%d", &opcao);

	switch(opcao)
	{
	case 1:
		printf("Tela");
		break;

	case 2:
		printf("Tela");
		break;

	case 3:
		printf("Tela");
		break;

	case 0:
		desempilhar(pilha);
		break;
	}
}

void pedidos(int opcao, struct Pilha * pilha)
{
	system("clear||cls");
	printf("*******************************************************************************\n");
	printf("***             = = = = = Menu Pedidos = = = = =                            ***\n");
	printf("***                                                                         ***\n");
	printf("***             1. Registrar pedidos                                        ***\n");
	printf("***             2. Finalizar pedidos                                        ***\n");
	printf("***             3. Visualizar pedidos                                       ***\n");
	printf("***             0. Voltar                                                   ***\n");
	printf("***                                                                         ***\n");
	printf("*******************************************************************************\n");
	printf("Como deseja entrar no sistema?\n");
	scanf("%d", &opcao);

	switch(opcao)
	{
	case 1:
		printf("Tela");
		break;

	case 2:
		printf("Tela");
		break;

	case 3:
		printf("Tela");
		break;

	case 0:
		desempilhar(pilha);
		break;
	}
}

void relatorios(int opcao, struct Pilha * pilha)
{
	system("clear||cls");
	printf("*******************************************************************************\n");
	printf("***             = = = = = Menu relatorios = = = = =                         ***\n");
	printf("***                                                                         ***\n");
	printf("***             1. Vendas semanais                                          ***\n");
	printf("***             2. Despesas semanais                                        ***\n");
	printf("***             3. Lucro semanal                                        	***\n");
	printf("***             4. Vendas por item                                          ***\n");
	printf("***             5. Atendimentos por dia                                     ***\n");
	printf("***             6. Vendas por horario                                    	***\n");
	printf("***             7. Lucro semanal                                        	***\n");
	printf("***             0. Voltar                                                   ***\n");
	printf("***                                                                         ***\n");
	printf("*******************************************************************************\n");
	printf("Como deseja entrar no sistema?\n");
	scanf("%d", &opcao);

	switch(opcao)
	{
	case 1:
		printf("Tela");
		break;

	case 2:
		printf("Tela");
		break;

	case 3:
		printf("Tela");
		break;

	case 4:
		printf("Tela");
		break;

	case 5:
		printf("Tela");
		break;

	case 6:
		printf("Tela");
		break;

	case 7:
		printf("Tela");
		break;

	case 0:
		desempilhar(pilha);
		break;
	}
}

void delivery(int opcao, struct Pilha * pilha)
{
	system("clear||cls");
	printf("*******************************************************************************\n");
	printf("***             = = = = = Menu delivery = = = = =                           ***\n");
	printf("***                                                                         ***\n");
	printf("***             1. Registrar pedido                                         ***\n");
	printf("***             2. Finalizar pedido                                         ***\n");
	printf("***             3. Rastrear pedido                                       	***\n");
	printf("***             4. Visualizar pedidos                                       ***\n");
	printf("***             0. Voltar                                                   ***\n");
	printf("***                                                                         ***\n");
	printf("*******************************************************************************\n");
	printf("Como deseja entrar no sistema?\n");
	scanf("%d", &opcao);

	switch(opcao)
	{
	case 1:
		printf("Tela");
		break;

	case 2:
		printf("Tela");
		break;

	case 3:
		printf("Tela");
		break;

	case 4:
		printf("Tela");
		break;

	case 0:
		desempilhar(pilha);
		break;
	}
}

void opcoes_de_pagamento(int opcao, struct Pilha * pilha)
{
	system("clear||cls");
	printf("*******************************************************************************\n");
	printf("***             = = = = = Menu pagamento = = = = =                          ***\n");
	printf("***                                                                         ***\n");
	printf("***             1. Dinheiro                                                 ***\n");
	printf("***             2. Cart�o de credito                                        ***\n");
	printf("***             3. Cart�o de debito                                       	***\n");
	printf("***             4. Transferencia bancaria                                   ***\n");
	printf("***             5. Pix                                                      ***\n");
	printf("***             0. Voltar                                                   ***\n");
	printf("***                                                                         ***\n");
	printf("*******************************************************************************\n");
	printf("Como deseja entrar no sistema?\n");
	scanf("%d", &opcao);

	switch(opcao)
	{
	case 1:
		printf("Tela");
		break;

	case 2:
		printf("Tela");
		break;

	case 3:
		printf("Tela");
		break;

	case 4:
		printf("Tela");
		break;

	case 5:
		printf("Tela");
		break;

	case 0:
		desempilhar(pilha);
		break;
	}
}


// easter eggs

void beijo(int opcao, struct Pilha* pilha)
{
	printf("+******##############################***++++++++++++++++++++++++++++++++++++++++++++++*+************\n");
	printf("+*****##################################***++++******++++++++++++++++++++++++++++++++++++++*********\n");
	printf("++**######################################**+++++++++++++++++++++++++++++++++++++++++++++*+*********\n");
	printf("+**##################################***####*+++++++++++++++++++++++*********+++++++++++++*+********\n");
	printf("+*####################*##****##*######********+++++++++++++++++***####################*****+********\n");
	printf("*######################************###*********+++++++++++++***#*****#######################********\n");
	printf("*######################*************##******#***+++++++++++**********##########################*****\n");
	printf("*####################*#**************#****#####**++++++++************############################***\n");
	printf("*############***########*###*************#**####*++++++**************#############################**\n");
	printf("*###############***##########***************####*+++++******************###########################*\n");
	printf("*#############################**********#*****##*++++*****##***************##*######################\n");
	printf("*##################***#########**************###*+++**#####********************#####################\n");
	printf("+##################**###########**********######*+++*######**********************###################\n");
	printf("+*##################*####****###********#######*+++*###########******************#####*#############\n");
	printf("+*#######################****###*********#####*+++++*#########********************##**#*############\n");
	printf("+#####################*####**####**********###**++*****####***********************##**#*############\n");
	printf("+###***####################**#######*******#####******#*************************##*****#############\n");
	printf("**##*###*##################**##########*#######**##***#************************##*****##############\n");
	printf("*#######****##################################****######*******##*******************###############*\n");
	printf("*#****###***#########################################*******######***********#*###################*+\n");
	printf("*##*################**################################******#####************#######**###########*++\n");
	printf("***###****##########**#################################******#####*******#*#######****##########*+*+\n");
	printf("****###*****########***##########################**##**********########*########*****###########****\n");
	printf("***###*#******####*##***###############################********##################****##########*+++*\n");
	printf("***##***************##***###############################********##################***##########*****\n");
	printf("*##**#****#*******######**##############################********##################**##########******\n");
	printf("*##***#*******##****##***#*#################*+***+*#####****#######################**########*#*****\n");
	printf("*##****#*******#***********################*++++++#########################################**#**#***\n");
	printf("**##**#######**************#*++****#######*+++++++########################################*****#****\n");
	printf("**#############*#**#*##*####*+++++++******++++++++*######################################****#******\n");
	printf("*############*******#**#####*+++++++++++++++++++++++**************#####################****##*******\n");
	printf("**#################**#######*+++++++++++++++++++++++++++++++++++++*#################**#***#*********\n");
	printf("+***################*#######+++++++++++++++++++++++++++++++++++++++*##############**##**************\n");
	system("Pause");
	desempilhar(pilha);
}
