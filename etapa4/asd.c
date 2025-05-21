#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "asd.h"

valor_t valor_simples(char* lexema) {
  valor_t valor = {
    lexema,
    0,
    TIPO_NO,
    TIPO_DADO_NADA
  };
  return valor;
}

asd_tree_t* asd_create_and_add_1(valor_t valor, asd_tree_t* child) {
  asd_tree_t* new_node = asd_new(valor);
  if (child != NULL) {
    asd_add_child(new_node, child);
  }
  return new_node;
}

asd_tree_t* asd_create_and_add_2(valor_t valor, asd_tree_t* child_1, asd_tree_t* child_2) {
  asd_tree_t* new_node = asd_new(valor);
  if (child_1 != NULL) {
    asd_add_child(new_node, child_1);
  }
  if (child_2 != NULL) {
    asd_add_child(new_node, child_2);
  }
  return new_node;
}

asd_tree_t* asd_create_and_add_3(valor_t valor, asd_tree_t* child_1, asd_tree_t* child_2, asd_tree_t* child_3) {
    asd_tree_t* new_node = asd_new(valor);
  if (child_1 != NULL) {
    asd_add_child(new_node, child_1);
  }
  if (child_2 != NULL) {
    asd_add_child(new_node, child_2);
  }
  if (child_3 != NULL) {
    asd_add_child(new_node, child_3);
  }
  return new_node;
}

asd_tree_t *asd_new(valor_t valor)
{
  asd_tree_t *ret = NULL;
  ret = calloc(1, sizeof(asd_tree_t));
  if (ret != NULL){
    ret->valor.lexema = strdup(valor.lexema);
    ret->number_of_children = 0;
    ret->children = NULL;
    if (ASD_DEBUG_PRINTS)
      printf("Criado ASD no: %s\n", valor.lexema);
  }
  return ret;
}

void asd_free(asd_tree_t *tree)
{
  if (tree != NULL){
    int i;
    for (i = 0; i < tree->number_of_children; i++){
      asd_free(tree->children[i]);
    }
    free(tree->children);
    free(tree->valor.lexema);
    free(tree);
  }else{
    printf("Erro: %s recebeu parâmetro tree = %p.\n", __FUNCTION__, tree);
  }
}

void asd_add_child(asd_tree_t *tree, asd_tree_t *child)
{
  if (tree != NULL && child != NULL){
    tree->number_of_children++;
    tree->children = realloc(tree->children, tree->number_of_children * sizeof(asd_tree_t*));
    tree->children[tree->number_of_children-1] = child;
    if (ASD_DEBUG_PRINTS)
      printf("Add ASD no: %s como filho de: %s\n", tree->valor.lexema, child->valor.lexema);
  }else{
    printf("Erro: %s recebeu parâmetro tree = %p / %p.\n", __FUNCTION__, tree, child);
  }
}

static void _asd_print (FILE *foutput, asd_tree_t *tree, int profundidade)
{
  int i;
  if (tree != NULL){
    fprintf(foutput, "%d%*s: Nó '%s' tem %d filhos:\n", profundidade, profundidade*2, "", tree->valor.lexema, tree->number_of_children);
    for (i = 0; i < tree->number_of_children; i++){
      _asd_print(foutput, tree->children[i], profundidade+1);
    }
  }else{
    printf("Erro: %s recebeu parâmetro tree = %p.\n", __FUNCTION__, tree);
  }
}

void asd_print(asd_tree_t *tree)
{
  FILE *foutput = stderr;
  if (tree != NULL){
    _asd_print(foutput, tree, 0);
  }else{
    printf("Erro: %s recebeu parâmetro tree = %p.\n", __FUNCTION__, tree);
  }
}

static void _asd_print_graphviz (FILE *foutput, asd_tree_t *tree)
{
  int i;
  if (tree != NULL){
    fprintf(foutput, "  %ld [ label=\"%s\" ];\n", (long)tree, tree->valor.lexema);
    for (i = 0; i < tree->number_of_children; i++){
      fprintf(foutput, "  %ld -> %ld;\n", (long)tree, (long)tree->children[i]);
      _asd_print_graphviz(foutput, tree->children[i]);
    }
  }else{
    printf("Erro: %s recebeu parâmetro tree = %p.\n", __FUNCTION__, tree);
  }
}

void asd_print_graphviz(asd_tree_t *tree)
{
  FILE *foutput = stdout;
  if (tree != NULL){
    fprintf(foutput, "digraph grafo {\n");
    _asd_print_graphviz(foutput, tree);
    fprintf(foutput, "}\n");
  }else{
    printf("Erro: %s recebeu parâmetro tree = %p.\n", __FUNCTION__, tree);
  }
}
