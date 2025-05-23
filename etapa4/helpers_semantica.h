#ifndef HELPERS_SEMANTICA_H
#define HELPERS_SEMANTICA_H
#include "pilha_tabelas.h"
#include "tabela_simbolos.h"
#include "asd.h"
#include "erros.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void check_declared(asd_tree_t* node);
void check_undeclared(asd_tree_t* node);
void check_is_var(asd_tree_t* node);
void check_is_func(asd_tree_t* node);
void check_args(asd_tree_t* node);

void set_tipo_da_tabela(asd_tree_t* no, char* lexema);
void inferencia_tipo_op_binaria(asd_tree_t* op, asd_tree_t* op1, asd_tree_t* op2);
void inferencia_tipo_return(asd_tree_t* retorno, asd_tree_t* exp, tipo_dado_t tipo_retorno);

void insere_params_func_tabela(char* identificador, asd_tree_t* lista_params);
void insere_variavel_tabela(valor_t valor_original, tipo_dado_t tipo_dado);
void insere_funcao_tabela(valor_t valor_original, tipo_dado_t tipo_dado);
void insere_literal_tabela(valor_t valor_original, tipo_dado_t tipo_dado);

#endif // HELPERS_SEMANTICA_H