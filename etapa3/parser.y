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

Programa: Lista
Programa: { $$ = NULL; }
Lista: Elemento ',' Lista | Elemento ';'
Elemento: Def_func | Dec_var
Def_func: Cab_func Corpo_func
Cab_func: TK_ID TK_PR_RETURNS Tipo TK_PR_WITH Lista_params TK_PR_IS
Cab_func: TK_ID TK_PR_RETURNS Tipo TK_PR_IS
Lista_params: Parametro ',' Lista_params | Parametro
Parametro: TK_ID TK_PR_AS Tipo
Tipo: TK_PR_INT | TK_PR_FLOAT
Corpo_func: Bloco
Comando: Bloco
Comando: Dec_var_com {
    asd_add_child(arvore, $1);
}
Comando: Atrib
Comando: Chama_func
Comando: Retorno
Comando: Fluxo
Bloco: '[' Lista_com ']' | '[' ']'
Lista_com: Comando Lista_com { 
//    $$ = $1; 
  //  asd_add_child($1, $2);
 } // add o resto da lista de comandos como filho do primeiro comando
Lista_com: Comando { $$ = $1; }
Dec_var: TK_PR_DECLARE TK_ID TK_PR_AS Tipo
Dec_var_com: Dec_var // não vai na AST, ou seja, $$ = NULL?? ou nada?
// troca Dec_var pra poder acessar o TK_ID
// Dec_var_com: Dec_var TK_PR_WITH Literal { /*Cria no with, bota o ID do Dec_var como um filho, e o literal como outro filho*/ }
Dec_var_com: TK_PR_DECLARE Identificador TK_PR_AS Tipo TK_PR_WITH Literal { 
    // Cria nó "with" com 2 filhos: id e literal
    $$ = asd_new("with");
    asd_add_child($$, $2);
    asd_add_child($$, $6); 
}
Identificador: TK_ID { $$ = asd_new($1->lexema); free($1->lexema); free($1); }
Literal: TK_LI_INT { $$ = asd_new($1->lexema); free($1->lexema); free($1); }
Literal: TK_LI_FLOAT { $$ = asd_new($1->lexema); free($1->lexema); free($1); }
Atrib: TK_ID TK_PR_IS Expressao
Chama_func: TK_ID '(' Lista_args ')' | TK_ID '(' ')'
Lista_args: Arg ',' Lista_args | Arg
Arg: Expressao
Retorno: TK_PR_RETURN Expressao TK_PR_AS Tipo
Fluxo: Fluxo_cond | Fluxo_iter
Fluxo_cond: TK_PR_IF '(' Expressao ')' Bloco | TK_PR_IF '(' Expressao ')' Bloco TK_PR_ELSE Bloco
Fluxo_iter: TK_PR_WHILE '(' Expressao ')' Bloco
Expressao: Expressao '|' T7 | T7
T7: T7 '&' T6 | T6
T6: T6 TK_OC_EQ T5 | T6 TK_OC_NE T5 | T5
T5: T5 TK_OC_GE T4 | T5 TK_OC_LE T4 | T5 '<' T4 | T5 '>' T4 | T4
T4: T4 '+' T3 | T4 '-' T3 | T3
T3: T3 '*' T2
T3: T3 '/' T2 
T3: T3 '%' T2 
T3: T2 { $$ = $1; }
T2: '+' T2
T2: '-' T2 
T2: '!' T2 { $$ = asd_new("!"); asd_add_child($$, $2);}
T2: T1 { $$ = $1; }
T1: '(' Expressao ')'
T1: TK_ID { $$ = asd_new($1->lexema); free($1->lexema); free($1); }
T1: Literal { $$ = $1; }
T1: Chama_func
%%

void yyerror (char const *mensagem) {
    printf("Na linha %d, houve erro [ %s ]\n", get_line_number(), mensagem);
}