%{
#include <stdio.h>
#include <string.h>
#include "parser.tab.h"
#include "token.h"
#include "utils.h"
#include "asd.h"
%}

%option noyywrap yylineno

%%

as { return TK_PR_AS; }
declare { return TK_PR_DECLARE; }
else { return TK_PR_ELSE; }
if { return TK_PR_IF; }
float { 
    yylval.tipo_dado = TIPO_DADO_FLOAT;
    return TK_PR_FLOAT;
}
int { 
    yylval.tipo_dado = TIPO_DADO_INT;
    return TK_PR_INT;
}
is { return TK_PR_IS;}
returns { return TK_PR_RETURNS; }
return { return TK_PR_RETURN; }
while { return TK_PR_WHILE; }
with { return TK_PR_WITH; }


! { return (int)(yytext[0]); }
\* { return (int)(yytext[0]); }
\/ { return (int)(yytext[0]); }
% { return (int)(yytext[0]); }
\+ { return (int)(yytext[0]); }
- { return (int)(yytext[0]); }
\< { return (int)(yytext[0]); }
> { return (int)(yytext[0]); }
\[ { return (int)(yytext[0]); }
\] { return (int)(yytext[0]); }
\( { return (int)(yytext[0]); }
\) { return (int)(yytext[0]); }
= { return (int)(yytext[0]); }
, { return (int)(yytext[0]); }
& { return (int)(yytext[0]); }
\| { return (int)(yytext[0]); }
; { return (int)(yytext[0]); }
\<\= { return TK_OC_LE; }
\>\= { return TK_OC_GE; }
\=\= { return TK_OC_EQ; }
\!\= { return TK_OC_NE; }

[a-z_][a-z0-9_]* { 
    valor_t* aux = (valor_t*) malloc(sizeof(valor_t));
    aux->lexema = strdup(yytext);
    aux->linha_token = yylineno;
    aux->tipo = TIPO_IDENTIFICADOR;
    yylval.valor_lexico = aux;
    return TK_ID; 
    /*
    yylval é uma var global usada pra passar o valor associado ao token pro bison
    valor_t representa o valor do token

    */
}

([0-9]+)?\.[0-9]+ { 
    valor_t* aux = (valor_t*) malloc(sizeof(valor_t));
    aux->lexema = strdup(yytext);
    aux->linha_token = yylineno;
    aux->tipo = TIPO_LITERAL;
    aux->tipo_dado_inferido = TIPO_DADO_FLOAT;
    yylval.valor_lexico = aux;
    return TK_LI_FLOAT; 
}
[0-9]+ { 
    valor_t* aux = (valor_t*) malloc(sizeof(valor_t));
    aux->lexema = strdup(yytext);
    aux->linha_token = yylineno;
    aux->tipo = TIPO_LITERAL;
    aux->tipo_dado_inferido = TIPO_DADO_INT;
    yylval.valor_lexico = aux;
    return TK_LI_INT; 
}



[\n\t\r\s ]

\/\/(.)*


. { return TK_ER; }

%%

int get_line_number(void) {
    return yylineno;
}