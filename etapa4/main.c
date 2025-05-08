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


int main() {
    item_tabela_t item;
    item.natureza = IDENTIFICADOR;
    item.tipo = INT;
    item.chave = (char*) malloc(strlen("my_varA")+1);
    strcpy(item.chave, "my_varA");

    // Cria primeira tabela e add na pilha

    printf("PUSH tabela\n");
    tabela_simbolos_t* tabela = init_tabela();
    push_pilha_tabelas(tabela);

    printf("Add A - O no topo\n");

    // Insere 15 itens my_varX na primeira tabela
    for (int i = 0; i < N_ITENS; i++) {
        tabela = get_tabela_topo_pilha();
        insere_item_tabela_simbolos(tabela, item);
        char* aux = (char*) malloc(strlen(item.chave)+1);
        strcpy(aux, item.chave);
        aux[6]++;
        item.chave = aux;
    }

    // Cria segunda tabela e add na pilha

    printf("PUSH tabela\n");
    tabela = init_tabela();
    push_pilha_tabelas(tabela);

    printf("Add a - o no topo\n");
    item.chave[6] = 'a';

    // Insere 15 itens my_varX na segunda tabela
    for (int i = 0; i < N_ITENS; i++) {
        tabela = get_tabela_topo_pilha();
        insere_item_tabela_simbolos(tabela, item);
        char* aux = (char*) malloc(strlen(item.chave)+1);
        strcpy(aux, item.chave);
        aux[6]++;
        item.chave = aux;
    }

    // Busuca na pilha em todas as tabelas.
    // Todos vão dar ESTÁ

    check_item_pilha("my_varA");
    check_item_pilha("my_varG");
    check_item_pilha("my_vara");
    check_item_pilha("my_varg");

    // Deleta a tabela do topo (letras minusculas)

    printf("POP tabela\n");
    pop_pilha_tabelas();

    // Busuca na pilha em todas as tabelas.
    // Maiúsculas vão dar ESTÁ
    // Minúsculas vão dar NÃO ESTÁ

    check_item_pilha("my_varA");
    check_item_pilha("my_varG");
    check_item_pilha("my_vara");
    check_item_pilha("my_varg");

    // Cria terceira tabela e add no topo da pilha


    printf("PUSH tabela\n");
    tabela = init_tabela();
    push_pilha_tabelas(tabela);

    printf("Add Z - L no topo\n");
    item.chave[6] = 'Z';

    // Insere 15 itens my_varX na terceira tabela
    for (int i = 0; i < N_ITENS; i++) {
        tabela = get_tabela_topo_pilha();
        insere_item_tabela_simbolos(tabela, item);
        char* aux = (char*) malloc(strlen(item.chave)+1);
        strcpy(aux, item.chave);
        aux[6]--;
        item.chave = aux;
    }

    // Busuca na pilha em todas as tabelas.
    // Maiúsculas do inicio vão dar ESTÁ
    // Minúsculas vão dar NÃO ESTÁ
    // Maiúsculas do fim vão dar ESTÀ

    check_item_pilha("my_varA");
    check_item_pilha("my_varG");
    check_item_pilha("my_vara");
    check_item_pilha("my_varg");
    check_item_pilha("my_varZ");
    check_item_pilha("my_varV");

    printf("FREE tudo\n");
    
    free_pilha_tabelas();

}