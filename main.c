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

/* Bibliotecas */
#include<stdio.h>
#include<stdlib.h> 

#include "defs.h"

int main(void){

const char *screen_type_str[] {

};

typedef enum {

} Screen;



    return 0;
}

int boas_vindas(int opcao1){
    system("cls");
    printf("\n");
    printf("*******************************************************************************\n");
    printf("***             Universidade Federal do Rio Grande do Norte                 ***\n");
    printf("***             Centro de Ensino Superior do Seridó                         ***\n");
    printf("***             Departamento de Computação e Tecnologia                     ***\n");
    printf("***             Disciplina: Programação                                     ***\n");
    printf("***             Professor: Flavius Gorgonio                                 ***\n");
    printf("***             Projeto: Sistema de Gestão de Hamburgueria                  ***\n");
    printf("***             Aluno: Emerson da Silva Santos                              ***\n");
    printf("***             Linguagem: C                                                ***\n");
    printf("*******************************************************************************\n");
    printf("*******************************************************************************\n");
    printf("***   = = = = =  Bem vindo ao Sistema de Gestão de Hamburgueria = = = = =   ***\n");
    printf("***                                                                         ***\n");
    printf("***             1. Login                                                    ***\n");
    printf("***             2. Consultar informações sobre o projeto                    ***\n");
    printf("***             3. Consultar informações sobre Equipe responsavel           ***\n");
    printf("***             0. Sair                                                     ***\n");
    printf("***                                                                         ***\n");
    printf("*******************************************************************************\n");
    printf("O que deseja fazer?\n");
    scanf("%d", &opcao1);
    return opcao1;
}

int login(int opcao1){
    system("cls");
    printf("*******************************************************************************\n");
    printf("***             = = = = = Menu de login = = = = =                           ***\n");
    printf("***                                                                         ***\n");
    printf("***             1. Administrador                                            ***\n");
    printf("***             2. Funcionário                                              ***\n");
    printf("***             3. Cliente                                                  ***\n");
    printf("***             0. Sair                                                     ***\n");
    printf("***                                                                         ***\n");
    printf("*******************************************************************************\n");
    printf("Como deseja entrar no sistema?\n");
    scanf("%d", &opcao1);
    return opcao1;
}

void info_projeto(void);{
    system("cls");
    printf("*******************************************************************************\n");
    printf("***             = = = = = informações sobre o projeto = = = = =             ***\n");
    printf("***                                                                         ***\n");
    printf("***             O Programa gerencia o funcionamento de uma hamburgueria     ***\n");
    printf("***       fins didáticos de ilustração. O programa contém os principais     ***\n");
    printf("***       e funcionalidades que serão exigidos na avaliação dos projetos    ***\n");
    printf("***       desenvolvidos pelos alunos ao longo da disciplina. Serve como u   ***\n");
    printf("***       de consulta e referência para o desenvolvidos dos demais proje    ***\n");
    printf("***                                                                         ***\n");
    printf("*******************************************************************************\n");
    system("pause");
    boas_vindas(opcao);
}

void info_equipe(void){
    system("clear||cls");
    printf("*******************************************************************************\n");
    printf("***             = = = = =informações sobre Equipe responsavel = = = = =     ***\n");
    printf("***                                                                         ***\n");
    printf("***             Este projeto exemplo foi desenvolvido por:                  ***\n");
    printf("***             Emerson da Silva santos                                     ***\n");
    printf("***             E-mail: emerson.santos.125@ufrn.edu.br                      ***\n");
    printf("***             Git: https://github.com/Simio123/Projeto_hamburgueria.git   ***\n");
    printf("***                                                                         ***\n");
    printf("*******************************************************************************\n");
    system("pause");
    boas_vindas(opcao);
}

int menu_principal() {
    char opcao;
    system("clear||cls");
    printf("*******************************************************************************\n");
    printf("***             = = = = = Menu principal = = = = =                          ***\n");
    printf("***                                                                         ***\n");
    printf("***             1. Módulo Aluno                                             ***\n");
    printf("***             2. Módulo Professor                                         ***\n");
    printf("***             3. Módulo Turma                                             ***\n");
    printf("***             4. Módulo Matrícula                                         ***\n");
    printf("***             5. Módulo Relatórios                                        ***\n");
    printf("***             0. Sair                                                     ***\n");
    printf("***                                                                         ***\n");
    printf("*******************************************************************************\n");
    printf("Escolha uma opcao\n");
    scanf("%c", &opcao);
    return opcao;
}
