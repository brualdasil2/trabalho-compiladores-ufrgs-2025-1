#include "helpers_iloc.h"
#include <stdlib.h>
#include <string.h>

void gera_load_var(asd_tree_t* node) {
    item_tabela_t* item = buscar_item_pilha_tabelas(node->valor.lexema);
    op_iloc_t op_load = init_op_load_var(item->offset, item->is_global);
    insere_item_array_op_iloc(&(node->valor.code), op_load);
    node->valor.temp = op_load.op3;
}

void gera_op_3(char* mnemonico, asd_tree_t* op_node, asd_tree_t* op1_node, asd_tree_t* op2_node) {
    op_iloc_t op = init_op_3(mnemonico, op1_node->valor.temp, op2_node->valor.temp);
    append_array_op_iloc(&(op_node->valor.code), &(op1_node->valor.code));
    append_array_op_iloc(&(op_node->valor.code), &(op2_node->valor.code));
    insere_item_array_op_iloc(&(op_node->valor.code), op);
    op_node->valor.temp = op.op3;
}

void gera_store_var(asd_tree_t* op_node, asd_tree_t* id_node, asd_tree_t* exp_node) {
    item_tabela_t* item = buscar_item_pilha_tabelas(id_node->valor.lexema);
    op_iloc_t op = init_op_store_var(item->offset, item->is_global, exp_node->valor.temp);
    append_array_op_iloc(&(op_node->valor.code), &(exp_node->valor.code));
    insere_item_array_op_iloc(&(op_node->valor.code), op);
}

void gera_not_unario(asd_tree_t* op_node, asd_tree_t* op1_node) {
    op_iloc_t op_load_0 = init_op_load_0();
    op_iloc_t op_cmp_eq = init_op_3("cmp_EQ", op1_node->valor.temp, op_load_0.op2);
    append_array_op_iloc(&(op_node->valor.code), &(op1_node->valor.code));
    insere_item_array_op_iloc(&(op_node->valor.code), op_load_0);
    insere_item_array_op_iloc(&(op_node->valor.code), op_cmp_eq);
    op_node->valor.temp = op_cmp_eq.op3;
}
void gera_sub_unario(asd_tree_t* op_node, asd_tree_t* op1_node) {
    operando_iloc_t zero = { "0" };
    op_iloc_t op_rsub_i = init_op_3("rsubI", zero, op1_node->valor.temp);
    append_array_op_iloc(&(op_node->valor.code), &(op1_node->valor.code));
    insere_item_array_op_iloc(&(op_node->valor.code), op_rsub_i);
    op_node->valor.temp = op_rsub_i.op3;
}

void gera_if(asd_tree_t* op_node, asd_tree_t* test_node, asd_tree_t* bloco_true) {
    op_iloc_t op_rotulo_true = init_op_iloc();
    op_iloc_t op_rotulo_false = init_op_iloc();
    gera_rotulo(&(op_rotulo_true.rotulo));
    gera_rotulo(&(op_rotulo_false.rotulo));
    op_iloc_t op_cbr = init_op_cbr(test_node->valor.temp, op_rotulo_true.rotulo, op_rotulo_false.rotulo);
    append_array_op_iloc(&(op_node->valor.code), &(test_node->valor.code));
    insere_item_array_op_iloc(&(op_node->valor.code), op_cbr);
    insere_item_array_op_iloc(&(op_node->valor.code), op_rotulo_true);
    append_array_op_iloc(&(op_node->valor.code), &(bloco_true->valor.code));
    insere_item_array_op_iloc(&(op_node->valor.code), op_rotulo_false);
}
void gera_if_else(asd_tree_t* op_node, asd_tree_t* test_node, asd_tree_t* bloco_true, asd_tree_t* bloco_false) {
    op_iloc_t op_rotulo_true = init_op_iloc();
    op_iloc_t op_rotulo_false = init_op_iloc();
    op_iloc_t op_rotulo_skip = init_op_iloc();
    gera_rotulo(&(op_rotulo_true.rotulo));
    gera_rotulo(&(op_rotulo_false.rotulo));
    gera_rotulo(&(op_rotulo_skip.rotulo));
    op_iloc_t op_cbr = init_op_cbr(test_node->valor.temp, op_rotulo_true.rotulo, op_rotulo_false.rotulo);
    op_iloc_t op_jump = init_op_jump(op_rotulo_skip.rotulo);
    append_array_op_iloc(&(op_node->valor.code), &(test_node->valor.code));
    insere_item_array_op_iloc(&(op_node->valor.code), op_cbr);
    insere_item_array_op_iloc(&(op_node->valor.code), op_rotulo_true);
    append_array_op_iloc(&(op_node->valor.code), &(bloco_true->valor.code));
    insere_item_array_op_iloc(&(op_node->valor.code), op_jump);
    insere_item_array_op_iloc(&(op_node->valor.code), op_rotulo_false);
    append_array_op_iloc(&(op_node->valor.code), &(bloco_false->valor.code));
    insere_item_array_op_iloc(&(op_node->valor.code), op_rotulo_skip);
}
void gera_while(asd_tree_t* op_node, asd_tree_t* test_node, asd_tree_t* bloco_true) {
    op_iloc_t op_rotulo_true = init_op_iloc();
    op_iloc_t op_rotulo_false = init_op_iloc();
    op_iloc_t op_rotulo_start = init_op_iloc();
    gera_rotulo(&(op_rotulo_start.rotulo));
    gera_rotulo(&(op_rotulo_true.rotulo));
    gera_rotulo(&(op_rotulo_false.rotulo));
    op_iloc_t op_cbr = init_op_cbr(test_node->valor.temp, op_rotulo_true.rotulo, op_rotulo_false.rotulo);
    op_iloc_t op_jump = init_op_jump(op_rotulo_start.rotulo);
    insere_item_array_op_iloc(&(op_node->valor.code), op_rotulo_start);
    append_array_op_iloc(&(op_node->valor.code), &(test_node->valor.code));
    insere_item_array_op_iloc(&(op_node->valor.code), op_cbr);
    insere_item_array_op_iloc(&(op_node->valor.code), op_rotulo_true);
    append_array_op_iloc(&(op_node->valor.code), &(bloco_true->valor.code));
    insere_item_array_op_iloc(&(op_node->valor.code), op_jump);
    insere_item_array_op_iloc(&(op_node->valor.code), op_rotulo_false);
}