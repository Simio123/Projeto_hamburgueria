#ifndef VALIDADORES_H
#define VALIDADORES_H

#include <stdbool.h>

bool recebe_nome(char* nome_v);
bool recebe_cpf(char* cpf_v);
bool recebe_data(char* data_v);
bool recebe_email(char* email_v);
bool recebe_telefone(char* telefone_v);

bool valida_nome(char *nome);
bool valida_cpf(char *cpf);
bool valida_data(char *data);
bool valida_email(char *email);
bool valida_telefone(char *telefone);
#endif
