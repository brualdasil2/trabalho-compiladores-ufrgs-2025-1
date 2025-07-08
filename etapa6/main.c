#include <stdio.h>
#include "asd.h"
#include "asm.h"
#include <string.h>
#include <stdlib.h>
extern int yyparse(void);
extern int yylex_destroy(void);
asd_tree_t *arvore = NULL;
// void test_iloc() {
//   int offset_x = 0;
//   int offset_y = 4;
//   int offset_z = 8;
//   int offset_lit_3 = 12;
//   int offset_a = 16;
//   int offset_b = 20;

//   // x
//   operando_iloc_t temp_x;
//   array_op_iloc_t code_x;
//   init_array_op_iloc(&code_x);
//   op_iloc_t op_load_x = init_op_load_var(offset_x, 0);
//   insere_item_array_op_iloc(&code_x, op_load_x);
//   temp_x = op_load_x.op3;
  
//   // y
//   operando_iloc_t temp_y;
//   array_op_iloc_t code_y;
//   init_array_op_iloc(&code_y);
//   op_iloc_t op_load_y = init_op_load_var(offset_y, 0);
//   insere_item_array_op_iloc(&code_y, op_load_y);
//   temp_y = op_load_y.op3;
  
//   // x + y
//   operando_iloc_t temp_add;
//   array_op_iloc_t code_add;
//   init_array_op_iloc(&code_add);
//   op_iloc_t op_add = init_op_3("add", temp_x, temp_y);
//   append_array_op_iloc(&code_add, &code_x);
//   append_array_op_iloc(&code_add, &code_y);
//   insere_item_array_op_iloc(&code_add, op_add);
//   temp_add = op_add.op3;
  
//   // z
//   operando_iloc_t temp_z;
//   array_op_iloc_t code_z;
//   init_array_op_iloc(&code_z);
//   op_iloc_t op_load_z = init_op_load_var(offset_z, 0);
//   insere_item_array_op_iloc(&code_z, op_load_z);
//   temp_z = op_load_z.op3;
  
//   // z * (x + y)
//   operando_iloc_t temp_mult;
//   array_op_iloc_t code_mult;
//   init_array_op_iloc(&code_mult);
//   op_iloc_t op_mult = init_op_3("mult", temp_z, temp_add);
  
//   append_array_op_iloc(&code_mult, &code_z);
//   append_array_op_iloc(&code_mult, &code_add);
//   insere_item_array_op_iloc(&code_mult, op_mult);
//   temp_mult = op_mult.op3;
  
//   // 3
//   operando_iloc_t temp_3;
//   array_op_iloc_t code_3;
//   init_array_op_iloc(&code_3);
//   op_iloc_t op_load_3 = init_op_load_var(offset_lit_3, 0);
//   insere_item_array_op_iloc(&code_3, op_load_3);
//   temp_3 = op_load_3.op3;

//   // z * (x + y) > 3
//   operando_iloc_t temp_gt;
//   array_op_iloc_t code_gt;
//   init_array_op_iloc(&code_gt);
//   op_iloc_t op_gt = init_op_3("cmp_GT", temp_mult, temp_3);
//   append_array_op_iloc(&code_gt, &code_mult);
//   append_array_op_iloc(&code_gt, &code_3);
//   insere_item_array_op_iloc(&code_gt, op_gt);

//   // bloco_true
//   array_op_iloc_t code_bloco_true;
//   init_array_op_iloc(&code_bloco_true);
//   op_iloc_t op_load_a = init_op_load_var(offset_a, 0);
//   insere_item_array_op_iloc(&code_bloco_true, op_load_a);
//   temp_gt = op_gt.op3;

//   // bloco_false
//   array_op_iloc_t code_bloco_false;
//   init_array_op_iloc(&code_bloco_false);
//   op_iloc_t op_load_b = init_op_load_var(offset_b, 0);
//   insere_item_array_op_iloc(&code_bloco_false, op_load_b);

//   // if (z * (x + y) > 3) bloco_true else bloco_false
//   array_op_iloc_t code_if_else;
//   init_array_op_iloc(&code_if_else);
//   op_iloc_t op_rotulo_true = init_op_iloc();
//   op_iloc_t op_rotulo_false = init_op_iloc();
//   op_iloc_t op_rotulo_skip = init_op_iloc();
//   gera_rotulo(&op_rotulo_true.rotulo);
//   gera_rotulo(&op_rotulo_false.rotulo);
//   gera_rotulo(&op_rotulo_skip.rotulo);
//   op_iloc_t op_if_else = init_op_cbr(temp_gt, op_rotulo_true.rotulo, op_rotulo_false.rotulo);
//   op_iloc_t op_jump = init_op_jump(op_rotulo_skip.rotulo);
//   append_array_op_iloc(&code_if_else, &code_gt);
//   insere_item_array_op_iloc(&code_if_else, op_if_else);
//   insere_item_array_op_iloc(&code_if_else, op_rotulo_true);
//   append_array_op_iloc(&code_if_else, &code_bloco_true);
//   insere_item_array_op_iloc(&code_if_else, op_jump);
//   insere_item_array_op_iloc(&code_if_else, op_rotulo_false);
//   append_array_op_iloc(&code_if_else, &code_bloco_false);
//   insere_item_array_op_iloc(&code_if_else, op_rotulo_skip);

//   print_array_op_iloc(code_if_else);
//   free_array_op_iloc(&code_if_else);
//   exit(0);

// }
int main (int argc, char **argv)
{
  //test_iloc();
  int ret = yyparse();
  //asd_print_graphviz(arvore);
  if (arvore != NULL) {
    print_array_op_asm(arvore->valor.code);
  }
  asd_free(arvore);
  yylex_destroy();
  return ret;
}
