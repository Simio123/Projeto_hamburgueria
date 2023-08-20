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

/* Funções de exibição de telas */

/* Tela de login*/
void login(void);

/* Tela principal*/
void menu_principal(void);

/* Telas de funcionários */
void menu_funcionarios(void);
void cadastrar_funcionario(void);
void descadastrar_funcionario(void);
void promover_funcionario(void);
void rebaixar_funcionario(void);
void informacoes_funcionario(void);

/* Telas de mesas */
void menu_mesas(void);
void adicionar_mesa(void);
void retirar_mesa(void);
void informacoes_mesas(void);

/* Telas de pedidos */
void menu_pedidos(void);
void tipo_pedido(void);
void cadastrar_pedido(void);
void cancelar_pedido(void);
void informacoes_pedido(void);

/* Funções auxiliares*/
void valida_cpf(void);
void salva_arquivos(void);
void recupera_arquivos(void);
void mensagem_erros_numericos(void);
void mensagem_erros_caracteres(void);
void emissao_nota_fiscal(void);

int main(void){




    return 0;
}

void login(void){









    
}





void menu_principal(void) {
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
    printf("***             = = = = = Sistema de Gestão de Hamburgueria = = = = =       ***\n");
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
    getchar();
}
