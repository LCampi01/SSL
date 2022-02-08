%{
static int directiveAux;
static int ifdefAux;
#include "y.tab.h"
#include "symbolTable.h"
void yyerror(char*);
%}

%%
"define"                {extern int directiveAux; directiveAux = 1; return DEFINE;}
"include"               return INCLUDE;
"ifdef"                 {extern int ifdefAux; ifdefAux = 1; return IFDEF;}
"undef"                 return UNDEF;
"endif"                 {extern int ifdefAux; ifdefAux = 0; return ENDIF;}
\/\/.*\n                {extern int ifdefAux; if(ifdefAux != 3) return COMMENT; yylval.replaceIfdef = strdup(yytext); return REPLACEIFDEF;}
\/\*(.|\n)*\*\/         {extern int ifdefAux; if(ifdefAux != 3) return COMMENT; yylval.replaceIfdef = strdup(yytext); return REPLACEIFDEF;}
\(                      {extern int ifdefAux; if(ifdefAux != 3) {yylval.element = strdup(yytext); return LPAR;}; yylval.replaceIfdef = strdup(yytext); return REPLACEIFDEF;}
\)                      {extern int ifdefAux; if(ifdefAux != 3) return RPAR; yylval.replaceIfdef = strdup(yytext); return REPLACEIFDEF;}
\{                      {extern int ifdefAux; if(ifdefAux != 3) {yylval.element = strdup(yytext); return LBRACE;}; yylval.replaceIfdef = strdup(yytext); return REPLACEIFDEF;}
\}                      {extern int ifdefAux; if(ifdefAux != 3) return RBRACE; yylval.replaceIfdef = strdup(yytext); return REPLACEIFDEF;}
\[                      {extern int ifdefAux; if(ifdefAux != 3) {yylval.element = strdup(yytext); return LBRACKET;}; yylval.replaceIfdef = strdup(yytext); return REPLACEIFDEF;}
\]                      {extern int ifdefAux; if(ifdefAux != 3) return RBRACKET; yylval.replaceIfdef = strdup(yytext); return REPLACEIFDEF;}
\#                      return NUMERAL;
"\n"                    return NEWLINE;
[%\\=,"';:<>+-\/]+      {extern int ifdefAux; if(ifdefAux != 3) {yylval.punctuator = strdup(yytext); return PUNCTUATOR;}; yylval.replaceIfdef = strdup(yytext); return REPLACEIFDEF;}
[a-zA-Z0-9.]+           {extern int ifdefAux; if (ifdefAux == 1 && lookup(yytext) != NULL) ifdefAux = 2; if (ifdefAux != 3) { extern int directiveAux; if (directiveAux == 2) { directiveAux = 0; yylval.replaceText = strdup(yytext); return REPLACETEXT;}; if (directiveAux == 1) directiveAux = 2; yylval.string = strdup(yytext); if(ifdefAux == 2) ifdefAux = 3; return IDENTIFIER; } yylval.replaceIfdef = strdup(yytext); return REPLACEIFDEF;}
