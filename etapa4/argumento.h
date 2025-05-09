#ifndef ARGUMENTO_H
#define ARGUMENTO_H
#include "utils.h"


typedef struct s_argumento_t {
    tipo_t tipo;
} argumento_t;

typedef struct s_array_argumento_t {
    argumento_t* itens;
    size_t tamanho_usado;
    size_t tamanho_total;
} array_argumento_t;

void init_array_argumento(array_argumento_t* array);
void insere_item_array_argumento(array_argumento_t* array, argumento_t item);
void free_array_argumento(array_argumento_t* array);


#endif