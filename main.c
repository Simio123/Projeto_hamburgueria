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
#include <locale.h>
#include "telas.h"
#include "validadores.h"
#include "pessoas.h"
#include "produtos.h"
#include "inserir_dados.h"

int main()
{
	struct Pilha* pilha = criarPilha();
	empilhar(pilha, TELA_INICIAL);
	executarTela(pilha);
	return 0;
}
