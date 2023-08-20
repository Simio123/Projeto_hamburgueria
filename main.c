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

/* Assinatura das funções de telas */
/* Telas principais*/
void boas_vindas(void);
void login(void);
void info_projeto(void);
void info_equipe(void);
void menu_principal(void);


/* Funções auxiliares*/
void valida_cpf(void);
void salva_arquivos(void);
void recupera_arquivos(void);
void mensagem_erros_numericos(void);
void mensagem_erros_caracteres(void);
void emissao_nota_fiscal(void);
void pesquisa_pessoas(void);
void pesquisa_pedidos(void);

int main(void){




    return 0;
}

void boas_vindas(void){
    char opcao;
    system("clear||cls");
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
    scanf("%c", &opcao);
}

void login(void){
    char opcao;
    system("clear||cls");
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
    scanf("%c", &opcao);
}

void info_projeto(void);
{








}
void info_equipe(void);

void menu_principal(void) {
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
}
