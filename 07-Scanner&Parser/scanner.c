#include "scanner.h"
#include <string.h>
#include <stdlib.h>

static int directiveAux;
Token getNextToken(void) {
    int c = getchar();
    if(c == ' '){
        return getNextToken();
    }
    Token token;
    token.value = (char *) malloc(100);
    switch(c) {
        case '(': {
            token.type = lPar;
            strcpy(token.value, "(");
            return token;
            break;
        }
        case ')': {
            token.type = rPar;
            strcpy(token.value, ")");
            return token;
            break;
        }
        case '{': {
            token.type = lBrace;
            strcpy(token.value, "{");
            return token;
            break;
        }
        case '}': {
            token.type = rBrace;
            strcpy(token.value, "}");
            return token;
            break;
        }
        case '[': {
            token.type = lBracket;
            strcpy(token.value,"[");
            return token;
            break;
        }
        case ']': {
            token.type = rBracket;
            strcpy(token.value, "]");
            return token;
            break;
        }
        case '#': {
            token.type = numeral;
            strcpy(token.value, " ");
            return token;
            break;
        }
        case '\n': {
            token.type = newLine;
            strcpy(token.value, "\n");
            return token;
            break;
        }
        case '=':
        case ',':
        case ';':
        case ':':
        case '"':
        case '\'':
        case '<':
        case '>':
        case '+':
        case '-': {
            token.type = punctuator;
            char str[2] = {0};
            str[0] = c;
            strcpy(token.value, str);
            return token;
            break;
        }
        case '/': {
            if ((c = getchar()) == '/') { 
                char current;
                while( ( current = getchar() ) != EOF) {
                    if( current == '\n') {
                        token.type = comment;
                        strcpy(token.value, " ");                        
                        putchar(current);
                        return token; 
                    }
                }       
            }
            else if(c == '*') {
                char current, currentAux;
                while((current = getchar() ) != EOF) {
                    if(current == '*') {
                        currentAux = getchar();
                        if(currentAux == '/') {
                            token.type = comment;
                            strcpy(token.value, " ");
                            return token;
                        }
                    }
                }
            }
            else {
                ungetc(c, stdin);
                token.type = punctuator;
                strcpy(token.value, "/");
            }
            return token;
            break;
        }
        case 'd': {
            char str[20] = {0};
            str[0] = c;
            c = getchar();
            for(int i = 1;c != ' ' && c != '\n' && c != '(' && c != ')' && c!= '[' && c!= ']' && c!= '{' && c!= '}' && c!= '/' && c!= '\'' && c!= '"' && c!= ';' && c!= ':' && c!= '+' && c!= '-' && c!= '*' && c!= '<' && c!= '>'; i++) {
                str[i] = c;
                c = getchar();
            }
            ungetc(c, stdin);
            if(strcmp(str, "define") == 0) {
                token.type = define;
                extern int directiveAux;
                directiveAux = 1;
            } else {
                token.type = identifier;
                strcpy(token.value, str);
            }
            return token;
            break;
        }
        case 'u': {
            char str[20] = {0};
            str[0] = c;
            c = getchar();
            for(int i = 1;c != ' ' && c != '\n' && c != '(' && c != ')' && c!= '[' && c!= ']' && c!= '{' && c!= '}' && c!= '/' && c!= '\'' && c!= '"' && c!= ';' && c!= ':' && c!= '+' && c!= '-' && c!= '*' && c!= '<' && c!= '>'; i++) {
                str[i] = c;
                c = getchar();
            }
            ungetc(c, stdin);
            if(strcmp(str, "undef") == 0) {
                token.type = undef;
            } else {
                token.type = identifier;
                strcpy(token.value, str);
            }
            return token;
            break;
        }
        case 'i': {
            char str[20] = {0};
            str[0] = c;
            c = getchar();
            for(int i = 1;c != ' ' && c != '\n' && c != '(' && c != ')' && c!= '[' && c!= ']' && c!= '{' && c!= '}' && c!= '/' && c!= '\'' && c!= '"' && c!= ';' && c!= ':' && c!= '+' && c!= '-' && c!= '*' && c!= '<' && c!= '>'; i++) {
                str[i] = c;
                c = getchar();
            }
            ungetc(c, stdin);
            if(strcmp(str, "include") == 0) {
                token.type = include;
            }
            else if(strcmp(str, "ifdef") == 0) {
                token.type = ifdef;
            } 
            else {
                token.type = identifier;
                strcpy(token.value, str);
            }
            return token;
            break;
        }
        case 'e': {
            char str[20] = {0};
            str[0] = c;
            c = getchar();
            for(int i = 1; c != ' ' && c != '\n' && c != '(' && c != ')' && c!= '[' && c!= ']' && c!= '{' && c!= '}' && c!= '/' && c!= '\'' && c!= '"' && c!= ';' && c!= ':' && c!= '+' && c!= '-' && c!= '*' && c!= '<' && c!= '>'; i++) {
                str[i] = c;
                c = getchar();
            }
            ungetc(c, stdin);
            if(strcmp(str, "endif") == 0) {
                token.type = endif;
            }
            else {
                token.type = identifier;
                strcpy(token.value, str);
            }
            return token;
            break;
        }
        case EOF: {
            token.type = eof;
            char str[2] = {0};
            str[0] = c;
            strcpy(token.value, str);
            return token;
            break;
        }
        default: {
            char str[20] = {0};
            str[0] = c;
            c = getchar();
            for(int i = 1; c != ' ' && c != '\n' && c != '(' && c != ')' && c!= '[' && c!= ']' && c!= '{' && c!= '}' && c!= '/' && c!= '\'' && c!= '"' && c!= ';' && c!= ':' && c!= '+' && c!= '-' && c!= '*' && c!= '<' && c!= '>'; i++) {
                str[i] = c;
                c = getchar();
            }
            ungetc(c, stdin);
            extern int directiveAux;
            if (directiveAux == 2) {
                token.type = replaceText;
                directiveAux = 0;
            }
            else
                token.type = identifier;
            if (directiveAux == 1) directiveAux = 2;
            strcpy(token.value, str);
            return token;
        }
    }
}