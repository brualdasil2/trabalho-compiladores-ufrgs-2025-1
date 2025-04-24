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

Programa: Lista { $$ = NULL; }
Programa: { $$ = NULL; }
Lista: Elemento ',' Lista { $$ = NULL; }
Lista: Elemento ';' { $$ = NULL; }
Elemento: Def_func { $$ = NULL; }
Elemento: Dec_var { $$ = NULL; }
Def_func: Cab_func Corpo_func { $$ = NULL; }
Cab_func: Identificador TK_PR_RETURNS Tipo TK_PR_WITH Lista_params TK_PR_IS { $$ = NULL; }
Cab_func: Identificador TK_PR_RETURNS Tipo TK_PR_IS { $$ = NULL; }
Lista_params: Parametro ',' Lista_params { $$ = NULL; }
Lista_params: Parametro { $$ = NULL; }
Parametro: Identificador TK_PR_AS Tipo { $$ = NULL; }
Tipo: TK_PR_INT { $$ = NULL; }
Tipo: TK_PR_FLOAT { $$ = NULL; }
Corpo_func: Bloco { $$ = NULL; }
Comando: Bloco { $$ = NULL; }
Comando: Dec_var_com { $$ = NULL; }
Comando: Dec_var_com_atrib {
    arvore = asd_new("root");
    asd_add_child(arvore, $1);
}
Comando: Atrib { $$ = NULL; }
Comando: Chama_func { $$ = NULL; }
Comando: Retorno { $$ = NULL; }
Comando: Fluxo { $$ = NULL; }
Bloco: '[' Lista_com ']' { $$ = NULL; }
Bloco: '[' ']' { $$ = NULL; }
Lista_com: Comando Lista_com { 
//    $$ = $1; 
  //  asd_add_child($1, $2);
  $$ = NULL;
 } // add o resto da lista de comandos como filho do primeiro comando
Lista_com: Comando { $$ = NULL; }
Dec_var: TK_PR_DECLARE Identificador TK_PR_AS Tipo { $$ = NULL; }
Dec_var_com: Dec_var { $$ = NULL; } // não vai na AST, ou seja, $$ = NULL?? ou nada?
// troca Dec_var pra poder acessar o TK_ID
// Dec_var_com_atrib: Dec_var TK_PR_WITH Literal { /*Cria no with, bota o ID do Dec_var como um filho, e o literal como outro filho*/ }
Dec_var_com_atrib: TK_PR_DECLARE Identificador TK_PR_AS Tipo TK_PR_WITH Literal { 
    // Cria nó "with" com 2 filhos: id e literal
    $$ = asd_new("with");
    asd_add_child($$, $2);
    asd_add_child($$, $6); 
}
Identificador: TK_ID { $$ = asd_new($1->lexema); free($1->lexema); free($1); }
Literal: TK_LI_INT { $$ = asd_new($1->lexema); free($1->lexema); free($1); }
Literal: TK_LI_FLOAT { $$ = asd_new($1->lexema); free($1->lexema); free($1); }
Atrib: Identificador TK_PR_IS Expressao { $$ = NULL; }
Chama_func: Identificador '(' Lista_args ')' { $$ = NULL; }
Chama_func: Identificador '(' ')' { $$ = NULL; }
Lista_args: Arg ',' Lista_args { $$ = NULL; }
Lista_args: Arg { $$ = NULL; }
Arg: Expressao { $$ = NULL; }
Retorno: TK_PR_RETURN Expressao TK_PR_AS Tipo { $$ = NULL; }
Fluxo: Fluxo_cond { $$ = NULL; }
Fluxo: Fluxo_iter { $$ = NULL; }
Fluxo_cond: TK_PR_IF '(' Expressao ')' Bloco { $$ = NULL; }
Fluxo_cond: TK_PR_IF '(' Expressao ')' Bloco TK_PR_ELSE Bloco { $$ = NULL; }
Fluxo_iter: TK_PR_WHILE '(' Expressao ')' Bloco { $$ = NULL; }
Expressao: Expressao '|' T7 { $$ = NULL; }
Expressao: T7 { $$ = NULL; }
T7: T7 '&' T6 { $$ = NULL; }
T7: T6 { $$ = NULL; }
T6: T6 TK_OC_EQ T5 { $$ = NULL; }
T6: T6 TK_OC_NE T5 { $$ = NULL; }
T6: T5 { $$ = NULL; }
T5: T5 TK_OC_GE T4 { $$ = NULL; }
T5: T5 TK_OC_LE T4 { $$ = NULL; }
T5: T5 '<' T4 { $$ = NULL; }
T5: T5 '>' T4 { $$ = NULL; }
T5: T4 { $$ = NULL; }
T4: T4 '+' T3 { $$ = NULL; }
T4: T4 '-' T3 { $$ = NULL; }
T4: T3 { $$ = NULL; }
T3: T3 '*' T2 { $$ = NULL; }
T3: T3 '/' T2  { $$ = NULL; }
T3: T3 '%' T2  { $$ = NULL; }
T3: T2 { $$ = NULL; }
T2: '+' T2 { $$ = NULL; }
T2: '-' T2  { $$ = NULL; }
T2: '!' T2 { $$ = NULL; }
T2: T1 { $$ = NULL; }
T1: '(' Expressao ')' { $$ = NULL; }
T1: Identificador { $$ = NULL; }
T1: Literal { $$ = NULL; }
T1: Chama_func { $$ = NULL; }
%%

void yyerror (char const *mensagem) {
    printf("Na linha %d, houve erro [ %s ]\n", get_line_number(), mensagem);
}