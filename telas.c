#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "telas.h"
#include "pessoas.h"
#include "produtos.h"

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
		printf("A pilha está vazia!\n");
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
	int controle = 0;

	while (pilha->topo != NULL)
	{
		enum Tela telaAtual = pilha->topo->tela;

		switch (telaAtual)
		{
		case TELA_INICIAL:
			tela_inicial(opcao, controle, pilha);
			break;

		case TELA_LOGIN:
			tela_login(opcao, controle, pilha);
			break;

		case TELA_INFO_PROJETO:
			tela_info_projeto(opcao, controle, pilha);
			break;

		case TELA_INFO_EQUIPE:
			tela_info_equipe(opcao, controle, pilha);
			break;

			// Telas secundárias
		case TELA_ADMINISTRADOR:
			administrador(opcao, controle, pilha);
			break;

		case TELA_FUNCIONARIO:
			funcionario(opcao, controle, pilha);
			break;

		case TELA_CLIENTE:
			cliente(opcao, controle, pilha);
			break;

			// Telas terciarias
		case TELA_ESTOQUE:
			estoque(opcao, controle, pilha);
			break;

		case TELA_PEDIDOS:
			pedidos(opcao, controle, pilha);
			break;

		case TELA_RELATORIOS:
			relatorios(opcao, controle, pilha);
			break;

		case TELA_DELIVERY:
			delivery(opcao, controle, pilha);
			break;

		case TELA_OPCOES_DE_PAGAMENTO:
			opcoes_de_pagamento(opcao, controle, pilha);
			break;

			// Funções associadas ao funcionario
		case CADASTRO_FUNCIONARIO:
			cadastro_funcionario(pilha);
			break;

		case LISTAGEM_FUNCIONARIOS:
			listagem_funcionarios(pilha);
			break;

		case LISTAGEM_FUNCIONARIOS_I:
			listagem_funcionarios_i(pilha);
			break;

		case LISTAGEM_TODOS_FUNCIONARIOS:
			listagem_todos_funcionarios(pilha);
			break;

		case DESABILITA_FUNCIONARIO:
			desabilita_funcionario(pilha);
			break;

		case READMITE_FUNCIONARIO:
			readimite_funcionario(pilha);
			break;

		case EDITA_DADOS_FUNCIONARIOS:
			editar_dados_funcionarios(pilha);
			break;

			// funcoes relacionadas ao estoque
		case CADASTRO_PRODUTO:
			cadastro_produto(pilha);
			break;

		case LISTAGEM_PRODUTOS:
			listagem_produtos(pilha);
			break;

		case LISTAGEM_PRODUTOS_I:
			listagem_produtos_i(pilha);
			break;

		case LISTAGEM_TODOS_PRODUTOS:
			listagem_todos_produtos(pilha);
			break;

		case DESABILITA_PRODUTO:
			desabilita_produto(pilha);
			break;

		case EDITA_DADOS_PRODUTOS:
			editar_dados_produtos(pilha);
			break;

		case REPOE_PRODUTO:
			repoe_produto(pilha);
			break;

			// pedidos

			// Easter eggs
		case BEIJO:
			beijo(opcao, pilha);
			break;
		}
	}
}

// Telas principais
void tela_inicial(int opcao, int controle, struct Pilha* pilha)
{
	system("clear||cls");
	printf("\n");
	printf("*******************************************************************************\n");
	printf("***             Universidade Federal do Rio Grande do Norte                 ***\n");
	printf("***             Centro de Ensino Superior do Serido                         ***\n");
	printf("***             Departamento de Computacao e Tecnologia                     ***\n");
	printf("***             Disciplina: Programacao                                     ***\n");
	printf("***             Professor: Flavius Gorgonio                                 ***\n");
	printf("***             Projeto: Sistema de Gestao de Hamburgueria                  ***\n");
	printf("***             Aluno: Emerson da Silva Santos                              ***\n");
	printf("***             Linguagem: C                                                ***\n");
	printf("*******************************************************************************\n");
	printf("*******************************************************************************\n");
	printf("***   = = = = =  Bem vindo ao Sistema de Gestao de Hamburgueria = = = = =   ***\n");
	printf("***                                                                         ***\n");
	printf("***             1. Login                                                    ***\n");
	printf("***             2. Consultar informacoes sobre o projeto                    ***\n");
	printf("***             3. Consultar informacoes sobre a equipe responsavel         ***\n");
	printf("***             0. Sair                                                     ***\n");
	printf("***                                                                         ***\n");
	printf("*******************************************************************************\n");
	printf("O que deseja fazer?\n");
	while (scanf("%d", &opcao) != 1)
	{
		printf("Entrada inválida. Por favor, insira uma opção válida.\n");
		while ((controle = getchar()) != '\n' && controle != EOF);
	}

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

	case 10:
		beijo(opcao, pilha);
		break;

	default:
		printf("Opcao invalida. Por favor, escolha uma opcao valida.\n");
		system("pause");
		break;
	}
}

void tela_login(int opcao, int controle, struct Pilha* pilha)
{
	system("clear||cls");
	printf("*******************************************************************************\n");
	printf("***             = = = = = Menu de login = = = = =                           ***\n");
	printf("***                                                                         ***\n");
	printf("***             1. Administrador                                            ***\n");
	printf("***             2. Funcionario                                              ***\n");
	printf("***             3. Cliente                                                  ***\n");
	printf("***             0. Voltar                                                   ***\n");
	printf("***                                                                         ***\n");
	printf("*******************************************************************************\n");
	printf("Como deseja entrar no sistema?\n");
	while (scanf("%d", &opcao) != 1)
	{
		printf("Entrada invalida. Por favor, insira uma opcao valida.\n");
		while ((controle = getchar()) != '\n' && controle != EOF);
	}

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

	default:
		printf("Opcao invalida. Por favor, escolha uma opcao valida.\n");
		system("pause");
		break;
	}
}

void tela_info_projeto(int opcao, int controle, struct Pilha* pilha)
{
	system("clear||cls");
	printf("*******************************************************************************\n");
	printf("***             = = = = = informações sobre o projeto = = = = =             ***\n");
	printf("***                                                                         ***\n");
	printf("***             O Programa gerencia o funcionamento de uma hamburgueria     ***\n");
	printf("***       para fins didaticos de ilustração. O programa contem os principais***\n");
	printf("***       e funcionalidades que serao exigidos na avaliacao dos projetos    ***\n");
	printf("***       desenvolvidos pelos alunos ao longo da disciplina. Serve como u   ***\n");
	printf("***       de consulta e referência para o desenvolvidos dos demais projetos ***\n");
	printf("***                                                                         ***\n");
	printf("*******************************************************************************\n");
	printf("Insira 0 para voltar\n");
	while (scanf("%d", &opcao) != 1)
	{
		printf("Entrada invalida. Por favor, insira uma opcao valida.\n");
		while ((controle = getchar()) != '\n' && controle != EOF); // Limpar o buffer
	}

	if (opcao == 0)
	{
		desempilhar(pilha);
	}
}

void tela_info_equipe(int opcao, int controle, struct Pilha* pilha)
{
	system("clear||cls");
	printf("*******************************************************************************\n");
	printf("***             = = = = = informacoes sobre Equipe responsavel = = = = =    ***\n");
	printf("***                                                                         ***\n");
	printf("***             Este projeto exemplo foi desenvolvido por:                  ***\n");
	printf("***             Emerson da Silva santos                                     ***\n");
	printf("***             E-mail: emerson.santos.125@ufrn.edu.br                      ***\n");
	printf("***             Git: https://github.com/Simio123/Projeto_hamburgueria.git   ***\n");
	printf("***                                                                         ***\n");
	printf("*******************************************************************************\n");
	printf("Insira 0 para voltar\n");
	while (scanf("%d", &opcao) != 1)
	{
		printf("Entrada invalida. Por favor, insira uma opcao valida.\n");
		while ((controle = getchar()) != '\n' && controle != EOF); // Limpar o buffer
	}
	empilhar(pilha, EDITA_DADOS_FUNCIONARIOS);

	if (opcao == 0)
	{
		desempilhar(pilha);
	}
}


// Telas secundárias
void administrador(int opcao, int controle, struct Pilha* pilha)
{
	system("clear||cls");
	printf("*******************************************************************************\n");
	printf("***             = = = = = Menu de administrador = = = = =                   ***\n");
	printf("***                                                                         ***\n");
	printf("***             1. Demitir funcionario                                      ***\n");
	printf("***             2. Acessar estoque                                          ***\n");
	printf("***             3. Cadastrar Funcionario                                    ***\n");
	printf("***             4. Exibir funcionarios ativos                               ***\n");
	printf("***             5. Exibir funcionarios inativos                             ***\n");
	printf("***             6. Editar dados dos funcionarios                            ***\n");
	printf("***             7. Recontratar funcionario                                  ***\n");
	printf("***             8. Exibir todos os funcionarios                             ***\n");
	printf("***             0. Voltar                                                   ***\n");
	printf("***                                                                         ***\n");
	printf("*******************************************************************************\n");
	printf("O que deseja fazer?\n");
	while (scanf("%d", &opcao) != 1)
	{
		printf("Entrada invalida. Por favor, insira uma opcao valida.\n");
		while ((controle = getchar()) != '\n' && controle != EOF); // Limpar o buffer
	}

	switch(opcao)
	{
	case 1:
		empilhar(pilha, DESABILITA_FUNCIONARIO);
		break;

	case 2:
		empilhar(pilha, TELA_ESTOQUE);
		break;

	case 3:
		empilhar(pilha, CADASTRO_FUNCIONARIO);
		break;

	case 4:
		empilhar(pilha, LISTAGEM_FUNCIONARIOS);
		break;

	case 5:
		empilhar(pilha, LISTAGEM_FUNCIONARIOS_I);
		break;

	case 6:
		empilhar(pilha, EDITA_DADOS_FUNCIONARIOS);
		break;

	case 7:
		empilhar(pilha, READMITE_FUNCIONARIO);
		break;

	case 8:
		empilhar(pilha, LISTAGEM_TODOS_FUNCIONARIOS);
		break;

	case 0:
		desempilhar(pilha);
		break;

	default:
		printf("Opcao invalida. Por favor, escolha uma opcao valida.\n");
		system("pause");
		break;
	}
}

void funcionario(int opcao, int controle, struct Pilha* pilha)
{
	system("clear||cls");
	printf("*******************************************************************************\n");
	printf("***             = = = = = Menu de funcionario = = = = =                     ***\n");
	printf("***                                                                         ***\n");
	printf("***             1. Editar dados pessoais                                    ***\n");
	printf("***             2. Acessar estoque                                          ***\n");
	printf("***             3. Verificar pedidos                                        ***\n");
	printf("***             0. Voltar                                                   ***\n");
	printf("***                                                                         ***\n");
	printf("*******************************************************************************\n");
	printf("O que deseja fazer?\n");
	while (scanf("%d", &opcao) != 1)
	{
		printf("Entrada invalida. Por favor, insira uma opcao valida.\n");
		while ((controle = getchar()) != '\n' && controle != EOF); // Limpar o buffer
	}

	switch(opcao)
	{
	case 1:
		empilhar(pilha, EDITA_DADOS_FUNCIONARIOS);
		break;

	case 2:
		empilhar(pilha, TELA_ESTOQUE);
		break;

	case 3:
		empilhar(pilha, TELA_PEDIDOS);
		break;

	case 0:
		desempilhar(pilha);
		break;

	default:
		printf("Opcao invalida. Por favor, escolha uma opcao valida.\n");
		system("pause");
		break;
	}
}

void cliente(int opcao, int controle, struct Pilha* pilha)
{
	system("clear||cls");
	printf("*******************************************************************************\n");
	printf("***             = = = = = Menu de cliente = = = = =                         ***\n");
	printf("***                                                                         ***\n");
	printf("***             1. Realizar pedido                                          ***\n");
	printf("***             2. Reservar mesa                                            ***\n");
	printf("***             3. Visualizar cardapio                                      ***\n");
	printf("***             0. Voltar                                                   ***\n");
	printf("***                                                                         ***\n");
	printf("*******************************************************************************\n");
	printf("O que deseja fazer?\n");
	while (scanf("%d", &opcao) != 1)
	{
		printf("Entrada invalida. Por favor, insira uma opcao valida.\n");
		while ((controle = getchar()) != '\n' && controle != EOF); // Limpar o buffer
	}

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

	default:
		printf("Opcao inválida. Por favor, escolha uma opção válida.\n");
		system("pause");
		break;
	}
}

// Telas terciarias
void estoque(int opcao, int controle, struct Pilha* pilha)
{
	system("clear||cls");
	printf("*******************************************************************************\n");
	printf("***             = = = = = Menu Estoque = = = = =                            ***\n");
	printf("***                                                                         ***\n");
	printf("***             1. Editar estoque                                           ***\n");
	printf("***             2. Cadastrar produto                                        ***\n");
	printf("***             3. Retirar produto do estoque                               ***\n");
	printf("***             4. Repor produto no estoque                                 ***\n");
	printf("***             5. Mostrar produtos em estoque                              ***\n");
	printf("***             6. Mostrar produtos fora de estoque                         ***\n");
	printf("***             7. Mostrar estoque completo                                 ***\n");
	printf("***             0. Voltar                                                   ***\n");
	printf("***                                                                         ***\n");
	printf("*******************************************************************************\n");
	printf("O que deseja fazer?\n");
	while (scanf("%d", &opcao) != 1)
	{
		printf("Entrada invalida. Por favor, insira uma opcao valida.\n");
		while ((controle = getchar()) != '\n' && controle != EOF); // Limpar o buffer
	}

	switch(opcao)
	{
	case 1:
		empilhar(pilha, EDITA_DADOS_PRODUTOS);
		break;

	case 2:
		empilhar(pilha, CADASTRO_PRODUTO);
		break;

	case 3:
		empilhar(pilha, DESABILITA_PRODUTO);
		break;

	case 4:
		empilhar(pilha, REPOE_PRODUTO);
		break;

	case 5:
		empilhar(pilha, LISTAGEM_PRODUTOS);
		break;

	case 6:
		empilhar(pilha, LISTAGEM_PRODUTOS_I);
		break;

	case 7:
		empilhar(pilha, LISTAGEM_TODOS_PRODUTOS);
		break;

	case 0:
		desempilhar(pilha);
		break;

	default:
		printf("Opcao invalida. Por favor, escolha uma opcao valida.\n");
		system("pause");
		break;
	}
}

void pedidos(int opcao, int controle, struct Pilha* pilha)
{
	system("clear||cls");
	printf("*******************************************************************************\n");
	printf("***             = = = = = Menu Pedidos = = = = =                            ***\n");
	printf("***                                                                         ***\n");
	printf("***             1. Finalizar pedidos                                        ***\n");
	printf("***             2. Visualizar pedidos                                       ***\n");
	printf("***             0. Voltar                                                   ***\n");
	printf("***                                                                         ***\n");
	printf("*******************************************************************************\n");
	printf("O que deseja fazer?\n");
	while (scanf("%d", &opcao) != 1)
	{
		printf("Entrada invalida. Por favor, insira uma opcao valida.\n");
		while ((controle = getchar()) != '\n' && controle != EOF); // Limpar o buffer
	}

	switch(opcao)
	{
	case 1:
		printf("Tela");
		break;

	case 2:
		printf("Tela");
		break;

	case 0:
		desempilhar(pilha);
		break;

	default:
		printf("Opcao invalida. Por favor, escolha uma opcao valida.\n");
		system("pause");
		break;
	}
}

void relatorios(int opcao, int controle, struct Pilha* pilha)
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
	printf("O que deseja exibir?\n");
	while (scanf("%d", &opcao) != 1)
	{
		printf("Entrada invalida. Por favor, insira uma opcao valida.\n");
		while ((controle = getchar()) != '\n' && controle != EOF); // Limpar o buffer
	}

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

	default:
		printf("Opcao invalida. Por favor, escolha uma opção valida.\n");
		system("pause");
		break;
	}
}

void delivery(int opcao, int controle, struct Pilha* pilha)
{
	system("clear||cls");
	printf("*******************************************************************************\n");
	printf("***             = = = = = Menu delivery = = = = =                           ***\n");
	printf("***                                                                         ***\n");
	printf("***             1. Finalizar pedido                                         ***\n");
	printf("***             2. Rastrear pedido                                       	***\n");
	printf("***             3. Visualizar pedidos                                       ***\n");
	printf("***             0. Voltar                                                   ***\n");
	printf("***                                                                         ***\n");
	printf("*******************************************************************************\n");
	printf("O que deseja fazer?\n");
	while (scanf("%d", &opcao) != 1)
	{
		printf("Entrada invalida. Por favor, insira uma opcao valida.\n");
		while ((controle = getchar()) != '\n' && controle != EOF); // Limpar o buffer
	}

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

	default:
		printf("Opcao invalida. Por favor, escolha uma opcao valida.\n");
		system("pause");
		break;
	}
}

void opcoes_de_pagamento(int opcao, int controle, struct Pilha* pilha)
{
	system("clear||cls");
	printf("*******************************************************************************\n");
	printf("***             = = = = = Menu pagamento = = = = =                          ***\n");
	printf("***                                                                         ***\n");
	printf("***             1. Dinheiro                                                 ***\n");
	printf("***             2. Cartao de credito                                        ***\n");
	printf("***             3. Cartao de debito                                       	***\n");
	printf("***             4. Transferencia bancaria                                   ***\n");
	printf("***             5. Pix                                                      ***\n");
	printf("***             0. Voltar                                                   ***\n");
	printf("***                                                                         ***\n");
	printf("*******************************************************************************\n");
	printf("Qual a forma de pagamento desejada?\n");
	while (scanf("%d", &opcao) != 1)
	{
		printf("Entrada invalida. Por favor, insira uma opcao valida.\n");
		while ((controle = getchar()) != '\n' && controle != EOF); // Limpar o buffer
	}

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

	default:
		printf("Opcao invalida. Por favor, escolha uma opcao valida.\n");
		system("pause");
		break;
	}
}

// easter eggs
void beijo(int opcao, struct Pilha* pilha)
{
	system("clear||cls");
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
}
