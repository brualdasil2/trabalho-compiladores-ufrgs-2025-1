#include "helpers_semantica.h"

void check_declared(asd_tree_t* node) {
    tabela_simbolos_t* tabela_atual = get_tabela_topo_pilha();
    item_tabela_t* item_existe = busca_item_tabela_simbolos(tabela_atual, node->valor.lexema);
    if (item_existe != NULL) {
        printf("Erro semântico: variável %s, na linha %d, já havia sido declarada na linha %d\n", item_existe->chave, node->valor.linha_token, item_existe->linha_token);
        free_pilha_tabelas();
        exit(ERR_DECLARED);
    }
}

void check_undeclared(asd_tree_t* node) {
    item_tabela_t* item_existe = buscar_item_pilha_tabelas(node->valor.lexema);
    if (item_existe == NULL) {
        printf("Erro semântico: variável %s, na linha %d, não delcarada\n", node->valor.lexema, node->valor.linha_token);
        free_pilha_tabelas();
        exit(ERR_UNDECLARED);
    }
}

void check_is_var(asd_tree_t* node) {
    item_tabela_t* item = buscar_item_pilha_tabelas(node->valor.lexema);
    // Aqui item não é NULL
    if (item == NULL) {
        printf("Deu ruim\n");
        exit(1);
    }
    if (item->natureza == NAT_FUNCAO) {
        printf("Erro semântico: função %s, na linha %d, usada como variável\n", node->valor.lexema, node->valor.linha_token);
        free_pilha_tabelas();
        exit(ERR_FUNCTION);
    }
}

void check_is_func(asd_tree_t* node) {
    item_tabela_t* item = buscar_item_pilha_tabelas(node->valor.lexema);
    // Aqui item não é NULL
    if (item == NULL) {
        printf("Deu ruim\n");
        exit(1);
    }
    if (item->natureza == NAT_IDENTIFICADOR) {
        printf("Erro semântico: variável %s, na linha %d, usada como função\n", node->valor.lexema, node->valor.linha_token);
        free_pilha_tabelas();
        exit(ERR_VARIABLE);
    }
}

extern array_argumento_t args_atual;

void check_args(asd_tree_t* node) {
    item_tabela_t* item = buscar_item_pilha_tabelas(node->valor.lexema);
    if (item == NULL) {
        printf("Deu ruim\n");
        exit(1);
    }
    int n_args_func = item->argumentos.tamanho_usado;
    int n_args_chamada = args_atual.tamanho_usado;
    if (n_args_chamada < n_args_func) {
        printf("Erro semântico: faltando argumentos na chamada da função %s na linha %d\n", node->valor.lexema, node->valor.linha_token);
        free_array_argumento(&args_atual);
        free_pilha_tabelas();
        exit(ERR_MISSING_ARGS);
    }
    if (n_args_chamada > n_args_func) {
        printf("Erro semântico: muitos argumentos na chamada da função %s na linha %d\n", node->valor.lexema, node->valor.linha_token);
        free_array_argumento(&args_atual);
        free_pilha_tabelas();
        exit(ERR_EXCESS_ARGS);
    }
    for (int i = 0; i < n_args_func; i++) {
        if (item->argumentos.itens[i].tipo_dado != args_atual.itens[n_args_chamada-i-1].tipo_dado) {
            printf("Erro semântico: tipos incompatíveis na chamada da função %s na linha %d\n", node->valor.lexema, node->valor.linha_token);
            free_array_argumento(&args_atual);
            free_pilha_tabelas();
            exit(ERR_WRONG_TYPE_ARGS);
        }
    }
    args_atual.tamanho_usado = 0;
    free_array_argumento(&args_atual);
}

void check_if_else(asd_tree_t* bloco_true, asd_tree_t* bloco_false) {
    if (bloco_true == NULL || bloco_false == NULL) {
        return;
    }
    if (bloco_true->valor.tipo_dado_inferido != bloco_false->valor.tipo_dado_inferido) {
        printf("Erro semântico: tipo errrado entre blocos do if-else nas linhas %d e %d\n", bloco_true->valor.linha_token, bloco_false->valor.linha_token);
        free_pilha_tabelas();
        exit(ERR_WRONG_TYPE);
    }
}

void insere_params_func_tabela(char* identificador, asd_tree_t* lista_params) {
    item_tabela_t* item_func = buscar_item_pilha_tabelas(identificador);
    while (lista_params != NULL) {
        // Insere param como var local na tabela da func
        check_declared(lista_params);
        insere_variavel_tabela(lista_params->valor, lista_params->valor.tipo_dado_inferido);
        // Insere param na lista de argumentos da func na tabela, pra poder checar dps se chamadas tão certas
        argumento_t arg;
        arg.tipo_dado = lista_params->valor.tipo_dado_inferido;
        insere_item_array_argumento(&(item_func->argumentos), arg);
        // Prox param
        if (lista_params->number_of_children == 0)
            lista_params = NULL;
        else
            lista_params = lista_params->children[0];
    }
}

void inferencia_tipo_op_binaria(asd_tree_t* op, asd_tree_t* op1, asd_tree_t* op2) {
    if (op1->valor.tipo_dado_inferido != op2->valor.tipo_dado_inferido) {
        printf("Erro semântico: tipo errrado entre \"%s\" e \"%s\" na linha %d\n", op1->valor.lexema, op2->valor.lexema, op1->valor.linha_token);
        free_pilha_tabelas();
        exit(ERR_WRONG_TYPE);
    }
    op->valor.tipo_dado_inferido = op1->valor.tipo_dado_inferido;
}

extern asd_tree_t* func_atual;

void inferencia_tipo_return(asd_tree_t* retorno, asd_tree_t* exp, tipo_dado_t tipo_retorno) {
    if (exp->valor.tipo_dado_inferido != tipo_retorno) {
        printf("Erro semântico: tipo incompatível de expressão e retorno na linha %d\n", exp->valor.linha_token);
        free_pilha_tabelas();
        exit(ERR_WRONG_TYPE);
    }
    retorno->valor.tipo_dado_inferido = tipo_retorno;
    item_tabela_t* item_func = buscar_item_pilha_tabelas(func_atual->valor.lexema);
    if (item_func == NULL) {
        printf("Deu ruim\n");
        exit(1);
    }
    if (retorno->valor.tipo_dado_inferido != item_func->tipo_dado) {
        printf("Erro semântico: tipo incompatível de retorno e função na linha %d\n", exp->valor.linha_token);
        free_pilha_tabelas();
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