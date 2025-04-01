%{
#include <stdio.h>
int yylex(void);
void yyerror (char const *mensagem);
int get_line_number();
%}

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
%token TK_ID
%token TK_LI_INT
%token TK_LI_FLOAT
%token TK_ER

%define parse.error verbose

%%

Programa: Lista
Programa:
Lista: Elemento ',' Lista | Elemento ';'
Elemento: Def_func | Dec_var
Def_func: Cab_func Corpo_func
Cab_func: TK_ID TK_PR_RETURNS Tipo TK_PR_WITH Lista_params TK_PR_IS
Cab_func: TK_ID TK_PR_RETURNS Tipo TK_PR_IS
Lista_params: Parametro ',' Lista_params | Parametro
Parametro: TK_ID TK_PR_AS Tipo
Tipo: TK_PR_INT | TK_PR_FLOAT
Corpo_func: Bloco
Comando: Bloco | Dec_var_com | Atrib | Chama_func | Retorno | Fluxo
Bloco: '[' Lista_com ']' | '[' ']'
Lista_com: Comando Lista_com | Comando
Dec_var: TK_PR_DECLARE TK_ID TK_PR_AS Tipo
Dec_var_com: Dec_var | Dec_var TK_PR_WITH Literal
Literal: TK_LI_INT | TK_LI_FLOAT
Atrib: TK_ID TK_PR_IS Expressao
Chama_func: TK_ID '(' Lista_args ')' | TK_ID '(' ')'
Lista_args: Arg ',' Lista_args | Arg
Arg: Expressao
Retorno: TK_PR_RETURN Expressao TK_PR_AS Tipo

// testes
Expressao: TK_LI_INT
Fluxo: TK_PR_IF

%%

void yyerror (char const *mensagem) {
    printf("Na linha %d, houve erro [ %s ]\n", get_line_number(), mensagem);
}