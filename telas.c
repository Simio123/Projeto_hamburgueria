#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "telas.h"
#include "funcoes.h"

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

	while (1)
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
		login();
		break;

	case 2:
		empilhar(pilha, BEIJO);
		break;

	case 3:
		printf("Tela cliente");
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

void funcionario(int opcao, struct Pilha* pilha)
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
		login();
		break;

	case 2:
		empilhar(pilha, BEIJO);
		break;

	case 3:
		printf("Tela cliente");
		break;

	case 0:
		desempilhar(pilha);
		break;
	}
}

void cliente(int opcao, struct Pilha* pilha)
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
		login();
		break;

	case 2:
		empilhar(pilha, BEIJO);
		break;

	case 3:
		printf("Tela cliente");
		break;

	case 0:
		desempilhar(pilha);
		break;
	}
}

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
	printf("***             5. Avaliar comida e atendimento                             ***\n");
	printf("***             0. Voltar                                                   ***\n");
	printf("***                                                                         ***\n");
	printf("*******************************************************************************\n");
	printf("Como deseja entrar no sistema?\n");
	scanf("%d", &opcao);

	switch(opcao)
	{
	case 1:
		login();
		break;

	case 2:
		empilhar(pilha, BEIJO);
		break;

	case 3:
		printf("Tela cliente");
		break;

	case 0:
		desempilhar(pilha);
		break;
	}
}




















void beijo(int opcao,struct Pilha* pilha)
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
