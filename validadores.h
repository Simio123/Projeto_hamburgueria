#ifndef VALIDADORES_H
#define VALIDADORES_H

#include <stdbool.h>

bool recebe_nome(const char* nome_v);
bool recebe_cpf(const char* cpf_v);
bool recebe_data(const char* data_v);
bool recebe_email(const char* email_v);
bool recebe_telefone(const char* telefone_v);

bool valida_nome(const char *nome);
bool valida_cpf(const char *cpf);
bool valida_data(const char *data);
bool valida_email(const char *email);
bool valida_telefone(const char *telefone);
#endif
