#include <stdio.h>
#include "asd.h"
#include "iloc.h"
#include <string.h>
#include <stdlib.h>
extern int yyparse(void);
extern int yylex_destroy(void);
asd_tree_t *arvore = NULL;
void test_iloc() {
  int offset_x_add = 0;
  int offset_y_add = 4;
  int offset_z_mult= 8;

  array_op_iloc_t code_add;
  init_array_op_iloc(&code_add);
  op_iloc_t op_load_t1 = init_op_load_var(offset_x_add);
  op_iloc_t op_load_t2 = init_op_load_var(offset_y_add);
  op_iloc_t op_add = init_op_3("add", op_load_t1.op3, op_load_t2.op3);
  insere_item_array_op_iloc(&code_add, op_load_t1);
  insere_item_array_op_iloc(&code_add, op_load_t2);
  insere_item_array_op_iloc(&code_add, op_add);

  array_op_iloc_t code_mult;
  init_array_op_iloc(&code_mult);
  op_iloc_t op_load_z = init_op_load_var(offset_z_mult);
  op_iloc_t op_mult = init_op_3("mult", op_load_z.op3, op_add.op3);

  append_array_op_iloc(&code_mult, &code_add);
  insere_item_array_op_iloc(&code_mult, op_load_z);
  insere_item_array_op_iloc(&code_mult, op_mult);

  print_array_op_iloc(code_mult);
  free_array_op_iloc(&code_mult);
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
