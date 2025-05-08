#include "tabela_simbolos.h"
#include "hash.h"
#include <string.h>
#include <stdlib.h>

tabela_simbolos_t* init_tabela() {
    tabela_simbolos_t* tabela = (tabela_simbolos_t*) malloc(sizeof(tabela_simbolos_t));
    for (int i = 0; i < TAM_TABELA; i++) {
        init_array_item_tabela(&(tabela->arrays[i]));
    }
    return tabela;
}

status_t insere_item_tabela_simbolos(tabela_simbolos_t* tabela, item_tabela_t item) {
    unsigned int hash_item = hash(item.chave, TAM_TABELA);
    for (int i = 0; i < tabela->arrays[hash_item].tamanho_usado; i++) {
        if (!strcmp(item.chave, tabela->arrays[hash_item].itens[i].chave)) {
            return STATUS_ERR;
        }
    }
    // item não existe, pode inserir
    insere_item_array_item_tabela(&(tabela->arrays[hash_item]), item);
    return STATUS_OK;
}

item_tabela_t* busca_item_tabela_simbolos(tabela_simbolos_t* tabela, char* chave) {
    unsigned int hash_item = hash(chave, TAM_TABELA);
    for (int i = 0; i < tabela->arrays[hash_item].tamanho_usado; i++) {
        if (!strcmp(chave, tabela->arrays[hash_item].itens[i].chave)) {
            return &(tabela->arrays[hash_item].itens[i]);
        }
    }
    return NULL;
}

void free_tabela_simbolos(tabela_simbolos_t* tabela) {
    for (int i = 0; i < TAM_TABELA; i++) {
        if (tabela->arrays[i].itens != NULL) {
            free_array_item_tabela(&(tabela->arrays[i]));
        }
    }
    free(tabela);
}