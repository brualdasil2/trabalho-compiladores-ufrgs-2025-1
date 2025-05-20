#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "item_tabela.h"
#include "tabela_simbolos.h"
#include "pilha_tabelas.h"

#define N_ITENS 15

void check_item_tabela(tabela_simbolos_t* tabela, char* chave) {
    item_tabela_t* busca_item = busca_item_tabela_simbolos(tabela, chave);
    if (busca_item == NULL) {
        printf("%s não está na tabela\n", chave);
    }
    else {
        printf("%s está na tabela\n", chave);
    }
}

void check_item_pilha(char* chave) {
    item_tabela_t* busca_item = buscar_item_pilha_tabelas(chave);
    if (busca_item == NULL) {
        printf("%s não está em nenhuma tabela\n", chave);
    }
    else {
        printf("%s está em alguma tabela\n", chave);
    }
}


void teste_eds() {
    item_tabela_t item;

    // Cria primeira tabela e add na pilha

    printf("PUSH tabela\n");
    tabela_simbolos_t* tabela = init_tabela();
    push_pilha_tabelas(tabela);

    printf("Add A - O no topo\n");
    // Inicializa item
    item.chave = (char*) malloc(strlen("my_var_A")+1);
    strcpy(item.chave, "my_var_A");
    item.natureza = NAT_IDENTIFICADOR;
    item.tipo = INT;
    init_array_argumento(&(item.argumentos));
    // Insere na tabela
    tabela = get_tabela_topo_pilha();
    insere_item_tabela_simbolos(tabela, item);

    // Inicializa e insere outros N-1 itens na primeira tabela
    for (int i = 0; i < N_ITENS-1; i++) {
        char* aux = (char*) malloc(strlen(item.chave)+1);
        strcpy(aux, item.chave);
        int ultima_letra = strlen(aux)-1;
        aux[ultima_letra]++;
        item.chave = aux;
        init_array_argumento(&(item.argumentos));
        tabela = get_tabela_topo_pilha();
        insere_item_tabela_simbolos(tabela, item);
    }

    // Cria segunda tabela e add na pilha

    printf("PUSH tabela\n");
    tabela = init_tabela();
    push_pilha_tabelas(tabela);

    printf("Add a - o no topo\n");
    // Inicializa item
    item.chave = (char*) malloc(strlen("my_var_a")+1);
    strcpy(item.chave, "my_var_a");
    item.natureza = NAT_IDENTIFICADOR;
    item.tipo = INT;
    init_array_argumento(&(item.argumentos));
    // Insere na tabela
    tabela = get_tabela_topo_pilha();
    insere_item_tabela_simbolos(tabela, item);

    // Inicializa e insere outros N-1 itens na segunda tabela
    for (int i = 0; i < N_ITENS-1; i++) {
        char* aux = (char*) malloc(strlen(item.chave)+1);
        strcpy(aux, item.chave);
        int ultima_letra = strlen(aux)-1;
        aux[ultima_letra]++;
        item.chave = aux;
        item.natureza = NAT_IDENTIFICADOR;
        item.tipo = INT;
        init_array_argumento(&(item.argumentos));
        tabela = get_tabela_topo_pilha();
        insere_item_tabela_simbolos(tabela, item);
    }

    // Busuca na pilha em todas as tabelas.
    // Todos vão dar ESTÁ

    check_item_pilha("my_var_A");
    check_item_pilha("my_var_G");
    check_item_pilha("my_var_a");
    check_item_pilha("my_var_g");

    // Deleta a tabela do topo (letras minusculas)

    printf("POP tabela\n");
    pop_pilha_tabelas();

    // Busuca na pilha em todas as tabelas.
    // Maiúsculas vão dar ESTÁ
    // Minúsculas vão dar NÃO ESTÁ

    check_item_pilha("my_var_A");
    check_item_pilha("my_var_G");
    check_item_pilha("my_var_a");
    check_item_pilha("my_var_g");

    // Cria terceira tabela e add no topo da pilha


    printf("PUSH tabela\n");
    tabela = init_tabela();
    push_pilha_tabelas(tabela);

    printf("Add Z - L no topo\n");
    // Inicializa item
    item.chave = (char*) malloc(strlen("my_var_Z")+1);
    strcpy(item.chave, "my_var_Z");
    item.natureza = NAT_IDENTIFICADOR;
    item.tipo = INT;
    init_array_argumento(&(item.argumentos));
    // Insere na tabela
    tabela = get_tabela_topo_pilha();
    insere_item_tabela_simbolos(tabela, item);

    // Insere 15 itens my_varX na terceira tabela
    for (int i = 0; i < N_ITENS-1; i++) {
        char* aux = (char*) malloc(strlen(item.chave)+1);
        strcpy(aux, item.chave);
        int ultima_letra = strlen(aux)-1;
        aux[ultima_letra]--;
        item.chave = aux;
        item.natureza = NAT_IDENTIFICADOR;
        item.tipo = INT;
        init_array_argumento(&(item.argumentos));
        tabela = get_tabela_topo_pilha();
        insere_item_tabela_simbolos(tabela, item);
    }

    // Busuca na pilha em todas as tabelas.
    // Maiúsculas do inicio vão dar ESTÁ
    // Minúsculas vão dar NÃO ESTÁ
    // Maiúsculas do fim vão dar ESTÀ

    check_item_pilha("my_var_A");
    check_item_pilha("my_var_G");
    check_item_pilha("my_var_a");
    check_item_pilha("my_var_g");
    check_item_pilha("my_var_Z");
    check_item_pilha("my_var_V");

    // Inicializa item de função, com lista de args
    item.natureza = NAT_FUNCAO;
    item.tipo = FLOAT;
    item.chave = (char*) malloc(strlen("add_float")+1);
    strcpy(item.chave, "add_float");
    init_array_argumento(&(item.argumentos));
    argumento_t arg;
    arg.tipo = FLOAT;
    insere_item_array_argumento(&(item.argumentos), arg);
    arg.tipo = FLOAT;
    insere_item_array_argumento(&(item.argumentos), arg);
    // Insere na tabela
    tabela = get_tabela_topo_pilha();
    insere_item_tabela_simbolos(tabela, item);

    printf("\nBusca por add_float func\n");
    item_tabela_t* item_buscado = buscar_item_pilha_tabelas("add_float");
    if (item_buscado == NULL) {
        printf("add_float não encontrado\n");
    }
    else {
        printf("Chave: %s\n", item_buscado->chave);
        printf("Natureza: %d\n", item_buscado->natureza);
        printf("Tipo: %d\n", item_buscado->tipo);
        for (int i = 0; i < item_buscado->argumentos.tamanho_usado; i++) {
            argumento_t arg_achado = item_buscado->argumentos.itens[i];
            printf("Argumento: %d\n", arg_achado.tipo);
        }
    }




    printf("FREE tudo\n");

    free_pilha_tabelas();
    // TODO: M=FIx memleak here
}
