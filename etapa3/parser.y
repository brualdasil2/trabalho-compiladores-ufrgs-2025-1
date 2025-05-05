%{
#include <stdio.h>
#include <string.h>
#include "asd.h"
#include "token.h"
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

// tipo de não terminal
//%type<int> Programa
// tipo de terminal
//%token<asd_tree_t> TK_ID


// não vai fazer { $$ = asd_new("[]"); } no bloco vazio []!!!
// vai fazer { $$ = NULL; }
// Nas regras onde bloco aparece, considerar que ele pode ser nulo!

// site do schnorr, tutorial do bison

%%

Programa: Lista { 
    //printf("Lista -> Programa\n");
    arvore = $1;
}
Programa: { $$ = NULL; }
Lista: Elemento ',' Lista {
    //printf("Elemento, Lista -> Lista\n");
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
    //printf("Elemento; -> Lista\n");
    $$ = $1;
}
Elemento: Def_func { 
    //printf("Def_func -> Elemento\n");
    $$ = $1;
}
Elemento: Dec_var { 
    //printf("Dev_var -> Elemento\n");
    $$ = NULL;
}
Def_func: Cab_func Corpo_func { 
    //printf("Cab_func Corpo_func -> Def_func\n");
    $$ = $1;
    if ($2 != NULL) {
        asd_add_child($1, $2);    
    }
    //if (arvore == NULL) {
        // Primeira função, vira raiz
      //  arvore = $1;
    //}
}
Cab_func: Identificador TK_PR_RETURNS Tipo TK_PR_WITH Lista_params TK_PR_IS { 
    //printf("id returns tipo with lista_params is -> Cab_func\n");
    $$ = $1;
}
Cab_func: Identificador TK_PR_RETURNS Tipo TK_PR_IS { 
    //printf("id returns tipo is -> Cab_func");
    $$ = $1;
}
Lista_params: Parametro ',' Lista_params {
    //printf("Param , Lista_params -> Lista_params\n");
    $$ = NULL;
}
Lista_params: Parametro {
    //printf("Param -> Lista_params\n");
    $$ = NULL;
}
Parametro: Identificador TK_PR_AS Tipo { 
    //printf("id as Tipo -> Param\n");
    $$ = NULL;
    asd_free($1);
}
Tipo: TK_PR_INT { $$ = NULL; }
Tipo: TK_PR_FLOAT { $$ = NULL; }
Corpo_func: Bloco {
    //printf("Bloco -> Corpo_func\n"); 
    $$ = $1;
}
Comando: Bloco { 
    //printf("Bloco -> Comando\n");
    $$ = $1;
}
Comando: Dec_var_com { 
    //printf("Dec_var_com -> Comando\n");
    $$ = $1;
    // Pode ser NULL! Tratar isso na lista de comando
}
Comando: Dec_var_com_atrib {
    //printf("Dec_var_com_atrib -> Comando\n");
    $$ = $1;
}
Comando: Atrib {
    //printf("Atrib -> Comando\n");
    $$ = $1;
}
Comando: Chama_func {
    //printf("Chama_func -> Comando\n");
    $$ = $1;
}
Comando: Retorno {
    //printf("Retorno -> Comando\n");
    $$ = $1;
}
Comando: Fluxo {
    //printf("Fluxo -> Comando\n");
    $$ = $1;
}
Bloco: '[' Lista_com ']' { 
    //printf("[ Lista_com ] -> Bloco\n");
    $$ = $2;
}
Bloco: '[' ']' {
    //printf("[ ] -> Bloco\n");
    $$ = NULL;
}
Lista_com: Comando Lista_com { 
    //printf("Comando Lista_com -> Lista_com\n");
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
    //printf("Comando -> Lista_com\n");
    $$ = $1;
}
Dec_var: TK_PR_DECLARE Identificador TK_PR_AS Tipo { 
    //printf("declare id as Tipo -> Dec_var\n");
    $$ = NULL;
    // Nem todo identificador vai virar um nó, nesses casos deletamos o nó que foi alocado
    asd_free($2);
}
Dec_var_com: Dec_var { 
    //printf("Dec_var -> Dec_var_com\n");
    $$ = NULL;
}
// troca Dec_var pra poder acessar o TK_ID
// Dec_var_com_atrib: Dec_var TK_PR_WITH Literal { /*Cria no with, bota o ID do Dec_var como um filho, e o literal como outro filho*/ }
Dec_var_com_atrib: TK_PR_DECLARE Identificador TK_PR_AS Tipo TK_PR_WITH Literal { 
    //printf("dec id as tipo with lit -> Dec_var_com_atrib\n");
    // Cria nó "with" com 2 filhos: id e literal
    $$ = asd_new("with");
    asd_add_child($$, $2);
    asd_add_child($$, $6);
}
Identificador: TK_ID { 
    //printf("id -> Identificador\n");
    $$ = asd_new($1->lexema);
    free($1->lexema);
    free($1); 
}
Literal: TK_LI_INT { 
    //printf("lit_int -> Literal\n");
    $$ = asd_new($1->lexema);
    free($1->lexema);
    free($1);
}
Literal: TK_LI_FLOAT { 
    //printf("lit_float -> Literal\n");
    $$ = asd_new($1->lexema);
    free($1->lexema);
    free($1);
}
Atrib: Identificador TK_PR_IS Expressao { 
    //printf("id is exp -> Atrib\n");
    $$ = asd_new("is");
    asd_add_child($$, $1); 
    asd_add_child($$, $3);
}
Chama_func: Identificador '(' Lista_args ')' {
    //printf("id ( Lista_args ) -> Chama_func\n");
    // alocar espaço pra "call $1->label"
   // realloc($1->label, strlen("call ") + strlen($1->label))
    char* id_label = (char*) malloc(strlen($1->label) + 1);
    strcpy(id_label, $1->label);
    free($1->label);
    $1->label = (char*) malloc(strlen("call ") + strlen(id_label) + 1);
    $1->label[0] = '\0';
    strcat($1->label, "call ");
    strcat($1->label, id_label);
    asd_add_child($1, $3);
    free(id_label);
    $$ = $1;
}
Chama_func: Identificador '(' ')' {
    //printf("id ( ) -> Chama_func\n");
    // alocar espaço pra "call $1->label"
    char* id_label = (char*) malloc(strlen($1->label) + 1);
    strcpy(id_label, $1->label);
    free($1->label);
    $1->label = (char*) malloc(strlen("call ") + strlen(id_label) + 1);
    $1->label[0] = '\0';
    strcat($1->label, "call ");
    strcat($1->label, id_label);
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
    $$ = asd_new("return");
    asd_add_child($$, $2);
}
Fluxo: Fluxo_cond { $$ = $1; }
Fluxo: Fluxo_iter { $$ = $1; }
Fluxo_cond: TK_PR_IF '(' Expressao ')' Bloco {
    // TODO: considerar bloco pode ser NULL
    $$ = asd_new("if");
    asd_add_child($$, $3);
    if ($5 != NULL) {
        asd_add_child($$, $5);
    }
}
Fluxo_cond: TK_PR_IF '(' Expressao ')' Bloco TK_PR_ELSE Bloco {
    // TODO: considerar bloco pode ser NULL
    $$ = asd_new("if");
    asd_add_child($$, $3);
    if ($5 != NULL) {
        asd_add_child($$, $5);
    }
    if ($7 != NULL) {
        asd_add_child($$, $7);
    }
}
Fluxo_iter: TK_PR_WHILE '(' Expressao ')' Bloco {
    // TODO: considerar bloco pode ser NULL
    $$ = asd_new("while");
    asd_add_child($$, $3);
    if ($5 != NULL) {
        asd_add_child($$, $5);
    }
}
Expressao: Expressao '|' T7 {
    $$ = asd_new("|");
    asd_add_child($$, $1);
    asd_add_child($$, $3);
}
Expressao: T7 {
    //printf("T7 -> Expr\n");
    $$ = $1;
}
T7: T7 '&' T6 {
    $$ = asd_new("&");
    asd_add_child($$, $1);
    asd_add_child($$, $3);
}
T7: T6 { $$ = $1; }
T6: T6 TK_OC_EQ T5 {
    $$ = asd_new("==");
    asd_add_child($$, $1);
    asd_add_child($$, $3);
}
T6: T6 TK_OC_NE T5 { 
    $$ = asd_new("!=");
    asd_add_child($$, $1);
    asd_add_child($$, $3);
}
T6: T5 { $$ = $1; }
T5: T5 TK_OC_GE T4 { 
    $$ = asd_new(">=");
    asd_add_child($$, $1);
    asd_add_child($$, $3);
}
T5: T5 TK_OC_LE T4 {
    $$ = asd_new("<=");
    asd_add_child($$, $1);
    asd_add_child($$, $3);
}
T5: T5 '<' T4 {
    $$ = asd_new("<");
    asd_add_child($$, $1);
    asd_add_child($$, $3);
}
T5: T5 '>' T4 {
    $$ = asd_new(">");
    asd_add_child($$, $1);
    asd_add_child($$, $3);
}
T5: T4 { $$ = $1; }
T4: T4 '+' T3 { 
    //printf("T4 + T3 -> T4\n");
    $$ = asd_new("+");
    asd_add_child($$, $1);
    asd_add_child($$, $3);
}
T4: T4 '-' T3 {
    $$ = asd_new("-");
    asd_add_child($$, $1);
    asd_add_child($$, $3);
}
T4: T3 { $$ = $1; }
T3: T3 '*' T2 { 
    //printf("T3 * T2 -> T2\n");
    $$ = asd_new("*");
    asd_add_child($$, $1);
    asd_add_child($$, $3);
}
T3: T3 '/' T2  {
    $$ = asd_new("/");
    asd_add_child($$, $1);
    asd_add_child($$, $3);
}
T3: T3 '%' T2  {
    $$ = asd_new("%");
    asd_add_child($$, $1);
    asd_add_child($$, $3);
}
T3: T2 { $$ = $1; }
T2: '+' T2 {
    $$ = asd_new("+");
    asd_add_child($$, $2);
}
T2: '-' T2  {
    $$ = asd_new("-");
    asd_add_child($$, $2);
}
T2: '!' T2 {
    $$ = asd_new("!");
    asd_add_child($$, $2);
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