#include <stdio.h>
#include "asd.h"
#include "iloc.h"
#include <string.h>
#include <stdlib.h>
extern int yyparse(void);
extern int yylex_destroy(void);
asd_tree_t *arvore = NULL;
void test_iloc() {
  int offset_x = 0;
  int offset_y = 4;
  int offset_z = 8;
  int offset_lit_3 = 12;

  // x
  operando_iloc_t temp_x;
  array_op_iloc_t code_x;
  init_array_op_iloc(&code_x);
  op_iloc_t op_load_x = init_op_load_var(offset_x);
  insere_item_array_op_iloc(&code_x, op_load_x);
  temp_x = op_load_x.op3;
  
  // y
  operando_iloc_t temp_y;
  array_op_iloc_t code_y;
  init_array_op_iloc(&code_y);
  op_iloc_t op_load_y = init_op_load_var(offset_y);
  insere_item_array_op_iloc(&code_y, op_load_y);
  temp_y = op_load_y.op3;
  
  // x + y
  operando_iloc_t temp_add;
  array_op_iloc_t code_add;
  init_array_op_iloc(&code_add);
  op_iloc_t op_add = init_op_3("add", temp_x, temp_y);
  append_array_op_iloc(&code_add, &code_x);
  append_array_op_iloc(&code_add, &code_y);
  insere_item_array_op_iloc(&code_add, op_add);
  temp_add = op_add.op3;
  
  // z
  operando_iloc_t temp_z;
  array_op_iloc_t code_z;
  init_array_op_iloc(&code_z);
  op_iloc_t op_load_z = init_op_load_var(offset_z);
  insere_item_array_op_iloc(&code_z, op_load_z);
  temp_z = op_load_z.op3;
  
  // z * (x + y)
  operando_iloc_t temp_mult;
  array_op_iloc_t code_mult;
  init_array_op_iloc(&code_mult);
  op_iloc_t op_mult = init_op_3("mult", temp_z, temp_add);
  
  append_array_op_iloc(&code_mult, &code_z);
  append_array_op_iloc(&code_mult, &code_add);
  insere_item_array_op_iloc(&code_mult, op_mult);
  temp_mult = op_mult.op3;
  
  // 3
  operando_iloc_t temp_3;
  array_op_iloc_t code_3;
  init_array_op_iloc(&code_3);
  op_iloc_t op_load_3 = init_op_load_var(offset_lit_3);
  insere_item_array_op_iloc(&code_3, op_load_3);
  temp_3 = op_load_3.op3;

  // z * (x + y) > 3
  operando_iloc_t temp_ge;
  array_op_iloc_t code_ge;
  init_array_op_iloc(&code_ge);
  op_iloc_t op_ge = init_op_3("cmp_LT", temp_mult, temp_3);
  append_array_op_iloc(&code_ge, &code_mult);
  append_array_op_iloc(&code_ge, &code_3);
  insere_item_array_op_iloc(&code_ge, op_ge);

  print_array_op_iloc(code_ge);
  free_array_op_iloc(&code_ge);
  exit(0);

}
int main (int argc, char **argv)
{
  test_iloc();
  int ret = yyparse();
  asd_print_graphviz(arvore);
  asd_free(arvore);
  yylex_destroy();
  return ret;
}
