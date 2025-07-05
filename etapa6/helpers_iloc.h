#ifndef HELPERS_ILOC_H
#define HELPERS_ILOC_H

#include "asd.h"
#include "iloc.h"
#include "pilha_tabelas.h"

void gera_load_var(asd_tree_t* node);
void gera_load_lit(asd_tree_t* node);
void gera_op_3(char* mnemonico, asd_tree_t* op_node, asd_tree_t* op1_node, asd_tree_t* op2_node);
void gera_store_var(asd_tree_t* op_node, asd_tree_t* id_node, asd_tree_t* exp_node);
void gera_not_unario(asd_tree_t* op_node, asd_tree_t* op1_node);
void gera_sub_unario(asd_tree_t* op_node, asd_tree_t* op1_node);
void gera_if(asd_tree_t* op_node, asd_tree_t* test_node, asd_tree_t* bloco_true);
void gera_if_else(asd_tree_t* op_node, asd_tree_t* test_node, asd_tree_t* bloco_true, asd_tree_t* bloco_false);
void gera_while(asd_tree_t* op_node, asd_tree_t* test_node, asd_tree_t* bloco_true);

#endif // HELPERS_ILOC_H