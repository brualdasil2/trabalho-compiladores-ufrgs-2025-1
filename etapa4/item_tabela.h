#ifndef ITEM_TABELA_H
#define ITEM_TABELA_H
#include "utils.h"
#include "argumento.h"

typedef enum { LITERAL, IDENTIFICADOR, FUNCAO } natureza_t;


typedef struct s_item_tabela_t {
    char* chave;
    natureza_t natureza;
    tipo_t tipo;
    array_argumento_t argumentos;
} item_tabela_t;

typedef struct s_array_item_tabela_t {
    item_tabela_t* itens;
    size_t tamanho_usado;
    size_t tamanho_total;
} array_item_tabela_t;

void init_array_item_tabela(array_item_tabela_t* array);
void insere_item_array_item_tabela(array_item_tabela_t* array, item_tabela_t item);
void free_array_item_tabela(array_item_tabela_t* array);

#endif // ITEM_TABELA_H