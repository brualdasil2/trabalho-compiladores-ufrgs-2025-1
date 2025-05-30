#ifndef ILOC_H
#define ILOC_H

#include "utils.h"

#define MAX_CHARS_ROTULO_ILOC 10
#define MAX_CHARS_OPERANDO_ILOC 10
#define MAX_CHARS_MNEMONICO_ILOC 10

typedef struct s_rotulo_iloc {
    char valor[MAX_CHARS_ROTULO_ILOC];
} rotulo_iloc_t;

typedef struct s_operando_iloc {
    char valor[MAX_CHARS_OPERANDO_ILOC];
} operando_iloc_t;

typedef struct s_mnemonico_iloc {
    char valor[MAX_CHARS_MNEMONICO_ILOC];
} mnemonico_iloc_t;

typedef struct s_op_iloc {
    rotulo_iloc_t rotulo;
    mnemonico_iloc_t mnemonico;
    operando_iloc_t op1;
    operando_iloc_t op2;
    operando_iloc_t op3;
} op_iloc_t;

typedef struct s_array_op_iloc {
    op_iloc_t* ops;
    size_t tamanho_usado;
    size_t tamanho_total;
} array_op_iloc_t;

op_iloc_t init_op_iloc();
op_iloc_t init_op_load_var(int offset, int is_global);
op_iloc_t init_op_load_0();
op_iloc_t init_op_store_var(int offset, int is_global, operando_iloc_t temp);
op_iloc_t init_op_3(char* mnemonico, operando_iloc_t op1, operando_iloc_t op2);
op_iloc_t init_op_cbr(operando_iloc_t test, rotulo_iloc_t rot_true, rotulo_iloc_t rot_false);
op_iloc_t init_op_jump(rotulo_iloc_t rot);
void gera_rotulo(rotulo_iloc_t* rotulo);
void gera_temp(operando_iloc_t* operando);
void set_operando_int(operando_iloc_t* operando, int valor);
void init_array_op_iloc(array_op_iloc_t* array);
void insere_item_array_op_iloc(array_op_iloc_t* array, op_iloc_t item);
void free_array_op_iloc(array_op_iloc_t* array);
void append_array_op_iloc(array_op_iloc_t* dst, array_op_iloc_t* src);
void print_array_op_iloc(array_op_iloc_t array);

/*

HEAP:

x.code -> OP1x OP2x OP3x OP4x
asdasd
y.code -> OP1y OP2y OP3y OP4y

x.code = array de op_iloc 
y.code = array de op_iloc 
op.code = array de op_iloc vazio
append_array_op_iloc(op.code, x.code)
    chama insere_item() pra cada item de x.code em op.code
    free_array_op_iloc(x.code)
append_array_op_iloc(op.code, y.code)
    chama insere_item() pra cada item de y.code em op.code
    free_array_op_iloc(y.code)

*/

#endif