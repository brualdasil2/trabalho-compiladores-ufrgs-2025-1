%{
#include <stdio.h>
#include <string.h>
#include "parser.tab.h"
%}

%option noyywrap yylineno

%%

as { return TK_PR_AS; }
declare { return TK_PR_DECLARE; }
else { return TK_PR_ELSE; }
float { return TK_PR_FLOAT; }
if { return TK_PR_IF; }
int { return TK_PR_INT; }
is { return TK_PR_IS; }
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

[a-z_][a-z0-9_]* { return TK_ID; }

([0-9]+)?\.[0-9]+ { return TK_LI_FLOAT; }
[0-9]+ { return TK_LI_INT; }



[\n\t\r\s ]

\/\/(.)*


. { return TK_ER; }

%%

int get_line_number(void) {
    return yylineno;
}