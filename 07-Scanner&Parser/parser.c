#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parser.h"
#include "symbolTable.h"
#include "scanner.h"
#include "stack.h"

void Unit(Token currentToken);
void Base(Token currentToken);

Token Text(Token currentToken) {
    if(currentToken.type == identifier) {
        struct nlist *found;
            found = lookup(currentToken.value);
            if (found != NULL) {
                printf(found->val, " ");
                printf(" ");
            
            }else {
                printf(currentToken.value, " ");
                printf(" ");
            }
    } else 
        printf(currentToken.value, " ");
    Token aux = getNextToken();
    if(aux.type == identifier || aux.type == punctuator || aux.type == newLine || aux.type == comment)
        Text(aux);
    else
        return aux;
}

void ifDirective(Token currentToken) {
    Token textReturn;
    if(currentToken.type == identifier) {
        if(getNextToken().type == newLine) {
            if(lookup(currentToken.value) != NULL){
                while((textReturn = getNextToken()).type != numeral)
                    printf("%s", textReturn.value);
            } else {
                Token aux = getNextToken();
                while(aux.type != numeral)
                    aux = getNextToken();
                goto readNumeral;
            }
            if(textReturn.type == numeral)
                readNumeral:
                if(getNextToken().type == endif)
                    return;
        }
    }
    fprintf(stderr, "\x1b[31m \nError sintáctico en la estructura IFDEF \x1b[0m \n");
    abort();  
}

void Directive(Token currentToken) {
    switch(currentToken.type) {

        case include: {
            Token nextToken = getNextToken(), aux;
            if(strcmp(nextToken.value, "\"") == 0) {
                if((aux = getNextToken()).type == identifier) {
                    if(strcmp((nextToken = getNextToken()).value, "\"") == 0) {
                        FILE *archivoInclude;
                        archivoInclude = fopen(aux.value, "r+");
                        if (archivoInclude == NULL){
                            printf("\x1b[31m");
                            printf("%s", aux.value);
                            printf(" no pudo ser abierto \x1b[0m \n");
                            exit(-1);
                        } else {
                            int c;
                            while((c = fgetc(archivoInclude)) != EOF){
                                putchar(c);
                            }
                            fclose(archivoInclude);
                            if((nextToken = getNextToken()).type == newLine)
                            printf("%s",  nextToken.value);
                                return;
                        }
                    }
                }
            }
            fprintf(stderr, "\x1b[31m \nError sintáctico en la estructura INCLUDE \x1b[0m \n");
            abort();                
        }

        case define: {
            Token nextToken = getNextToken();
            Token replaceValue;
            if(nextToken.type == identifier) {
                if((replaceValue = getNextToken()).type == replaceText) {
                    install(nextToken.value, replaceValue.value);
                    if((nextToken = getNextToken()).type == newLine)
                        return;
                }
            }
            fprintf(stderr, "\x1b[31m \nError sintáctico en la estructura DEFINE \x1b[0m \n");
            abort();  
        }

        case undef: {
            Token nextToken = getNextToken();
            if(nextToken.type == identifier) {
                rem(nextToken.value);
                if((nextToken = getNextToken()).type == newLine)
                    return;
            }
            fprintf(stderr, "\x1b[31m \nError sintáctico en la estructura UNDEF \x1b[0m \n");
            abort();  
        }

    }
}

void Base(Token currentToken) {
    switch(currentToken.type) {

        case rPar: {
                char* poppedValue = pop();
            if(strcmp(poppedValue, "(") != 0){
                fprintf(stderr, "\x1b[31m \nError de balanceo \x1b[0m \n");
                abort();
            }
            printf("%s", currentToken.value);
            return;
        } 
        case rBrace: {
                char* poppedValue = pop();
            if(strcmp(poppedValue, "{") != 0){
                fprintf(stderr, "\x1b[31m \nError de balanceo \x1b[0m \n");
                abort();
            }
            printf("%s", currentToken.value);
            return;
        }
        case rBracket: {
                char* poppedValue = pop();
            if(strcmp(poppedValue, "[") != 0){
                fprintf(stderr, "\x1b[31m \nError de balanceo \x1b[0m \n");
                abort();
            }
            printf("%s", currentToken.value);
            return;
        }

        case lBrace:
        case lBracket:
        case lPar: {
            printf("%s", currentToken.value);
            push(currentToken.value);
            Base(getNextToken());
            return;
        }   

        case numeral: {
            Token aux = getNextToken();
            if(aux.type == ifdef) {
                ifDirective(getNextToken());
                return;
            } else {
                Directive(aux);
                return;
            }
            fprintf(stderr, "\x1b[31m \nError sintáctico en la directiva. \x1b[0m \n");
            abort(); 
        }
        default: {
            Token tokenAux = Text(currentToken);
            Unit(tokenAux);
            return;
        }

    }
}

void Unit(Token currentToken) {
    if(currentToken.type != eof)
        Base(currentToken);
    else
        return;
}

void parser() {
    Token currentToken;
    while((currentToken = getNextToken()).type != eof) {
        Unit(currentToken);
    }
    return;
}
