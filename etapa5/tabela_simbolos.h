#ifndef TABELA_SIMBOLOS_H
#define TABELA_SIMBOLOS_H
#include "utils.h"
#include "argumento.h"
#include "token.h"

typedef enum { NAT_LITERAL, NAT_IDENTIFICADOR, NAT_FUNCAO } natureza_t;

#define PRINTS_DEBUG_TABELA 0
#define TAM_INT 4


typedef struct s_item_tabela_t {
    char* chave;
    natureza_t natureza;
    tipo_dado_t tipo_dado;
    array_argumento_t argumentos;
    int linha_token;
    int offset;
    int is_global;
} item_tabela_t;

typedef struct s_tabela_simbolos_t {
    item_tabela_t* itens;
    size_t tamanho_usado;
    size_t tamanho_total;
    int is_global;
} tabela_simbolos_t;

tabela_simbolos_t* init_tabela();
void insere_item_tabela_simbolos(tabela_simbolos_t* tabela, item_tabela_t item);
void free_tabela_simbolos(tabela_simbolos_t* tabela);
item_tabela_t* busca_item_tabela_simbolos(tabela_simbolos_t* tabela, char* chave);

#endif // TABELA_SIMBOLOS_H