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

  array_op_iloc_t code_add;
  init_array_op_iloc(&code_add);

  op_iloc_t op_load_t1 = init_op_iloc();
  strcpy(op_load_t1.mnemonico.valor, "loadAI");
  strcpy(op_load_t1.op1.valor, "rfp");
  set_operando_int(&op_load_t1.op2, offset_x_add);
  gera_temp(&op_load_t1.op3);
  
  op_iloc_t op_load_t2 = init_op_iloc();
  strcpy(op_load_t2.mnemonico.valor, "loadAI");
  strcpy(op_load_t2.op1.valor, "rfp");
  set_operando_int(&op_load_t2.op2, offset_y_add);
  gera_temp(&op_load_t2.op3);

  op_iloc_t op_add = init_op_iloc();
  strcpy(op_add.mnemonico.valor, "add");
  //gera_rotulo(&op_add.rotulo);
  strcpy(op_add.op1.valor, op_load_t1.op3.valor);
  strcpy(op_add.op2.valor, op_load_t2.op3.valor);
  gera_temp(&op_add.op3);

  insere_item_array_op_iloc(&code_add, op_load_t1);
  insere_item_array_op_iloc(&code_add, op_load_t2);
  insere_item_array_op_iloc(&code_add, op_add);

  print_array_op_iloc(code_add);
  free_array_op_iloc(&code_add);
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
