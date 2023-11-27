/******************************************************************************
***             Universidade Federal do Rio Grande do Norte                 ***
***             Centro de Ensino Superior do Seridó                         ***
***             Departamento de Computação e Tecnologia                     ***
***             Disciplina: Programação                                     ***
***             Professor: Flavius Gorgonio                                 ***
***             Projeto: Sistema de Gestão de Hamburgueria                  ***
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
#include "inserir_dados.h"

int main()
{
	struct Pilha* pilha = criarPilha();
	empilhar(pilha, TELA_INICIAL);
	executarTela(pilha);

	return 0;
}
