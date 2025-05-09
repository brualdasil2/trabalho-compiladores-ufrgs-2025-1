#include "item_tabela.h"
#include <stdlib.h>

void init_array_item_tabela(array_item_tabela_t* array) {
    array->itens = (item_tabela_t*) malloc(DELTA_TAM*sizeof(item_tabela_t));
    array->tamanho_usado = 0;
    array->tamanho_total = DELTA_TAM;
}

void insere_item_array_item_tabela(array_item_tabela_t* array, item_tabela_t item) {
    if (array->tamanho_usado == array->tamanho_total) {
        array->tamanho_total += DELTA_TAM;
        array->itens = (item_tabela_t*) realloc(array->itens, array->tamanho_total*sizeof(item_tabela_t));
    }
    array->itens[array->tamanho_usado] = item;
    array->tamanho_usado++;
}

void free_array_item_tabela(array_item_tabela_t* array) {
    for (int i = 0; i < array->tamanho_usado; i++) {
        free(array->itens[i].chave);
        free(array->itens[i].argumentos.itens);
    }
    free(array->itens);
}