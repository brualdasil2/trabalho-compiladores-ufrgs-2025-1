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

void check_is_var(char* identificador) {
    item_tabela_t* item = buscar_item_pilha_tabelas(identificador);
    // Aqui item não é NULL
    if (item == NULL) {
        printf("Deu ruim\n");
        exit(1);
    }
    if (item->natureza == NAT_FUNCAO) {
        free_pilha_tabelas();
        exit(ERR_FUNCTION);
    }

}

void check_is_func(char* identificador) {
    item_tabela_t* item = buscar_item_pilha_tabelas(identificador);
    // Aqui item não é NULL
    if (item == NULL) {
        printf("Deu ruim\n");
        exit(1);
    }
    if (item->natureza == NAT_IDENTIFICADOR) {
        free_pilha_tabelas();
        exit(ERR_VARIABLE);
    }

}

void inferencia_tipo_op_binaria(asd_tree_t* op, asd_tree_t* op1, asd_tree_t* op2) {
    if (op1->valor.tipo_dado_inferido != op2->valor.tipo_dado_inferido) {
        free_pilha_tabelas();
        printf("Erro: tipo errrado entre \"%s\" e \"%s\" na linha %d\n", op1->valor.lexema, op2->valor.lexema, op1->valor.linha_token);
        exit(ERR_WRONG_TYPE);
    }
    //printf("\"%s\": tipo %d %s \"%s\": tipo %d\n", op1->valor.lexema, op1->valor.tipo_dado_inferido, op->valor.lexema, op2->valor.lexema, op2->valor.tipo_dado_inferido);
    op->valor.tipo_dado_inferido = op1->valor.tipo_dado_inferido;
}

extern asd_tree_t* func_atual;

void inferencia_tipo_return(asd_tree_t* retorno, asd_tree_t* exp, tipo_dado_t tipo_retorno) {
    if (exp->valor.tipo_dado_inferido != tipo_retorno) {
        free_pilha_tabelas();
        printf("Erro: tipo incompatível de expressão e retorno na linha %d\n", exp->valor.linha_token);
        exit(ERR_WRONG_TYPE);
    }
    retorno->valor.tipo_dado_inferido = tipo_retorno;
    item_tabela_t* item_func = buscar_item_pilha_tabelas(func_atual->valor.lexema);
    if (item_func == NULL) {
        printf("Deu ruim\n");
        exit(1);
    }
    if (retorno->valor.tipo_dado_inferido != item_func->tipo_dado) {
        free_pilha_tabelas();
        printf("Erro: tipo incompatível de retorno e função na linha %d\n", exp->valor.linha_token);
        exit(ERR_WRONG_TYPE);
    }
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
    // TODO: args
    item.linha_token = valor.linha_token;
    tabela_simbolos_t* tabela = get_tabela_topo_pilha();
    insere_item_tabela_simbolos(tabela, item);
}

void insere_literal_tabela(valor_t valor_original, tipo_dado_t tipo_dado) {
    valor_t valor = valor_original;
    valor.lexema = strdup(valor_original.lexema);
    item_tabela_t item;
    item.chave = valor.lexema;
    item.natureza = NAT_LITERAL;
    item.tipo_dado = tipo_dado;
    init_array_argumento(&(item.argumentos));
    item.linha_token = valor.linha_token;
    tabela_simbolos_t* tabela = get_tabela_topo_pilha();
    insere_item_tabela_simbolos(tabela, item);
}