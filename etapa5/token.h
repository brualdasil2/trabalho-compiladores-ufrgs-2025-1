#ifndef TOKEN_H
#define TOKEN_H

#include "utils.h"

typedef enum { TIPO_IDENTIFICADOR, TIPO_LITERAL, TIPO_NO } tipo_token_t;
typedef struct {
    char* lexema;
    int linha_token;
    tipo_token_t tipo;
    tipo_dado_t tipo_dado_inferido;
} valor_t;

#endif // TOKEN_H