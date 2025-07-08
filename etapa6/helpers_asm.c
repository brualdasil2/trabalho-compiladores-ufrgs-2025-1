#include "helpers_asm.h"
#include "stdio.h"
#include "string.h"


void gera_store(asd_tree_t* op_node, asd_tree_t* id_node, asd_tree_t* exp_node) {
    //recebe lit ou valor temporario na expressao
    item_tabela_t* item = buscar_item_pilha_tabelas(id_node->valor.lexema);
    op_asm_t op = init_op_store(item->offset, item->is_global, exp_node->valor.temp);
    append_array_op_asm(&(op_node->valor.code), &(exp_node->valor.code));
    insere_item_array_op_asm(&(op_node->valor.code), op);
}

void gera_lit(asd_tree_t* node) {
    op_asm_t op_lit = init_lit(node->valor.lexema);
    node->valor.temp = op_lit.op1;
}

void gera_retorno(asd_tree_t* ret_node, asd_tree_t* exp_node) {
    op_asm_t op[3];
    for(int i = 0; i<3; i++)
    {
        op[i] = init_op_asm();
    }
    if(exp_node->valor.tipo == TIPO_LITERAL)
    {
        op[0] = init_op_load_lit_to_reg(exp_node->valor.temp, "%eax");
    }
    else
    {
        item_tabela_t* item = buscar_item_pilha_tabelas(exp_node->valor.lexema);
        op[0] = init_op_load_var_to_reg(item->offset, item->is_global, exp_node->valor.temp, "%eax");
    }
    op[1] = init_op_popq("%rbp");
    op[2] = init_op_ret();
    append_array_op_asm(&(ret_node->valor.code), &(exp_node->valor.code));
    for(int i = 0; i<3; i++)
    {
        insere_item_array_op_asm(&(ret_node->valor.code), op[i]);
    }
} 

void gera_main(asd_tree_t* main_node) {
    op_asm_t op[5];
    for(int i = 0; i<5; i++)
    {
        op[i] = init_op_asm();
    }
    strcpy(op[0].mnemonico.valor, ".text");
    strcpy(op[1].mnemonico.valor, ".globl	main");
    strcpy(op[2].mnemonico.valor, ".type	main, @function");
    strcpy(op[3].mnemonico.valor, "pushq %rbp");
    strcpy(op[3].rotulo.valor, "main");
    strcpy(op[4].mnemonico.valor, "movq	%rsp, %rbp");
    for(int i = 0; i<5; i++)
    {
        insere_item_array_op_asm(&(main_node->valor.code), op[i]);
    }
}


// void gera_store_lit(asd_tree_t* op_node, asd_tree_t* id_node, asd_tree_t* exp_node) {
//     item_tabela_t* item = buscar_item_pilha_tabelas(id_node->valor.lexema);
//     op_asm_t op = init_op_store_lit(item->offset, item->is_global, exp_node->valor.temp);
//     append_array_op_asm(&(op_node->valor.code), &(exp_node->valor.code));
//     insere_item_array_op_asm(&(op_node->valor.code), op);
// }

// void gera_store_var(asd_tree_t* op_node, asd_tree_t* id_node, asd_tree_t* exp_node) {
//     item_tabela_t* item = buscar_item_pilha_tabelas(id_node->valor.lexema);
//     op_asm_t op = init_op_store_var(item->offset, item->is_global, exp_node->valor.temp);
//     append_array_op_asm(&(op_node->valor.code), &(exp_node->valor.code));
//     insere_item_array_op_asm(&(op_node->valor.code), op);
// }

// void gera_op_3(char* mnemonico, asd_tree_t* op_node, asd_tree_t* op1_node, asd_tree_t* op2_node) {
//     op_asm_t op = init_op_3(mnemonico, op1_node->valor.temp, op2_node->valor.temp);
//     append_array_op_iloc(&(op_node->valor.code), &(op1_node->valor.code));
//     append_array_op_iloc(&(op_node->valor.code), &(op2_node->valor.code));
//     insere_item_array_op_iloc(&(op_node->valor.code), op);
//     op_node->valor.temp = op.op3;
// }