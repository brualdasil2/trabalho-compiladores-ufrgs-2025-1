#ifndef TOKEN_H
#define TOKEN_H

#include "utils.h"
#include "iloc.h"

typedef enum { TIPO_IDENTIFICADOR, TIPO_LITERAL, TIPO_NO } tipo_token_t;
typedef struct {
    char* lexema;
    int linha_token;
    tipo_token_t tipo;
    tipo_dado_t tipo_dado_inferido;
    array_op_iloc_t code;
    operando_iloc_t temp;
} valor_t;

#endif // TOKEN_H