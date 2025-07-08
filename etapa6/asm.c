#include "asm.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void set_operando_int(operando_asm_t* operando, int valor) {
    sprintf(operando->valor, "%d", valor);
}

op_asm_t init_op_asm() {
    op_asm_t op;
    strcpy(op.mnemonico.valor, "nop");
    strcpy(op.op1.valor, "");
    strcpy(op.op2.valor, "");
    strcpy(op.rotulo.valor, "");
    op.op_qtd = 0;
    return op;
}

op_asm_t init_op_store(int offset, int is_global, char* temp, char* var_name) {
    op_asm_t op = init_op_asm();
    strcpy(op.mnemonico.valor, "movl");
    strcpy(op.op1.valor, temp);
    if (is_global)
    {
        strcpy(op.op2.valor, var_name);
        strcat(op.op2.valor, "(%rip)");
    }
    else
    {
        set_operando_int(&op.op2, -offset);
        strcat(op.op2.valor, "(%rbp)");
    }
    op.op_qtd = 2;
    return op;
}

op_asm_t init_lit(char* lit) {
    op_asm_t op = init_op_asm();
    strcpy(op.op1.valor, "$");
    strcat(op.op1.valor, lit);
    return op;
}

op_asm_t init_op_load_var_to_reg(int offset, int is_global, char* reg, char* var_name) {
    op_asm_t op = init_op_asm();
    strcpy(op.mnemonico.valor, "movl");
    if (is_global)
    {
        strcpy(op.op1.valor, var_name);
        strcat(op.op1.valor, "(%rip)");
    }
    else
    {
        set_operando_int(&op.op1, -offset);
        strcat(op.op1.valor, "(%rbp)");
    }
    strcpy(op.op2.valor, reg);
    op.op_qtd = 2;
    return op;
}

op_asm_t init_op_load_lit_to_reg(operando_asm_t lit, char* reg) {
    op_asm_t op = init_op_asm();
    strcpy(op.mnemonico.valor, "movl");
    strcpy(op.op1.valor, lit.valor);
    strcpy(op.op2.valor, reg);
    op.op_qtd = 2;
    return op;
}

op_asm_t init_op_pushq(char* reg) {
    op_asm_t op = init_op_asm();
    strcpy(op.mnemonico.valor, "pushq");
    strcpy(op.op1.valor, reg);
    op.op_qtd = 1;
    return op;
}

op_asm_t init_op_popq(char* reg) {
    op_asm_t op = init_op_asm();
    strcpy(op.mnemonico.valor, "popq");
    strcpy(op.op1.valor, reg);
    op.op_qtd = 1;
    return op;
}

op_asm_t init_op_ret() {
    op_asm_t op = init_op_asm();
    strcpy(op.mnemonico.valor, "ret");
    op.op_qtd = 0;
    return op;
}

void append_array_op_asm(array_op_asm_t* dst, array_op_asm_t* src) {
    for (int i = 0; i < src->tamanho_usado; i++) {
        insere_item_array_op_asm(dst, src->ops[i]);
    }
    free_array_op_asm(src);
}

void prepend_array_op_asm(array_op_asm_t* dst, array_op_asm_t* src) {
    for (int i = 0; i < dst->tamanho_usado; i++) {
        insere_item_array_op_asm(src, dst->ops[i]);
    }
    free_array_op_asm(dst);
}

void insere_item_array_op_asm(array_op_asm_t* array, op_asm_t item) {
    if (array->tamanho_usado == array->tamanho_total) {
        array->tamanho_total += DELTA_TAM;
        array->ops = (op_asm_t*) realloc(array->ops, array->tamanho_total*sizeof(op_asm_t));
    }
    array->ops[array->tamanho_usado] = item;
    array->tamanho_usado++;
}

void free_array_op_asm(array_op_asm_t* array) {
    if (array->tamanho_total > 0) {
        free(array->ops);
        array->tamanho_total = 0;
        array->tamanho_usado = 0;
    }
}

void init_array_op_asm(array_op_asm_t* array) {
    array->ops = (op_asm_t*) malloc(DELTA_TAM*sizeof(op_asm_t));
    array->tamanho_usado = 0;
    array->tamanho_total = DELTA_TAM;
}

void print_array_op_asm(array_op_asm_t array) {
    printf("\t");
    for (int i = 0; i < array.tamanho_usado; i++) {
        op_asm_t op = array.ops[i];
        if (strlen(op.rotulo.valor) == 0) {
            printf("\n\t%s ", op.mnemonico.valor);
        }
        else {
            printf("\n%s: \n\t%s ", op.rotulo.valor, op.mnemonico.valor);
        }

        if (!strcmp(op.mnemonico.valor, "nop")) {
            
        }
        else if (op.op_qtd == 0) {
        
        }
        else if (op.op_qtd == 1) {
            printf(" %s", op.op1.valor);
        }
        else if (op.op_qtd == 2) {
            printf(" %s, %s", op.op1.valor, op.op2.valor);
        }
        // else if (!strcmp(op.mnemonico.valor, "cbr")) {
        //     printf("%s -> %s, %s\n", op.op1.valor, op.op2.valor, op.op3.valor);
        // }
        // else if (!strcmp(op.mnemonico.valor, "jumpI")) {
        //     printf("-> %s\n", op.op1.valor);
        // }
        // else if (strlen(op.op2.valor) == 0) {
        //     // só tem um operando, logo fica à direita da seta
        //     printf("=> %s\n", op.op1.valor);
        // }
        // else if (strlen(op.op3.valor) == 0) {
        //     // tem 2 operandos, um fica à esq e um à dir da seta
        //     printf("%s => %s\n", op.op1.valor, op.op2.valor);
        // }
        // else {
        //     // tem 3 operandos, 2 ficam na esquerda e 1 na direita
        //     printf("%s, %s => %s\n", op.op1.valor, op.op2.valor, op.op3.valor);

        // }
    }
    printf("\n");
}


// op_asm_t init_op_store_lit(int offset, int is_global, operando_asm_t temp) {
//     op_asm_t op = init_op_asm();
//     strcpy(op.mnemonico.valor, "movl");
//     strcpy(op.op1.valor, temp.valor);
//     if (is_global)
//         strcpy(op.op2.valor, "rip");
//     else
//         strcpy(op.op2.valor, "rbp");
//     set_operando_int(&op.op3, offset);
//     return op;
// }

// op_asm_t init_op_store_var(int offset, int is_global, operando_asm_t temp) {
//     op_asm_t op = init_op_iloc();
//     strcpy(op.mnemonico.valor, "movl");
//     strcpy(op.op1.valor, temp.valor);
//     if (is_global)
//         strcpy(op.op2.valor, "rip");
//     else
//         strcpy(op.op2.valor, "rbp");
//     set_operando_int(&op.op3, offset);
//     return op;
// }

// op_asm_t init_op_3(char* mnemonico, operando_asm_t op1, operando_asm_t op2) {
//     op_asm_t op = init_op_iloc();
//     strcpy(op.mnemonico.valor, mnemonico);
//     strcpy(op.op1.valor, op1.valor);
//     strcpy(op.op2.valor, op2.valor);
//     gera_temp(&op.op3);
//     return op;
// }



