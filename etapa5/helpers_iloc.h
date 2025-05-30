#ifndef HELPERS_ILOC_H
#define HELPERS_ILOC_H

#include "asd.h"
#include "iloc.h"
#include "pilha_tabelas.h"

void gera_load_var(asd_tree_t* node);
void gera_op_3(char* mnemonico, asd_tree_t* op_node, asd_tree_t* op1_node, asd_tree_t* op2_node);
void gera_store_var(asd_tree_t* op_node, asd_tree_t* id_node, asd_tree_t* exp_node);
void gera_not_unario(asd_tree_t* op_node, asd_tree_t* op1_node);
void gera_sub_unario(asd_tree_t* op_node, asd_tree_t* op1_node);


#endif // HELPERS_ILOC_H