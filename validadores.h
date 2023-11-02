#ifndef VALIDADORES_H
#define VALIDADORES_H

#include <stdbool.h>


void recebe_nome();
void recebe_cpf();
void recebe_data();

bool valida_nome(const char *nome);
bool valida_cpf(const char *cpf);
bool valida_data(const char *data);


#endif
