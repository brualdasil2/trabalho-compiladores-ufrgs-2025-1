#ifndef TOKEN_H
#define TOKEN_H

typedef enum { IDENTIFICADOR, LITERAL } tipo_token_t;
typedef struct {
    char* lexema;
    int linha_token;
    tipo_token_t tipo;
} valor_t;

#endif // TOKEN_H