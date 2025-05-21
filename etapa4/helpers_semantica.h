#ifndef HELPERS_SEMANTICA_H
#define HELPERS_SEMANTICA_H
#include "pilha_tabelas.h"
#include "tabela_simbolos.h"
#include "erros.h"
#include <stdlib.h>
#include <stdio.h>

void check_declared(char* identificador);

void insere_variavel_tabela(valor_t valor_original, tipo_dado_t tipo_dado);

#endif // HELPERS_SEMANTICA_H