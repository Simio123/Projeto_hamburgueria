#ifndef VALIDADORES_H
#define VALIDADORES_H

#include <stdbool.h>

bool recebe_nome();
bool recebe_cpf();
bool recebe_data();
bool recebe_email();
bool recebe_telefone();

bool valida_nome(const char *nome);
bool valida_cpf(const char *cpf);
bool valida_data(const char *data);
bool valida_email(const char *email);
bool valida_telefone(const char *telefone);
#endif
