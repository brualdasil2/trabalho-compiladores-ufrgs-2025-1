#include "tabela_simbolos.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

tabela_simbolos_t* init_tabela() {
    tabela_simbolos_t* tabela = (tabela_simbolos_t*) malloc(sizeof(tabela_simbolos_t));
    tabela->itens = (item_tabela_t*) malloc(DELTA_TAM*sizeof(item_tabela_t));
    tabela->tamanho_usado = 0;
    tabela->tamanho_total = DELTA_TAM;
    tabela->is_global = 0;
    return tabela;
}

void insere_item_tabela_simbolos(tabela_simbolos_t* tabela, item_tabela_t item) {
    if (tabela->tamanho_usado == tabela->tamanho_total) {
        tabela->tamanho_total += DELTA_TAM;
        tabela->itens = (item_tabela_t*) realloc(tabela->itens, tabela->tamanho_total*sizeof(item_tabela_t));
    }
    item.is_global = tabela->is_global;
    // calcula offset a partir do offset do ultimo int adicionado
    item.offset = 0;
    for (int i = tabela->tamanho_usado-1; i >= 0; i--) {
        if (tabela->itens[i].natureza != NAT_IDENTIFICADOR) {
            continue;
        }
        item.offset = tabela->itens[i].offset + TAM_INT;
        break;
    }
    
    tabela->itens[tabela->tamanho_usado] = item;
    tabela->tamanho_usado++;
    if (PRINTS_DEBUG_TABELA)
        printf("Inseriu item %s na tabela, novo tam = %lu\n", item.chave, tabela->tamanho_usado);
}

item_tabela_t* busca_item_tabela_simbolos(tabela_simbolos_t* tabela, char* chave) {
    for (int i = 0; i < tabela->tamanho_usado; i++) {
        if (!strcmp(tabela->itens[i].chave, chave)) {
            return &(tabela->itens[i]);
        }
    }
    return NULL;
}

void free_tabela_simbolos(tabela_simbolos_t* tabela) {
    for (int i = 0; i < tabela->tamanho_usado; i++) {
        free(tabela->itens[i].chave);
        free(tabela->itens[i].argumentos.itens);
    }
    free(tabela->itens);
    free(tabela);
}