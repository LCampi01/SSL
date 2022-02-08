%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "symbolTable.h"
    #include "stack.h"
    int yylex(void);
    void yyerror(char *s);
%}

%union{char* string; char* punctuator; char* replaceText; char* element; char* replaceIfdef;}
%token DEFINE UNDEF IFDEF ENDIF INCLUDE NUMERAL NEWLINE RPAR RBRACE RBRACKET COMMENT;
%token <string> IDENTIFIER
%token <punctuator> PUNCTUATOR
%token <replaceText> REPLACETEXT
%token <element> LPAR LBRACE LBRACKET
%token <replaceIfdef> REPLACEIFDEF
%start UNIT

%%
    UNIT: BASE
        | BASE UNIT
        ;

    BASE: DIRECTIVE
        | IFDIRECTIVE
        | TEXT
        | LPAR {balancing($1);}
        | LBRACE {balancing($1);}
        | LBRACKET {balancing($1);}
        | RPAR  {checkRPAR();}
        | RBRACKET {checkRBRACKET();}
        | RBRACE {checkRBRACE();}
        | UNIT
        ;

    DIRECTIVE:  NUMERAL INCLUDE PUNCTUATOR IDENTIFIER PUNCTUATOR NEWLINE {include($4);}
            |   NUMERAL DEFINE IDENTIFIER REPLACETEXT NEWLINE {define($3, $4);}
            |   NUMERAL UNDEF IDENTIFIER NEWLINE {undef($3);}
            ;
    
    IFDIRECTIVE: NUMERAL IFDEF IDENTIFIER NEWLINE REPLACEMENT NEWLINE NUMERAL ENDIF
            |    NUMERAL IFDEF IDENTIFIER NEWLINE NOTREPLACE NEWLINE NUMERAL ENDIF
            ;

    REPLACEMENT: REPLACEIFDEF {printf($1);}
            |    REPLACEMENT REPLACEIFDEF {printf($2);}
            ;
    
    NOTREPLACE: IDENTIFIER
            | PUNCTUATOR
            | LPAR
            | LBRACE
            | LBRACKET
            | RPAR
            | RBRACE
            | RBRACKET
            | COMMENT
            | NEWLINE
            | NOTREPLACE NEWLINE
            | NOTREPLACE IDENTIFIER
            | NOTREPLACE PUNCTUATOR
            | NOTREPLACE LPAR
            | NOTREPLACE LBRACKET
            | NOTREPLACE LBRACE
            | NOTREPLACE RPAR
            | NOTREPLACE RBRACKET
            | NOTREPLACE RBRACE
            | NOTREPLACE COMMENT
            ;
    
    TEXT: IDENTIFIER {lookupFunction($1);}
        | NEWLINE   {printf("\n");}
        | COMMENT
        | PUNCTUATOR {printf($1);}
        ;

%%

int main(){
    return(yyparse());
}

void yyerror(char *s){
    printf("\n%s\n", s);
}

int yywrap(){
    return 1;
}

    
void include(char* includedFile){
    FILE *archivoInclude;
    archivoInclude = fopen(includedFile, "r+");
    if (archivoInclude == NULL){
        printf("\x1b[31m");
        printf("%s", includedFile);
        printf(" no pudo ser abierto \x1b[0m \n");
        exit(-1);
    } else {
        int c;
        while((c = fgetc(archivoInclude)) != EOF)
            putchar(c);
    }
    fclose(archivoInclude);   
    return; 
}

void define(char* definedConstant, char* value) {
    install(definedConstant, value);
    return;
}

void undef(char* undefinedConstant) {
    rem(undefinedConstant);
    return;
}

void lookupFunction(char* value){
    struct nlist *found;
    found = lookup(value);
    if (found != NULL) {
        printf(found->val, " ");
    
    }else {
        printf(value, " ");
    }
}

void balancing(char* element) {
    push(element);
    printf(element);
}

void checkRPAR(){
    char* poppedValue = pop();
    if(strcmp(poppedValue, "(") != 0){
        fprintf(stderr, "\x1b[31m \nError de balanceo \x1b[0m \n");
        abort();
    }
    printf(")");
    return;
}

void checkRBRACE(){
    char* poppedValue = pop();
    if(strcmp(poppedValue, "{") != 0){
        fprintf(stderr, "\x1b[31m \nError de balanceo \x1b[0m \n");
        abort();
    }
    printf("}");
    return;
}

void checkRBRACKET(){
    char* poppedValue = pop();
    if(strcmp(poppedValue, "[") != 0){
        fprintf(stderr, "\x1b[31m \nError de balanceo \x1b[0m \n");
        abort();
    }
    printf("]");
    return;
}

void ifdef(char* identifier){
    char* textReturn;
    if(lookup(identifier) == NULL) {
            return 0;
    }
}