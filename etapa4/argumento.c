#include "argumento.h"
#include <stdlib.h>

void init_array_argumento(array_argumento_t* array) {
    // This MALLOC is not being freed
    array->itens = (argumento_t*) malloc(DELTA_TAM*sizeof(argumento_t));
    array->tamanho_usado = 0;
    array->tamanho_total = DELTA_TAM;
}

void insere_item_array_argumento(array_argumento_t* array, argumento_t item) {
    if (array->tamanho_usado == array->tamanho_total) {
        array->tamanho_total += DELTA_TAM;
        array->itens = (argumento_t*) realloc(array->itens, array->tamanho_total*sizeof(argumento_t));
    }
    array->itens[array->tamanho_usado] = item;
    array->tamanho_usado++;
}
void free_array_argumento(array_argumento_t* array) {
    free(array->itens);
}
