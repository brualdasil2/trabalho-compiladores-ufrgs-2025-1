%{
#include <stdio.h>
#include <string.h>
#include "asd.h"
#include "token.h"
#include "pilha_tabelas.h"
#include "tabela_simbolos.h"
#include "argumento.h"
int yylex(void);
void yyerror (char const *mensagem);
int get_line_number();

extern asd_tree_t *arvore;
%}

// Onde valor_t é alocado? No scanner.l!!

%code requires {
    #include "token.h"
    #include "asd.h"
}

// campos podem ser ou nó ou valor lexico
%union {
    asd_tree_t* no;
    valor_t* valor_lexico;
}

%token TK_PR_AS
%token TK_PR_DECLARE
%token TK_PR_ELSE
%token TK_PR_FLOAT
%token TK_PR_IF
%token TK_PR_INT
%token TK_PR_IS
%token TK_PR_RETURN
%token TK_PR_RETURNS
%token TK_PR_WHILE
%token TK_PR_WITH
%token TK_OC_LE
%token TK_OC_GE
%token TK_OC_EQ
%token TK_OC_NE
%token<valor_lexico> TK_ID
%token<valor_lexico> TK_LI_INT
%token<valor_lexico> TK_LI_FLOAT
%token TK_ER

%define parse.error verbose

%type<no> Programa
%type<no> Lista
%type<no> Elemento
%type<no> Def_func
%type<no> Cab_func
%type<no> Lista_params
%type<no> Parametro
%type<no> Tipo
%type<no> Corpo_func
%type<no> Comando
%type<no> Bloco
%type<no> Lista_com
%type<no> Dec_var
%type<no> Dec_var_com
%type<no> Dec_var_com_atrib
%type<no> Identificador
%type<no> Literal
%type<no> Atrib
%type<no> Chama_func
%type<no> Lista_args
%type<no> Arg
%type<no> Retorno
%type<no> Fluxo
%type<no> Fluxo_cond
%type<no> Fluxo_iter
%type<no> Expressao
%type<no> T7
%type<no> T6
%type<no> T5
%type<no> T4
%type<no> T3
%type<no> T2
%type<no> T1

%%


Programa: Cria_tabela_global Lista Free_tabela_global { 
    arvore = $2;
}
Programa: { $$ = NULL; }
Cria_tabela_global: {
    init_pilha_tabelas();
    tabela_simbolos_t* tabela = init_tabela();
    push_pilha_tabelas(tabela);
}
Free_tabela_global: {
    free_pilha_tabelas();
}
Lista: Elemento ',' Lista {
    if ($3 == NULL && $1 != NULL) {
        // Lista pode ser NULL (dec var global), retorna só a função
        $$ = $1;        
    }
    else if ($1 == NULL && $3 != NULL) {
        // Elemento pode ser NULL, retorna só o resto da lista
        $$ = $3;
    }
    else if ($1 == NULL && $3 == NULL) {
        $$ = NULL;
    }
    else {
        // Os dois existem, bota lista de filho do elemento
        asd_add_child($1, $3);
        $$ = $1;
    }
}
Lista: Elemento ';' { 
    $$ = $1;
}
Elemento: Def_func { 
    $$ = $1;
}
Elemento: Dec_var { 
    $$ = NULL;
}
Def_func: Cab_func Corpo_func { 
    $$ = $1;
    if ($2 != NULL) {
        asd_add_child($1, $2);    
    }
}
Cab_func: Identificador TK_PR_RETURNS Tipo TK_PR_WITH Lista_params TK_PR_IS { 
    $$ = $1;
}
Cab_func: Identificador TK_PR_RETURNS Tipo TK_PR_IS { 
    $$ = $1;
}
Lista_params: Parametro ',' Lista_params {
    $$ = NULL;
}
Lista_params: Parametro {
    $$ = NULL;
}
Parametro: Identificador TK_PR_AS Tipo { 
    $$ = NULL;
    asd_free($1);
}
Tipo: TK_PR_INT { $$ = NULL; }
Tipo: TK_PR_FLOAT { $$ = NULL; }
Corpo_func: Bloco {
    $$ = $1;
}
Comando: Bloco { 
    $$ = $1;
}
Comando: Dec_var_com { 
    $$ = $1;
}
Comando: Dec_var_com_atrib {
    $$ = $1;
}
Comando: Atrib {
    $$ = $1;
}
Comando: Chama_func {
    $$ = $1;
}
Comando: Retorno {
    $$ = $1;
}
Comando: Fluxo {
    $$ = $1;
}
Bloco: '[' Lista_com ']' { 
    $$ = $2;
}
Bloco: '[' ']' {
    $$ = NULL;
}
Lista_com: Comando Lista_com { 
    if ($2 == NULL && $1 != NULL) {
        // Lista_com pode ser NULL, retorna só o Comando
        $$ = $1;
    }
    else if ($1 == NULL && $2 != NULL) {
        // Comando pode ser NULL, retorna só a Lista_com pra ligar com os de cima
        $$ = $2;
    }
    else if ($1 == NULL && $2 == NULL) {
        $$ = NULL;
    }
    else {
        // Comando e Lista_com existem, bota Lista_com como filho e retorna o comando
        asd_add_child($1, $2);
        $$ = $1;
    }
}
Lista_com: Comando {
    $$ = $1;
}
Dec_var: TK_PR_DECLARE Identificador TK_PR_AS Tipo { 
    valor_t valor = $2->valor;
    valor.lexema = strdup($2->valor.lexema);
    tabela_simbolos_t* tabela = get_tabela_topo_pilha();
    item_tabela_t item;
    item.chave = valor.lexema;
    item.natureza = NAT_IDENTIFICADOR;
    item.tipo = INT;
    init_array_argumento(&(item.argumentos));
    item.linha_token = valor.linha_token;
    insere_item_tabela_simbolos(tabela, item);

    $$ = NULL;
    // Nem todo identificador vai virar um nó, nesses casos deletamos o nó que foi alocado
    asd_free($2);
}
Dec_var_com: Dec_var { 
    $$ = NULL;
}
Dec_var_com_atrib: TK_PR_DECLARE Identificador TK_PR_AS Tipo TK_PR_WITH Literal { 
    valor_t valor = valor_simples("with");
    $$ = asd_create_and_add_2(valor, $2, $6);
}
Identificador: TK_ID {
    $$ = asd_new(*$1);
    free($1->lexema);
    free($1);
}
Literal: TK_LI_INT { 
    $$ = asd_new(*$1);
    free($1->lexema);
    free($1);
}
Literal: TK_LI_FLOAT { 
    $$ = asd_new(*$1);
    free($1->lexema);
    free($1);
}
Atrib: Identificador TK_PR_IS Expressao { 
    valor_t valor = valor_simples("is");
    $$ = asd_create_and_add_2(valor, $1, $3);
}
Chama_func: Identificador '(' Lista_args ')' {
    // alocar espaço pra "call $1->valor.lexema"
   // realloc($1->valor.lexema, strlen("call ") + strlen($1->valor.lexema))
    char* id_label = (char*) malloc(strlen($1->valor.lexema) + 1);
    strcpy(id_label, $1->valor.lexema);
    free($1->valor.lexema);
    $1->valor.lexema = (char*) malloc(strlen("call ") + strlen(id_label) + 1);
    $1->valor.lexema[0] = '\0';
    strcat($1->valor.lexema, "call ");
    strcat($1->valor.lexema, id_label);
    asd_add_child($1, $3);
    free(id_label);
    $$ = $1;
}
Chama_func: Identificador '(' ')' {
    // alocar espaço pra "call $1->valor.lexema"
    char* id_label = (char*) malloc(strlen($1->valor.lexema) + 1);
    strcpy(id_label, $1->valor.lexema);
    free($1->valor.lexema);
    $1->valor.lexema = (char*) malloc(strlen("call ") + strlen(id_label) + 1);
    $1->valor.lexema[0] = '\0';
    strcat($1->valor.lexema, "call ");
    strcat($1->valor.lexema, id_label);
    free(id_label);
    $$ = $1;
}
Lista_args: Arg ',' Lista_args {
    asd_add_child($1, $3);
    $$ = $1;
}
Lista_args: Arg { $$ = $1; }
Arg: Expressao { $$ = $1; }
Retorno: TK_PR_RETURN Expressao TK_PR_AS Tipo {
    valor_t valor = valor_simples("return");
    $$ = asd_create_and_add_1(valor, $2);
}
Fluxo: Fluxo_cond { $$ = $1; }
Fluxo: Fluxo_iter { $$ = $1; }
Fluxo_cond: TK_PR_IF '(' Expressao ')' Bloco {
    valor_t valor = valor_simples("if");
    $$ = asd_create_and_add_2(valor, $3, $5);
}
Fluxo_cond: TK_PR_IF '(' Expressao ')' Bloco TK_PR_ELSE Bloco {
    valor_t valor = valor_simples("if");
    $$ = asd_create_and_add_3(valor, $3, $5, $7);
}
Fluxo_iter: TK_PR_WHILE '(' Expressao ')' Bloco {
    valor_t valor = valor_simples("while");
    $$ = asd_create_and_add_2(valor, $3, $5);
}
Expressao: Expressao '|' T7 {
    valor_t valor = valor_simples("|");
    $$ = asd_create_and_add_2(valor, $1, $3);
}
Expressao: T7 {
    $$ = $1;
}
T7: T7 '&' T6 {
    valor_t valor = valor_simples("&");
    $$ = asd_create_and_add_2(valor, $1, $3);
}
T7: T6 { $$ = $1; }
T6: T6 TK_OC_EQ T5 {
    valor_t valor = valor_simples("==");
    $$ = asd_create_and_add_2(valor, $1, $3);
}
T6: T6 TK_OC_NE T5 { 
    valor_t valor = valor_simples("!=");
    $$ = asd_create_and_add_2(valor, $1, $3);
}
T6: T5 { $$ = $1; }
T5: T5 TK_OC_GE T4 { 
    valor_t valor = valor_simples(">=");
    $$ = asd_create_and_add_2(valor, $1, $3);
}
T5: T5 TK_OC_LE T4 {
    valor_t valor = valor_simples("<=");
    $$ = asd_create_and_add_2(valor, $1, $3);
}
T5: T5 '<' T4 {
    valor_t valor = valor_simples("<");
    $$ = asd_create_and_add_2(valor, $1, $3);
}
T5: T5 '>' T4 {
    valor_t valor = valor_simples(">");
    $$ = asd_create_and_add_2(valor, $1, $3);
}
T5: T4 { $$ = $1; }
T4: T4 '+' T3 { 
    //printf("T4 + T3 -> T4\n");
    valor_t valor = valor_simples("+");
    $$ = asd_create_and_add_2(valor, $1, $3);
}
T4: T4 '-' T3 {
    valor_t valor = valor_simples("-");
    $$ = asd_create_and_add_2(valor, $1, $3);
}
T4: T3 { $$ = $1; }
T3: T3 '*' T2 { 
    //printf("T3 * T2 -> T2\n");
    valor_t valor = valor_simples("*");
    $$ = asd_create_and_add_2(valor, $1, $3);
}
T3: T3 '/' T2  {
    valor_t valor = valor_simples("/");
    $$ = asd_create_and_add_2(valor, $1, $3);
}
T3: T3 '%' T2  {
    valor_t valor = valor_simples("%");
    $$ = asd_create_and_add_2(valor, $1, $3);
}
T3: T2 { $$ = $1; }
T2: '+' T2 {
    valor_t valor = valor_simples("+");
    $$ = asd_create_and_add_1(valor, $2);
}
T2: '-' T2  {
    valor_t valor = valor_simples("-");
    $$ = asd_create_and_add_1(valor, $2);
}
T2: '!' T2 {
    valor_t valor = valor_simples("!");
    $$ = asd_create_and_add_1(valor, $2);
}
T2: T1 { $$ = $1; }
T1: '(' Expressao ')' { $$ = $2; }
T1: Identificador { $$ = $1; }
T1: Literal { $$ = $1; }
T1: Chama_func { $$ = $1; }
%%

void yyerror (char const *mensagem) {
    printf("Na linha %d, houve erro [ %s ]\n", get_line_number(), mensagem);
}