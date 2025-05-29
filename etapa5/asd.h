#ifndef _ASD_H_
#define _ASD_H_
#include "token.h"
#include "utils.h"

#define ASD_DEBUG_PRINTS 0

typedef struct asd_tree {
  valor_t valor;
  int number_of_children;
  struct asd_tree **children;
} asd_tree_t;

valor_t valor_simples(char* lexema);
asd_tree_t* asd_create_and_add_1(valor_t valor, asd_tree_t* child);
asd_tree_t* asd_create_and_add_2(valor_t valor, asd_tree_t* child_1, asd_tree_t* child_2);
asd_tree_t* asd_create_and_add_3(valor_t valor, asd_tree_t* child_1, asd_tree_t* child_2, asd_tree_t* child_3);
/*
 * Função asd_new, cria um nó sem filhos com o label informado.
 */
asd_tree_t *asd_new(valor_t valor);

/*
 * Função asd_tree, libera recursivamente o nó e seus filhos.
 */
void asd_free(asd_tree_t *tree);

/*
 * Função asd_add_child, adiciona child como filho de tree.
 */
void asd_add_child(asd_tree_t *tree, asd_tree_t *child);

/*
 * Função asd_print, imprime recursivamente a árvore.
 */
void asd_print(asd_tree_t *tree);

/*
 * Função asd_print_graphviz, idem, em formato DOT
 */
void asd_print_graphviz (asd_tree_t *tree);
#endif //_ASD_H_
