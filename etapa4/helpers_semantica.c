#include "helpers_semantica.h"

void check_declared(char* identificador) {
    item_tabela_t* item_existe = buscar_item_pilha_tabelas(identificador);
    if (item_existe != NULL) {
        free_pilha_tabelas();
        exit(ERR_DECLARED);
    }
}

void check_undeclared(char* identificador) {
    item_tabela_t* item_existe = buscar_item_pilha_tabelas(identificador);
    if (item_existe == NULL) {
        free_pilha_tabelas();
        exit(ERR_UNDECLARED);
    }
}

void inferencia_tipo_op_binaria(asd_tree_t* op, asd_tree_t* op1, asd_tree_t* op2) {
    if (op1->valor.tipo_dado_inferido != op2->valor.tipo_dado_inferido) {
        free_pilha_tabelas();
        exit(ERR_WRONG_TYPE);
    }
    op->valor.tipo_dado_inferido = op1->valor.tipo_dado_inferido;
}

void set_tipo_da_tabela(asd_tree_t* no, char* lexema) {
    item_tabela_t* item = buscar_item_pilha_tabelas(lexema);
    // aqui item não é NULL
    if (item == NULL) {
        printf("Deu ruim\n");
        exit(1);
    }
    no->valor.tipo_dado_inferido = item->tipo_dado;
}

void insere_variavel_tabela(valor_t valor_original, tipo_dado_t tipo_dado) {
    valor_t valor = valor_original;
    valor.lexema = strdup(valor_original.lexema);
    item_tabela_t item;
    item.chave = valor.lexema;
    item.natureza = NAT_IDENTIFICADOR;
    item.tipo_dado = tipo_dado;
    init_array_argumento(&(item.argumentos));
    item.linha_token = valor.linha_token;
    tabela_simbolos_t* tabela = get_tabela_topo_pilha();
    insere_item_tabela_simbolos(tabela, item);
}

void insere_funcao_tabela(valor_t valor_original, tipo_dado_t tipo_dado) {
    valor_t valor = valor_original;
    valor.lexema = strdup(valor_original.lexema);
    item_tabela_t item;
    item.chave = valor.lexema;
    item.natureza = NAT_FUNCAO;
    item.tipo_dado = tipo_dado;
    init_array_argumento(&(item.argumentos));
    item.linha_token = valor.linha_token;
    tabela_simbolos_t* tabela = get_tabela_topo_pilha();
    insere_item_tabela_simbolos(tabela, item);
}