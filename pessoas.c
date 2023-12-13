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

void legenda_funcionario(void)
{
	system("clear||cls");
	printf("*******************************************************************************\n");
	printf("***           = = = = = Menu de cadastro de funcionário = = = = =           ***\n");
	printf("*******************************************************************************\n");
}

Pessoa* cadastro_funcionario(struct Pilha * pilha)
{
	Pessoa *funcionario = malloc(sizeof(Pessoa));

	int controle = 0, status_v = 1, tipo = 0;
	double salario_v;
	char id_v[17], nome_v[100], cargo_v[100], email_v[150], telefone_v[20], cpf_v[12], data_v[11];

	while (controle != 3)
	{
		legenda_funcionario();
		printf("Insira o cpf do funcionario(apenas numeros):");
		limpar_buffer();
		recebe_cpf(cpf_v);

		legenda_funcionario();
		printf("Insira o nome do funcionario(apenas letras):");
		recebe_nome(nome_v);

		legenda_funcionario();
		printf("Insira a data da contratacao(no formato xx/xx/xxxx):");
		recebe_data(data_v);

		legenda_funcionario();
		printf("Insira o cargo do funcionario(apenas letras):");
		recebe_cargo(cargo_v);

		legenda_funcionario();
		printf("Insira o salario do funcionario(apenas numeros):");
		recebe_salario(&salario_v);

		legenda_funcionario();
		printf("Insira o id do funcionario:");
		recebe_id(id_v, tipo);

		legenda_funcionario();
		printf("Insira o email do funcionario:");
		recebe_email(email_v);

		legenda_funcionario();
		printf("Insira o telefone do funcionario(no formato(xx)xxxxx-xxxx):");
		recebe_telefone(telefone_v);

		if (funcionario != NULL)
		{
			funcionario->status = status_v;
			funcionario->salario = salario_v;
			strncpy(funcionario->id, id_v, 17);
			strncpy(funcionario->nome, nome_v, 100);
			strncpy(funcionario->cargo, cargo_v, 100);
			strncpy(funcionario->email, email_v, 150);
			strncpy(funcionario->telefone, telefone_v, 20);
			strncpy(funcionario->cpf, cpf_v, 12);
			strncpy(funcionario->data, data_v, 11);

			controle = 3;
		}
		else
		{
			printf("Falha na alocação de memória\n");
		}
	}
	salva_funcionario(funcionario);

	printf("Funcionário cadastrado com sucesso\n");
	system("pause");
	system("clear||cls");
	desempilhar(pilha);

	return funcionario;
	free(funcionario);
}

void salva_funcionario(Pessoa * funcionario)
{
	FILE* file = fopen("funcionarios.dat", "ab");

	if (file == NULL)
	{
		printf("Erro ao abrir o arquivo para escrita.\n");
		return;
		fclose(file);
	}
	else
	{
		fwrite(funcionario, sizeof(Pessoa), 1, file);
		fclose(file);
	}
}

void listagem_funcionarios(struct Pilha * pilha)
{
	Pessoa funcionario;
	system("clear||cls");
	printf("*******************************************************************************\n");
	printf("***              = = = = = Listagem de funcionários = = = = =               ***\n");
	printf("*******************************************************************************\n");

	FILE* file = fopen("funcionarios.dat", "rb");

	if (file == NULL)
	{
		printf("Erro ao abrir o arquivo para leitura ou nao existem funcionarios cadastrados\n");
		fclose(file);
		system("pause");
		desempilhar(pilha);
	}
	else
	{
		printf("|********|************************|*****************|*****************|********************|**********|*************|*****************|***********|\n");
		printf("|Status  |Nome                    |CPF              |Telefone         |Data de contratacao |Salario   |Cargo        |Email            |Id         |\n");

		while (fread(&funcionario, sizeof(Pessoa), 1, file) == 1)
		{
			if (funcionario.status == 1)
			{
				printf("|********|************************|*****************|*****************|********************|**********|*************|*****************|***********|\n");
				printf("|Ativo   |%-24s|%-17s|%-17s|%-20s|%-10.2f|%-13s|%-17s|%-11s| \n", funcionario.nome, funcionario.cpf, funcionario.telefone, funcionario.data, funcionario.salario, funcionario.cargo, funcionario.email, funcionario.id);
			}
		}
		fclose(file);
		system("pause");
		desempilhar(pilha);
	}
}

void listagem_funcionarios_i(struct Pilha * pilha)
{
	Pessoa funcionario;
	system("clear || cls");
	printf("*******************************************************************************\n");
	printf("***              = = = = = Listagem de funcionários = = = = =               ***\n");
	printf("*******************************************************************************\n");

	FILE* file = fopen("funcionarios.dat", "rb");

	if (file == NULL)
	{
		printf("Erro ao abrir o arquivo para leitura ou nao existem funcionarios cadastrados\n");
		fclose(file);
		system("pause");
		desempilhar(pilha);
	}
	else
	{
		printf("\n");
		printf("|********|************************|*****************|*****************|********************|**********|*************|*****************|***********|\n");
		printf("|Status  |Nome                    |CPF              |Telefone         |Data de contratacao |Salario   |Cargo        |Email            |Id         |\n");


		while (fread(&funcionario, sizeof(Pessoa), 1, file) == 1)
		{
			if (funcionario.status == 0)
			{
				printf("|********|************************|*****************|*****************|********************|**********|*************|*****************|***********|\n");
				printf("|Inativo |%-24s|%-17s|%-17s|%-20s|%-10.2f|%-13s|%-17s|%-11s| \n", funcionario.nome, funcionario.cpf, funcionario.telefone, funcionario.data, funcionario.salario, funcionario.cargo, funcionario.email, funcionario.id);
			}
		}
		fclose(file);
		system("pause");
		desempilhar(pilha);
	}
}

void listagem_todos_funcionarios(struct Pilha * pilha)
{
	Pessoa funcionario;
	system("clear || cls");
	printf("*******************************************************************************\n");
	printf("***              = = = = = Listagem de funcionários = = = = =               ***\n");
	printf("*******************************************************************************\n");

	FILE* file = fopen("funcionarios.dat", "rb");

	if (file == NULL)
	{
		printf("Erro ao abrir o arquivo para leitura ou nao existem funcionarios cadastrados\n");
		fclose(file);
		system("pause");
		desempilhar(pilha);
	}

	else
	{
		printf("\n");
		printf("|********|************************|*****************|*****************|********************|**********|*************|*****************|***********|\n");
		printf("|Status  |Nome                    |CPF              |Telefone         |Data de contratacao |Salario   |Cargo        |Email            |Id         |\n");

		while (fread(&funcionario, sizeof(Pessoa), 1, file) == 1)
		{

			if (funcionario.status == 1)
			{
				printf("|********|************************|*****************|*****************|********************|**********|*************|*****************|***********|\n");
				printf("|Ativo   |%-24s|%-17s|%-17s|%-20s|%-10.2f|%-13s|%-17s|%-11s| \n", funcionario.nome, funcionario.cpf, funcionario.telefone, funcionario.data, funcionario.salario, funcionario.cargo, funcionario.email, funcionario.id);
			}
			else
			{
				printf("|********|************************|*****************|*****************|********************|**********|*************|*****************|***********|\n");
				printf("|Inativo |%-24s|%-17s|%-17s|%-20s|%-10.2f|%-13s|%-17s|%-11s| \n", funcionario.nome, funcionario.cpf, funcionario.telefone, funcionario.data, funcionario.salario, funcionario.cargo, funcionario.email, funcionario.id);
			}
		}

		fclose(file);
		system("pause");
		desempilhar(pilha);
	}
}

void editar_dados_funcionarios(struct Pilha * pilha)
{
	int tipo = 0, opc_v;
	double salario_v;
	char id_v[11], nome_v[100], cargo_v[100], email_v[150], telefone_v[20];

	Pessoa funcionario;

	system("clear || cls");
	printf("*******************************************************************************\n");
	printf("***               = = = = = Edição de funcionários = = = = =                ***\n");
	printf("*******************************************************************************\n");

	if(procurar_funcionario(&funcionario, pilha))
	{
		do
		{
			system("clear || cls");
			printf("*******************************************************************************\n");
			printf("***               = = = = = Edição de funcionários = = = = =                ***\n");
			printf("*******************************************************************************\n");

			printf("1 - Editar salario\n");
			printf("2 - Editar id\n");
			printf("3 - Editar nome\n");
			printf("4 - Editar cargo\n");
			printf("5 - Editar email\n");
			printf("6 - Editar telefone\n");
			printf("0 - Voltar\n");
			printf("\n");

			char *opc = get_user_input("O que deseja fazer ? \t");
			opc_v = atoi(opc);
			system("clear || cls");

			switch(opc_v)
			{
			case 1:
				printf("Insira o novo salario do funcionario\t");
				recebe_salario(&salario_v);
				funcionario.salario = salario_v;
				break;

			case 2:
				printf("Insira o novo Id do funcionario\t");
				recebe_id(id_v, tipo);
				strncpy(funcionario.id, id_v , 11);
				break;

			case 3:
				printf("Insira o novo nome do funcionario\t");
				recebe_nome(nome_v);
				strncpy(funcionario.nome, nome_v, 100);
				break;

			case 4:
				printf("Insira o novo cargo do funcionario\t");
				recebe_cargo(cargo_v);
				strncpy(funcionario.cargo, cargo_v, 100);
				break;

			case 5:
				printf("Insira o novo email do funcionario\t");
				recebe_email(email_v);
				strncpy(funcionario.email, email_v, 150);
				break;

			case 6:
				printf("Insira o novo telefone do funcionario\t");
				recebe_telefone(telefone_v);
				strncpy(funcionario.telefone, telefone_v, 20);
				break;

			case 0:
				desempilhar(pilha);
				system("pause");
				break;

			default:
				printf("Opção inválida.\n");
			}
			printf("Alteração realizada\n");
			system("pause");
		}
		while(opc_v != 0);
		atualizar_funcionario(&funcionario);
	}
	else
	{
		printf("Funcionário não encontrado\n");
		system("pause");
		desempilhar(pilha);
	}
}

void atualizar_funcionario(Pessoa * funcionario)
{
	Pessoa tmp;

	FILE* file = fopen("funcionarios.dat", "r+b");

	if (file == NULL)
	{
		printf("Erro ao abrir o arquivo para leitura.\n");
		fclose(file);
		return;
	}

	while (fread(&tmp, sizeof(Pessoa), 1, file) == 1)
	{
		if (tmp.status == 1 && !strcmp(funcionario->cpf, tmp.cpf))
		{
			fseek(file, -sizeof(Pessoa), SEEK_CUR);
			fwrite(funcionario, sizeof(Pessoa), 1, file);

			fclose(file);
			return;
		}
	}
	fclose(file);
}

bool procurar_funcionario(Pessoa * funcionario, struct Pilha * pilha)
{
	limpar_buffer();
	char *cpf_busca = get_user_input("Insira o cpf do funcionario(somente números):\t");

	FILE* file = fopen("funcionarios.dat", "rb");

	if (file == NULL)
	{
		printf("Erro ao abrir o arquivo para leitura.\n");
		return false;
		fclose(file);
		system("pause");
		desempilhar(pilha);
	}
	else
	{
		while (fread(funcionario, sizeof(Pessoa), 1, file) == 1)
		{
			if (funcionario->status == 1 && !strcmp(cpf_busca, funcionario->cpf))
			{
				fclose(file);
				printf("Funcionário encontrado\n");
				system("pause");
				return true;
				desempilhar(pilha);
			}
		}
	}
	return false;
}

void desabilita_funcionario(struct Pilha * pilha)
{
	char cpf_v[12];
	int controle = 0;
	Pessoa funcionario;

	system("clear || cls");
	printf("*******************************************************************************\n");
	printf("***              = = = = = Exclusão de funcionários = = = = =               ***\n");
	printf("*******************************************************************************\n");

	limpar_buffer();
	printf("Insira o cpf do funcionario que deseja demitir(apenas numeros):");
	recebe_cpf(cpf_v);

	FILE* file = fopen("funcionarios.dat", "rb+");

	if (file == NULL)
	{
		printf("Erro ao abrir o arquivo\n");
		return;
	}

	while (fread(&funcionario, sizeof(Pessoa), 1, file) == 1)
	{
		if (strcmp(funcionario.cpf, cpf_v) == 0)
		{
			funcionario.status = 0;
			fseek(file, -sizeof(Pessoa), SEEK_CUR);
			fwrite(&funcionario, sizeof(Pessoa), 1, file);
			controle = 1;
			break;
		}
	}

	if (!controle)
	{
		printf("\n");
		printf("Funcionário não encontrado.\n");
	}
	else
	{
		printf("\n");
		printf("Funcionário desabilitado com sucesso.\n");
	}
	system("pause");
	fclose(file);
	desempilhar(pilha);
}

void readimite_funcionario(struct Pilha * pilha)
{
	char cpf_v[12];
	int controle = 0;
	Pessoa funcionario;

	system("clear || cls");
	printf("*******************************************************************************\n");
	printf("***             = = = = = Readmissão de funcionários = = = = =              ***\n");
	printf("*******************************************************************************\n");

	limpar_buffer();
	printf("Insira o cpf do funcionario que deseja readmitir(apenas numeros):");
	recebe_cpf(cpf_v);

	FILE* file = fopen("funcionarios.dat", "rb+");

	if (file == NULL)
	{
		printf("Erro ao abrir o arquivo\n");
		return;
	}

	while (fread(&funcionario, sizeof(Pessoa), 1, file) == 1)
	{
		if (strcmp(funcionario.cpf, cpf_v) == 0)
		{
			funcionario.status = 1;
			fseek(file, -sizeof(Pessoa), SEEK_CUR);
			fwrite(&funcionario, sizeof(Pessoa), 1, file);
			controle = 1;
			break;
		}
	}

	if (!controle)
	{
		printf("\n");
		printf("Funcionário não encontrado.\n");
	}
	else
	{
		printf("\n");
		printf("Funcionário readmitido com sucesso.\n");
	}
	system("pause");
	fclose(file);
	desempilhar(pilha);
}
