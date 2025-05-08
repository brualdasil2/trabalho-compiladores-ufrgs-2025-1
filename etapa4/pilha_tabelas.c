#include "pilha_tabelas.h"
#include <stdlib.h>
#include <string.h>

pilha_tabelas_t pilha;

void init_pilha_tabelas() {
    pilha.tabelas = (tabela_simbolos_t**) malloc(DELTA_TAM*sizeof(tabela_simbolos_t*));
    pilha.tamanho_usado = 0;
    pilha.tamanho_total = DELTA_TAM;
}

void push_pilha_tabelas(tabela_simbolos_t* tabela){
    if (pilha.tamanho_usado == pilha.tamanho_total) {
        pilha.tamanho_total += DELTA_TAM;
        pilha.tabelas = (tabela_simbolos_t**) realloc(pilha.tabelas, pilha.tamanho_total*sizeof(tabela_simbolos_t**));
    }
    pilha.tabelas[pilha.tamanho_usado] = tabela;
    pilha.tamanho_usado++;
}

status_t pop_pilha_tabelas(){
    if (pilha.tamanho_usado == 0) {
        return STATUS_ERR;
    }
    free_tabela_simbolos(pilha.tabelas[pilha.tamanho_usado-1]);
    pilha.tamanho_usado--;
    return STATUS_OK;
}

tabela_simbolos_t* get_tabela_topo_pilha() {
    return pilha.tabelas[pilha.tamanho_usado-1];
}

item_tabela_t* buscar_item_pilha_tabelas(char* chave){
    item_tabela_t* item;
    // percorre a pilha do topo até a base, importante pra priorizar o escopo local
    for (int i = pilha.tamanho_usado-1; i >= 0; i--) {
        item = busca_item_tabela_simbolos(pilha.tabelas[i], chave);
        if (item != NULL) {
            return item;
        }
    }
    return NULL;
}

void free_pilha_tabelas() {
    for (int i = 0; i < pilha.tamanho_usado; i++) {
        free_tabela_simbolos(pilha.tabelas[i]);
    }
    free(pilha.tabelas);
}