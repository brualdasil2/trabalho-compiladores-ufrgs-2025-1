#ifndef PILHA_TABELAS_H
#define PILHA_TABELAS_H
#include "tabela_simbolos.h"
#include "utils.h"

#define PRINTS_DEUBG_PILHA 0

typedef struct s_pilha_tabelas_t {
    tabela_simbolos_t** tabelas;
    size_t tamanho_usado;
    size_t tamanho_total;
} pilha_tabelas_t;

void init_pilha_tabelas();
void push_pilha_tabelas(tabela_simbolos_t* tabela);
status_t pop_pilha_tabelas();
tabela_simbolos_t* get_tabela_topo_pilha();
item_tabela_t* buscar_item_pilha_tabelas(char* chave);
void free_pilha_tabelas();

#endif