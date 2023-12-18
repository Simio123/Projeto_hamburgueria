/******************************************************************************
***             Universidade Federal do Rio Grande do Norte                 ***
***             Centro de Ensino Superior do Serido                         ***
***             Departamento de Computacao e Tecnologia                     ***
***             Disciplina: Programacao                                     ***
***             Professor: Flavius Gorgonio                                 ***
***             Projeto: Sistema de Gestao de Hamburgueria                  ***
***             Aluno: Emerson da Silva Santos                              ***
***             Linguagem: C                                                ***
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "telas.h"
#include "validadores.h"
#include "produtos.h"
#include "pessoas.h"
#include "inserir_dados.h"
#include "user_input.h"
#include "pedidos.h"

int main()
{
	// Cria a pilha de telas
	struct Pilha* pilha = criarPilha();
	// Coloca a tela principal como primeiro elemento da pilha
	empilhar(pilha, TELA_INICIAL);
	// Executa a fun��o de empilhamento
	executarTela(pilha);
	return 0;
}

/* Utilizei a navega��o por pilha, colocando uma tela por cima da outra quando conforme
se avan�a no crud e desempilhando conforme volta nele, a filha funciona no modelo de FILO
first in,last out o useja, o a primeira tela empilhada � a ultima a ser desempilhada
no caso do programa a primeira tela � sempre atela inicial e o programa roda at� que essa
tela esteja na pilha */

