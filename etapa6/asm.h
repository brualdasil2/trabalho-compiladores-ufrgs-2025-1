#ifndef ASM_H
#define ASM_H

#include "utils.h"

#define MAX_CHARS_ROTULO_ASM 10
#define MAX_CHARS_OPERANDO_ASM 10
#define MAX_CHARS_MNEMONICO_ASM 10

typedef struct s_rotulo_asm {
    char valor[MAX_CHARS_ROTULO_ASM];
} rotulo_asm_t;

typedef struct s_operando_asm {
    char valor[MAX_CHARS_OPERANDO_ASM];
} operando_asm_t;

typedef struct s_mnemonico_asm {
    char valor[MAX_CHARS_MNEMONICO_ASM];
} mnemonico_asm_t;

typedef struct s_op_asm {
    rotulo_asm_t rotulo;
    mnemonico_asm_t mnemonico;
    operando_asm_t op1;
    operando_asm_t op2;
    int op_qtd;
} op_asm_t;

typedef struct s_array_op_asm {
    op_asm_t* ops;
    size_t tamanho_usado;
    size_t tamanho_total;
} array_op_asm_t;

void set_operando_int(operando_asm_t* operando, int valor);
op_asm_t init_op_asm();
op_asm_t init_op_store(int offset, int is_global, operando_asm_t temp);
op_asm_t init_lit(char* lit);
op_asm_t init_op_load_var_to_reg(int offset, int is_global, operando_asm_t temp, char* reg);
op_asm_t init_op_load_lit_to_reg(operando_asm_t lit, char* reg);
op_asm_t init_op_pushq(char* reg);
op_asm_t init_op_popq(char* reg);
op_asm_t init_op_ret();
void insere_item_array_op_asm(array_op_asm_t* array, op_asm_t item);
void free_array_op_asm(array_op_asm_t* array);
void append_array_op_asm(array_op_asm_t* dst, array_op_asm_t* src);
void init_array_op_asm(array_op_asm_t* array);
void print_array_op_asm(array_op_asm_t array);

// op_asm_t init_op_load_var(int offset, int is_global);
// op_asm_t init_op_load_lit(char* lit);
// op_asm_t init_op_store_var(int offset, int is_global, operando_asm_t temp);
// op_asm_t init_op_store_lit(int offset, int is_global, operando_asm_t temp);
// op_asm_t init_op_3(char* mnemonico, operando_asm_t op1, operando_asm_t op2);
// op_asm_t init_op_cbr(operando_asm_t test, rotulo_asm_t rot_true, rotulo_asm_t rot_false);
// op_asm_t init_op_jump(rotulo_asm_t rot);
// void gera_rotulo(rotulo_asm_t* rotulo);
// void gera_temp(operando_asm_t* operando);

#endif