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

/*
storeAI Exp.temp => (rfp / rbss), Id.offset

*/