#ifndef TABELA_H
#define TABELA_H
#include "item_tabela.h"

#define TAM_TABELA 512

typedef struct s_tabela_simbolos_t {
    array_item_tabela_t arrays[TAM_TABELA];
} tabela_simbolos_t;

tabela_simbolos_t* init_tabela();
status_t insere_item_tabela_simbolos(tabela_simbolos_t* tabela, item_tabela_t item);
item_tabela_t* busca_item_tabela_simbolos(tabela_simbolos_t* tabela, char* chave);
void free_tabela_simbolos(tabela_simbolos_t* tabela);

#endif // TABELA_H