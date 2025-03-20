%{
#include <stdio.h>
#include <string.h>
#include "tokens.h"
%}

%option noyywrap yylineno

%%

[a-z_][a-z0-9_]* { return TK_ID; }

[0-9]+ { return TK_LI_INT; }

\/\/(.)*

[-] { return yytext[0]; }

[\n\t\r\s ]

. { return TK_ER; }

%%

int get_line_number(void) {
	return yylineno;
}
