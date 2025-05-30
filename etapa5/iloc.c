#include "iloc.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int rotulo_counter = 0;
int temp_counter = 0;

void gera_rotulo(rotulo_iloc_t* rotulo) {
    sprintf(rotulo->valor, "L%d", rotulo_counter++);
}
void gera_temp(operando_iloc_t* operando) {
    sprintf(operando->valor, "r%d", temp_counter++);
}
void set_operando_int(operando_iloc_t* operando, int valor) {
    sprintf(operando->valor, "%d", valor);
}
op_iloc_t init_op_iloc() {
    op_iloc_t op;
    strcpy(op.mnemonico.valor, "nop");
    strcpy(op.op1.valor, "");
    strcpy(op.op2.valor, "");
    strcpy(op.op3.valor, "");
    strcpy(op.rotulo.valor, "");
    return op;
}
op_iloc_t init_op_load_var(int offset, int is_global) {
    op_iloc_t op = init_op_iloc();
    strcpy(op.mnemonico.valor, "loadAI");
    if (is_global)
        strcpy(op.op1.valor, "rbss");
    else
        strcpy(op.op1.valor, "rfp");
    set_operando_int(&op.op2, offset);
    gera_temp(&op.op3);
    return op;
}
op_iloc_t init_op_load_lit(char* lit) {
    op_iloc_t op = init_op_iloc();
    strcpy(op.mnemonico.valor, "loadI");
    strcpy(op.op1.valor, lit);
    gera_temp(&op.op2);
    return op;
}
op_iloc_t init_op_store_var(int offset, int is_global, operando_iloc_t temp) {
    op_iloc_t op = init_op_iloc();
    strcpy(op.mnemonico.valor, "storeAI");
    strcpy(op.op1.valor, temp.valor);
    if (is_global)
        strcpy(op.op2.valor, "rbss");
    else
        strcpy(op.op2.valor, "rfp");
    set_operando_int(&op.op3, offset);
    return op;
}
op_iloc_t init_op_3(char* mnemonico, operando_iloc_t op1, operando_iloc_t op2) {
    op_iloc_t op = init_op_iloc();
    strcpy(op.mnemonico.valor, mnemonico);
    strcpy(op.op1.valor, op1.valor);
    strcpy(op.op2.valor, op2.valor);
    gera_temp(&op.op3);
    return op;
}
op_iloc_t init_op_cbr(operando_iloc_t test, rotulo_iloc_t rot_true, rotulo_iloc_t rot_false) {
    op_iloc_t op = init_op_iloc();
    strcpy(op.mnemonico.valor, "cbr");
    strcpy(op.op1.valor, test.valor);
    strcpy(op.op2.valor, rot_true.valor);
    strcpy(op.op3.valor, rot_false.valor);
    return op;
}
op_iloc_t init_op_jump(rotulo_iloc_t rot) {
    op_iloc_t op = init_op_iloc();
    strcpy(op.mnemonico.valor, "jumpI");
    strcpy(op.op1.valor, rot.valor);
    return op;

}
void init_array_op_iloc(array_op_iloc_t* array) {
    array->ops = (op_iloc_t*) malloc(DELTA_TAM*sizeof(op_iloc_t));
    array->tamanho_usado = 0;
    array->tamanho_total = DELTA_TAM;
}
void insere_item_array_op_iloc(array_op_iloc_t* array, op_iloc_t item) {
    if (array->tamanho_usado == array->tamanho_total) {
        array->tamanho_total += DELTA_TAM;
        array->ops = (op_iloc_t*) realloc(array->ops, array->tamanho_total*sizeof(op_iloc_t));
    }
    array->ops[array->tamanho_usado] = item;
    array->tamanho_usado++;
}
void free_array_op_iloc(array_op_iloc_t* array) {
    if (array->tamanho_total > 0) {
        free(array->ops);
        array->tamanho_total = 0;
        array->tamanho_usado = 0;
    }
}
void append_array_op_iloc(array_op_iloc_t* dst, array_op_iloc_t* src) {
    for (int i = 0; i < src->tamanho_usado; i++) {
        insere_item_array_op_iloc(dst, src->ops[i]);
    }
    free_array_op_iloc(src);
}
void print_array_op_iloc(array_op_iloc_t array) {
    for (int i = 0; i < array.tamanho_usado; i++) {
        op_iloc_t op = array.ops[i];
        if (strlen(op.rotulo.valor) == 0) {
            printf("%s ", op.mnemonico.valor);
        }
        else {
            printf("%s: %s ", op.rotulo.valor, op.mnemonico.valor);
        }

        if (!strcmp(op.mnemonico.valor, "nop")) {
            printf("\n");
        }
        else if (!strcmp(op.mnemonico.valor, "storeAI")) {
            printf("%s => %s, %s\n", op.op1.valor, op.op2.valor, op.op3.valor);
        }
        else if (!strcmp(op.mnemonico.valor, "cbr")) {
            printf("%s -> %s, %s\n", op.op1.valor, op.op2.valor, op.op3.valor);
        }
        else if (!strcmp(op.mnemonico.valor, "jumpI")) {
            printf("-> %s\n", op.op1.valor);
        }
        else if (strlen(op.op2.valor) == 0) {
            // só tem um operando, logo fica à direita da seta
            printf("=> %s\n", op.op1.valor);
        }
        else if (strlen(op.op3.valor) == 0) {
            // tem 2 operandos, um fica à esq e um à dir da seta
            printf("%s => %s\n", op.op1.valor, op.op2.valor);
        }
        else {
            // tem 3 operandos, 2 ficam na esquerda e 1 na direita
            printf("%s, %s => %s\n", op.op1.valor, op.op2.valor, op.op3.valor);

        }
    }
}
