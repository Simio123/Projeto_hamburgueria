#ifndef PRODUTOS_H
#define PRODUTOS_H

#include <stdbool.h>

bool recebe_idade(int* idade_v);
bool recebe_salario(double* idade_v);
bool recebe_id(char* id_v, int tipo);
bool recebe_cargo(char* cargo_v);
bool recebe_endereco(char* endereco_v);

bool recebe_preco(double* preco_v);
bool recebe_tipo(char* tipo_v);
bool recebe_quantidade(int* quantidade_v);
#endif
