#include "helpers_semantica.h"

void check_declared(char* identificador) {
    item_tabela_t* item_existe = buscar_item_pilha_tabelas(identificador);
    if (item_existe != NULL) {
        free_pilha_tabelas();
        exit(ERR_DECLARED);
    }
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